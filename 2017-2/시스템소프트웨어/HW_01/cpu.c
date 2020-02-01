/**
 * @file cpu.c
 * @author Daeyoung Heo
 * @author Suntae Hwang
 * @version 1.3.4
 * @since 1.0
 * @date 1998-2012

 * @copyright Copylight (c) 1998-2011 Daeyoung Heo and Suntae Hwang,
 * Kookmin University, All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cpu/cpu.h>
#include <cpu/interrupt.h>
#include <memory/memory.h>
#include <memory/roms/bios.h>
#include <mainboard/bus.h>
#include <builtin/cpubuiltin.h>

extern int verbose;
/*
 * Registers
 */
DBOX LMCreg[pMAX_REG]; /* LMC registers */

/*
 * DBOX type ALU
 */
DBOX
ALU(alu_t op, DBOX opr1, DBOX opr2)
{
  DBOX result;
  BOOL SIGN1, SIGN2;
  switch (op)
    {
    case ALU_SUB1:
      /* Subtract는 opr2를 invert 한 값에 1을 우선 더한다.*/
      opr2 = invertReg(opr2);
      opr2 = increaseReg(opr2,1);
      /* opr1과 opr2의 Invert + 1의 결과를  계속해서 더한다.*/
      /* @see 교재 제 7 장 Little Man Desing 참고*/
    case ALU_ADD1:
      SIGN1 = (opr1.low>=HALF_BOX)?TRUE:FALSE;
      SIGN2 = (opr2.low>=HALF_BOX)?TRUE:FALSE;
      result.low = opr1.low + opr2.low;

      SET_CPU_FLAG(AC, (result.low>=MAX_BOX)?TRUE:FALSE);
      result.low = result.low % MAX_BOX;

      SET_CPU_FLAG(Z, (result.low==0       )?TRUE:FALSE);
      SET_CPU_FLAG(S, (result.low>=HALF_BOX)?TRUE:FALSE);
      if( SIGN1 == SIGN2 &&
          GET_CPU_FLAG(S) != SIGN1)
        {
          SET_CPU_FLAG(O, TRUE);
        }
      else
        {
          SET_CPU_FLAG(O, FALSE);
        }
      break;
      /* @TODO 새로운 산술&로직 연산자 추가 */
    default:
      _RAISE(HW_EXCEPTION, UNKNOWN_ALU_OPERATOR);
    }
  return result;
}

/**
 * @see 교제 제 7 장 Little Man Design  참고
 */
DBOX
addReg(DBOX lop, DBOX rop)
{
  DBOX result;
  /*
   * 레지스터 가산기는 PSW를 수정하지 않는다.
   */

  result.low  = lop.low %MAX_BOX + rop.low %MAX_BOX;
  result.high = lop.high%MAX_BOX
    + rop.high%MAX_BOX
    + result.low/MAX_BOX;

  result.low = result.low % MAX_BOX;
  result.high = result.high % MAX_BOX;
  return result;
}

/**
 * @see 교제 제 7 장 Little Man Design  참고
 */
DBOX
increaseReg(DBOX reg, int i)
{
  DBOX value = reg;
  value.low = (value.low %MAX_BOX) + i;
  value.high= (value.high%MAX_BOX) + (value.low/MAX_BOX);

  if(value.low >= MAX_BOX)
    {
      /*
       * 레지스터 증산기는 PSW를 수정하지 않는다.
       * SET_CPU_FLAG( AC, TRUE );
       */
      value.low = value.low % MAX_BOX;
    }
  if(value.high >= MAX_BOX)
    {
      /*
       * 레지스터 증산기는 PSW를 수정하지 않는다.
       * SET_CPU_FLAG( CA, TRUE );
       */
      value.high = value.high % MAX_BOX;
    }
  return value;
}

/**
 * @see 교제 제 7 장 Little Man Design  참고
 */
DBOX
decreaseReg(DBOX reg, int i)
{
  /*
   * 레지스터 감산기는 PSW를 수정하지 않는다.
   * SET_CPU_FLAG( AC, TRUE );
   * SET_CPU_FLAG( CA, TRUE );
   */
  reg.low  = (reg.low%MAX_BOX ) + MAX_BOX; /* AC = 1*/
  reg.high = (reg.high%MAX_BOX) + MAX_BOX; /* CA = 1*/

  reg.low  = reg.low  - i;
  if(reg.low < MAX_BOX)
    {
      reg.high = reg.high - 1;
      SET_CPU_FLAG( AC, FALSE );
      /* 한번에 큰수를 뺄 경우에 대해서 처리*/
      /* 실제 기계에서는 일어나지 않는다.*/
      if(reg.low < 0)
        {
          reg.low = MAX_DBOX + reg.low;
          reg.high = reg.high
            - (MAX_BOX - reg.low/MAX_BOX); /* Carry*/
          reg.low = (reg.low%MAX_BOX);
        }
    }
  /*
   * 레지스터 감산기는 PSW를 수정하지 않는다.
   * if(reg.high < MAX_BOX)
   * {
   *  SET_CPU_FLAG( CA, FALSE );
   * }
   */
  reg.low  = reg.low  % MAX_BOX;
  reg.high = reg.high % MAX_BOX;
  return reg;
}

/**
 * @see 교제 제 7 장 Little Man Design  참고
 */
DBOX
invertReg(DBOX reg)
{
  reg.low  = (MAX_BOX-1) - (reg.low %MAX_BOX);
  reg.high = (MAX_BOX-1) - (reg.high%MAX_BOX);
  return reg;
}

/*
 * Instruction Decode
 */
ir_t
decode(DBOX ir)
{
  ir_t IR;

  LMCreg[pIR] = ir; /* for Debugger */

  /* IR 레지스터 Decode */
  IR.IR0 = ir.low % 10;
  IR.IR1 = (ir.low / 10) % 10;
  IR.IR2 = (ir.low / 100) % 10;
  IR.IR3 = (ir.low / 1000) % 10;
  IR.pc = (DBOX2INT(PC));
  IR.Oooo = (ir.low%10000);
  IR.Ooo_ = IR.Oooo/10;
  IR.Oo__ = IR.Oooo/100;
  IR.__R_ = IR.Ooo_%10;
  IR.___M = IR.Oooo%10;
  IR.___C = IR.Oooo%10;
  IR.___R = IR.Oooo%10;
  IR.__Aa = IR.Oooo%100;

  /*
   * Format 결정
   * @file cpubuiltin.h 에서 등록한 테이블에서 검색한다.
   * @see 교재 제 7 장 Little Man Design, 7.5절 참고.
   */
  if(IR.Oo__ >= 0 &&
     IR.Oo__ < 98 &&
     IS_REGISTERED_OP(IR.Oo__))
    {
      IR.format = __FORMAT(IR.Oo__);
    }
  else if(IR.Ooo_ < 998 &&
          IS_REGISTERED_OP(IR.Ooo_))
    {
      IR.format = __FORMAT(IR.Ooo_);
    }
  else if(IS_REGISTERED_OP(IR.Oooo))
    {
      IR.format = __FORMAT(IR.Oooo);
    }
  else
    {
      IR.format = F_INVALID;
    }

  /*
   * 찾은 Format을 바탕으로 Opcode를 결정한다.
   */
  switch(IR.format)
    {
    case F_OOAA:
    case F_OORR:
      IR.opcode = IR.Oo__;
      break;
    case F_OOOR:
      IR.opcode = IR.Ooo_;
      break;
    case F_OORMFA:
    case F_OORMD:
      IR.opcode = IR.Oo__;
      IR.addrmode = IR.___M;
      break;
    case F_OOOO:
      IR.opcode = IR.Oooo;
      break;
    }
  return IR;
}

/**
 * @brief 내장 Opr0 주소 계산기
 *
 * F_OOAA, F_OOOR 의 Operand와 F_OORR, F_OORMFA, F_OORMD 포맷의 왼쪽
 * Operand의 주소를 계산한다.
 */
static DBOX
getOpr0TargetAddress(ir_t IR)
{
  DBOX target;
  switch (IR.format)
    {
    case F_OOAA:
      target = INT2DBOX( IR.__Aa );
      break;
    case F_OOOR:
      if (IR.___R < 6)
        {
          _RAISE(HW_EXCEPTION, ADDRESS_RESOLVE_ERROR);
        }
      else /* Indirect Mode */
        {
          MAR = LMCreg[IR.___R];
          activateMemory(READ, 2);
          target = MDR;
        }
      break;
    case F_OORR:
    case F_OORMFA:
    case F_OORMD:
      /* @TODO Implement addressing mode */

      /**********************************/
      break;
    default:
      // OOOO 는 해당사항 없음.
      _RAISE(HW_EXCEPTION, ADDRESS_RESOLVE_ERROR);
      break;
    }
  return target;
}

/**
 * @deprecated getOpr1TargetAddress로 변경되었다.
 */
#define getTargetAddress(_IR_)\
  getOpr1TargetAddress(_IR_)

/**
 * @brief 내장 Opr1 주소 계산기
 *
 * F_OORR, F_OORMFA, F_OORMD 포맷의 오른쪽 Operand의 주소를 계산한다.
 * F_OOOR과 F_OOAA는 getOpr0TargetAddress()를 호출하여 해결한다.
 */
static DBOX
getOpr1TargetAddress(ir_t IR)
{
  DBOX target;
  switch (IR.format)
    {
    case F_OOAA:
    case F_OOOR:
      return getOpr0TargetAddress(IR);
    case F_OOOO:
      // OOOO 는 해당사항 없음.
      _RAISE(HW_EXCEPTION, ADDRESS_RESOLVE_ERROR);
      break;
    case F_OORR:
      /* @TODO Implement addressing mode */

      /**********************************/
      break;
    case F_OORMFA:
      /* @TODO Implement addressing mode */

      /**********************************/
      break;
    case F_OORMD:
      /* @TODO Implement addressing mode */

      /**********************************/
      break;
    default:
      _RAISE(HW_EXCEPTION, UNKNOWN_FORMAT);
    }
  return target;
}

/**
 * @brief SKIP, JUMP 조건 검사기
 * @ingroup CONDITION
 */
static BOOL
satisfyCondition(int cond)
{
  switch (cond)
    {
    case Zero:
      return (GET_CPU_FLAG(Z));
    case ZeroPositive:
      return (GET_CPU_FLAG(Z) || !GET_CPU_FLAG(S));
    case Negative:
      return (GET_CPU_FLAG(S));
      /* @TODO insert new conditions here */

      /***********************************/
    default:
      _RAISE(HW_EXCEPTION, UNKNOWN_CONDITION);
    }
  return TRUE;
}

/**
 * @brief Little Man Click Hand Counter
 * @ingroup CPU
 *
 * 포맷별로 PC 핸드 카운터를 증가시킨다.
 */
static void
clickHandCounter(ir_t IR)
{
  switch (IR.format)
    { /* PC = Next PC */
    case F_OORMFA:
      PC = increaseReg(PC, 3);
      break;
    case F_OORMD:
      PC = increaseReg(PC, 2);
      break;
    default:
      PC = increaseReg(PC, 1);
    }
}

/**
 * @section CPU 인터럽트 처리기
 * @code
 * {IF of PSW} = 1 // 인터럽트 끄기
 * {P of PSW}  = 0 // 인터럽트 요청 청소
 * M[(M[SS]-2] = SP
 * M[(M[SS]-4] = PC
 * M[(M[SS]-6] = PSW
 * PC = EH_ENTRY // 시스템 벡터(@link EH_ENTRY)값으로 점프
 * @endcode
 */
static void
InterruptHandling()
{
  /* Disable Interrupt */
  SET_CPU_FLAG(IF, TRUE);
  /* Clean Interrupt Pending */
  SET_CPU_FLAG(P,FALSE);

  /* Interrupt ********************************/
  /* M[(M[SS])-2] := SP */
  MAR = INT2DBOX( SS );
  activateMemory(READ, 2);
  MAR = decreaseReg(MDR, 2);
  MDR = SP;
  activateMemory(WRITE, 2);

  /* M[(M[SS])-4] := PC */
  MAR = INT2DBOX( SS );
  activateMemory(READ, 2);
  MAR = decreaseReg(MDR, 4);
  MDR = PSW;
  activateMemory(WRITE, 2);

  /* M[(M[SS])-6] := PSW */
  MAR = INT2DBOX( SS );
  activateMemory(READ, 2);
  MAR = decreaseReg(MDR, 6);
  MDR = PC;
  activateMemory(WRITE, 2);

  /* SP = (M[SS])-6 */
  MAR = INT2DBOX( SS );
  activateMemory(READ, 2);
  SP = decreaseReg(MDR, 6);

  MAR = INT2DBOX( EH_ENTRY ); /* PC = EH_ENTRY */
  activateMemory(READ, 2);
  PC = MDR;
  /********************************************/
}

/**
 * @brief Little Man Execution Cycle
 * @ingroup CPU
 * @return #lmc_status_t @n LMC Machine Status @n
 *    NORMAL, JUMP(BRANCH) or SHUTDOWN
 */
lmc_status_t
LittleMan(void)
{
  lmc_trace(TRACE_LMC,TRACE_START);
  BOOL check;
  ir_t IR;
  lmc_status_t status = STATUS_NORMAL;

  /* Interrupt Handle */
  if (!GET_CPU_FLAG(IF) && GET_CPU_FLAG(P))
    {
      InterruptHandling();
      SET_CPU_FLAG(P, FALSE);
    }

  /* Check Built-in Service Call */
  switch (CHECK_BUILTIN_SECTION())
    {
    case MEMORY_SECTION:
      BOUND_CHECK( DBOX2INT(PC) );
      if( !GET_CPU_FLAG(IF) && GET_CPU_FLAG(P) )
        {
          lmc_trace(TRACE_LMC,TRACE_EXIT);
          return status;
        }
      break;
    default:
      check = execute_magiccode();
      lmc_trace(TRACE_LMC,TRACE_EXIT);
      return check ? STATUS_SHUTDOWN : STATUS_JUMP;
    }


  /* Fetch and Decode */
  MAR = PC;
  activateMemory(READ, 1);
  IR = decode(MDR);

  if(isBuiltInCpuMode()) {
    status = builtinExecution(IR,
                              FIND_BUILTINOP( IR.opcode ));
  } else {
    if( (verbose&0x2) )
      {
        int op = IR.opcode;
        int pc = IR.pc;
        if( pc < RAM_SIZE || TRUE )
          {
            //fgets(tmp,100,stdin);
            lmcprintf(CONSOLE, "Fetch    >  PC: %8d,  IR: %4d(%s), FMT: %d\n",
                      pc, DBOX2INT(LMCreg[pIR]), MNEMONIC(op), IR.format);
          }
      }
    /* Execution */
    switch (IR.opcode)
      {
        /*
         * @instruction NOP
         * @opcode 0 OOAA
         */
      case 0:
        break;
        /*
         * @instruction LDA
         * @opcode 1 OOAA
         */
      case 1:
        switch( IR.format )
          {
          case F_OOAA:
            /*
             * @fixme 다음과 같이 사용하는 것을 권장한다.
             * @code
             * MAR = getOpr0TargetAddress(IR)
             * @endcode
             */
            MAR = INT2DBOX(IR.__Aa);
            activateMemory(READ, 1);
            A.low = MDR.low;
            break;
          default:
            _RAISE(HW_EXCEPTION, INVALID_FORMAT);
          }
        break;
        /*
         * @instruction ADDA
         * @opcode 3 OOAA
         */

      case 2:
        switch( IR.format )
        {
          case F_OOAA:
            MAR = INT2DBOX(IR.__Aa);
            MDR.low = A.low;
            activateMemory(WRITE, 1);
            break;
          default:
            _RAISE(HW_EXCEPTION, INVALID_FORMAT);
        }
        break;

      case 4:
        switch( IR.format)
        {
          case F_OOAA:
            MAR = INT2DBOX(IR.__Aa);
            activateMemory(READ, 1);

            A = ALU(ALU_SUB1,A,MDR);
            break;
          default:
           _RAISE(HW_EXCEPTION, INVALID_FORMAT);
        }
        break;

      case 9:
        switch(IR.format)
        {
          case F_OOAA:
            status = STATUS_JUMP;
            PC = INT2DBOX(IR.__Aa);
            break;
        }
        break;

      case 3:
        switch( IR.format )
          {
          case F_OOAA:
            MAR = INT2DBOX(IR.__Aa);
            activateMemory(READ, 1);
            /*
             * @fixme ALU는 ALU_ADD1과 ALU_SUB1만 구현되어있다.
             * 다른 연산은 ALU 함수에서 구현해야만 한다.
             */
            A = ALU(ALU_ADD1,A,MDR);
            break;
          default:
            _RAISE(HW_EXCEPTION, INVALID_FORMAT);
          }
        break;
        /*
         * @instruction IN
         * @opcode 5 OOAA
         */
      case 5:
        switch( IR.format )
          {
          case F_OOAA:
            A = InputPort(IR.__Aa, ONE_BOX);
            break;
          default:
            _RAISE(HW_EXCEPTION, INVALID_FORMAT);
          }
        break;
        /*
         * @instruction OUT
         * @opcode 6 OOAA
         */
      case 6:
        switch( IR.format )
          {
          case F_OOAA:
            OutputPort(A, IR.__Aa, ONE_BOX);
            break;
          default:
            _RAISE(HW_EXCEPTION, INVALID_FORMAT);
          }
        break;
        /*
         * @instruction OUT
         * @opcode 6 OOAA
         */
      case 8:
        switch(IR.format)
          {
          case F_OOAA:
            /*
             * 명령어에서 PC 카운터를 직접 변경할 경우
             * 위 문장을 기술한다.
             */
            status = STATUS_JUMP;
            if( satisfyCondition(IR.___C))
              {
                PC = increaseReg(PC,2);
              }
            else
              {
                PC = increaseReg(PC,1);
              }
            break;
          default:
            _RAISE(HW_EXCEPTION, INVALID_FORMAT);
          }
        break;
        /* @TODO insert your instructions here */
        /* eg) case Push: ... break; */

        /**************************************/
      default: {
        if(IS_REGISTERED_OP(IR.opcode))
          {
            status = builtinExecution(IR,
                                      FIND_BUILTINOP( IR.opcode ));
          }
        else
          {
            _RAISE(HW_EXCEPTION, INVALID_INSTRUCTION);
          }
      }
      }
    /** VERBOSE **/
    if ( (verbose&0x2) ) {
      int op = IR.opcode;
      int pc = IR.pc;
      char tmp[100];
      int reg = 0;
      //fgets(tmp,100,stdin);
      lmcprintf(CONSOLE, "Register > \n");
      int regCount = 0;
      for(;reg<pMAX_REG;reg++)
        {
          if(IS_REGISTER(reg) && REGISTER(reg)[0] != '*')
            {
              lmcprintf(CONSOLE, "%8s: %08d,",
                        REGISTER(reg),
                        DBOX2INT(LMCreg[reg]));
              if( regCount%3==2 )
                lmcprintf(CONSOLE,"\n");
              else lmcprintf(CONSOLE,"\t");
              regCount++;
            }
        }
      lmcprintf(CONSOLE,"\n");
      console_refresh();
    }
  }

  if( status == STATUS_NORMAL )
    {
      clickHandCounter(IR);
    }
#ifdef _DEBUG
    {
      int pc = DBOX2INT(PC);
      lmcprintf(CONSOLE, "Next     >  PC: %8d\n", pc);
    }
#endif

  lmc_trace(TRACE_LMC,TRACE_EXIT);
  tick();
  return status;
}
/*
 * Local Variables:
 *  mode:c
 *  c-file-style:"gnu"
 *  indent-tabs-mode:nil
 * End:
 * vim:ai:si:cin:ft=c.doxygen:expandtab:sw=2:sts=2:ts=8:bg=dark:syntax=c.doxygen:bs=eol,start,indent:sm
 * vim:cino=>2s,e-1s,n-1s,f0,{1s,}0,^-1s,\:1s,=1s,l1,b0,g1s,h1s,p1s,t0,i1s,+1s,c3,C0,/0,(0,u0,U1,w0,W1s,m1,M0,)20,*30,#0
 */
