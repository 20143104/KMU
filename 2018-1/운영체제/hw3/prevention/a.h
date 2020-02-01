#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SEMPERM 0600
#define TRUE 1
#define FALSE 0

typedef union   _semun {
             int val;
             struct semid_ds *buf;
             ushort *array;
             } semun;

int initsem (key_t semkey, int n) {
   int status = 0, semid;
   if ((semid = semget (semkey, 1, SEMPERM | IPC_CREAT | IPC_EXCL)) == -1)
   {
       if (errno == EEXIST)
                semid = semget (semkey, 1, 0);
   }
   else
   {
       semun arg;
       arg.val = n;
       status = semctl(semid, 0, SETVAL, arg);
   }
   if (semid == -1 || status == -1)
   {
       perror("initsem failed");
       return (-1);
   }
   return (semid);
}

int p (int semid) {
   struct sembuf p_buf;
   p_buf.sem_num = 0;
   p_buf.sem_op = -1;
   p_buf.sem_flg = SEM_UNDO;
   if (semop(semid, &p_buf, 1) == -1)
   {
      printf("p(semid) failed");
      exit(1);
   }
   return (0);
}

int v (int semid) {
   struct sembuf v_buf;
   v_buf.sem_num = 0;
   v_buf.sem_op = 1;
   v_buf.sem_flg = SEM_UNDO;
   if (semop(semid, &v_buf, 1) == -1)
   {
      printf("v(semid) failed");
      exit(1);
   }
   return (0);
}

// Shared variable by file
void reset(char *fileVar) {
// fileVar라는 이름의 텍스트 화일을 새로 만들고 0값을 기록한다.
  FILE *f = fopen(fileVar, "r");
  if(f==NULL){
      f = fopen(fileVar , "w");
      fprintf(f, "%d\n", 0);
  }
  fclose(f);
}
void reset_resc(char *fileVar) {
// fileVar라는 이름의 텍스트 화일을 새로 만들고 1값을 기록한다.
  FILE *f = fopen(fileVar, "r");
  if(f==NULL){
      f = fopen(fileVar , "w");
      fprintf(f, "%d\n", 1);
  }
  fclose(f);
}
void Store(char *fileVar,int i) {
// fileVar 화일 끝에 i 값을 append한다.
  FILE *f = fopen(fileVar, "a");
  fprintf(f, "%d\n", i);
  fclose(f);
}

int Load(char *fileVar) {
// fileVar 화일의 마지막 값을 읽어 온다.
  int data;
  FILE *f = fopen(fileVar, "r");
  while(!feof(f))
    fscanf(f, "%d", &data);
  fclose(f);

  return data;
}

void add(char *fileVar,int i) {
// fileVar 화일의 마지막 값을 읽어서 i를 더한 후에 이를 끝에 append 한다.
  int data;
  pid_t pid = getpid();
  FILE *f = fopen(fileVar, "a+");
  while(!feof(f))
    fscanf(f, "%d", &data);
  fprintf(f, "%d\n", (i+data));
  fclose(f);
}

void sub(char *fileVar,int i) {
  pid_t pid = getpid();
  int data;
  FILE *f = fopen(fileVar, "a+");
  while(!feof(f))
    fscanf(f, "%d", &data);
  fprintf(f, "%d\n", (data-i));
  fclose(f);
// fileVar 화일의 마지막 값을 읽어서 i를 뺀 후에 이를 끝에 append 한다.
}

// Class Lock
typedef struct _lock {
   int semid;
} Lock;

void initLock(Lock *l, key_t semkey) {
   if ((l->semid = initsem(semkey,1)) < 0)
   // 세마포를 연결한다.(없으면 초기값을 1로 주면서 새로 만들어서 연결한다.)
      exit(1);
}

void Acquire(Lock *l) {
   p(l->semid);
}

void Release(Lock *l) {
   v(l->semid);
}

// Class CondVar
typedef struct _cond {
   int semid;
   char *queueLength;
} CondVar;

void initCondVar(CondVar *c, key_t semkey, char *queueLength) {
   c->queueLength = queueLength;
   reset(c->queueLength); // queueLength=0
   if ((c->semid = initsem(semkey,0)) < 0)
   // 세마포를 연결한다.(없으면 초기값을 0로 주면서 새로 만들어서 연결한다.)
      exit(1);
}

void Wait(CondVar *c, Lock *lock) {
  add(c->queueLength, 1);
  Release(lock);
  p(c->semid);
  Acquire(lock);
}

void Signal(CondVar *c) {
  if(Load(c->queueLength) >0){
    v(c->semid);
    sub(c->queueLength, 1);
  }
}

void Broadcast(CondVar *c) {
  while(Load(c->queueLength) > 0){
    v(c->semid);
    sub(c->queueLength,1);
  }
}


Lock lock1, lock2, lock3;
CondVar c1, c2, c3;

void take_r1(){
  pid_t pid;
  pid = getpid();

  Acquire(&lock1);

  while(Load("r1")==0){
    printf("%d 가 R1을 기다림\n", pid);
    Wait(&c1, &lock1);
    printf("%d 가 R1을 기다리다가 깨어남\n", pid);
  }
  Store("r1", 0);
  printf("%d가 R1을 가져옴\n", pid);
  Release(&lock1);
}
void take_r2(){
  pid_t pid;
  pid = getpid();

  Acquire(&lock2);

  while(Load("r2")==0){
    printf("%d 가 R2을 기다림\n", pid);
    Wait(&c2, &lock2);
    printf("%d 가 R2을 기다리다가 깨어남\n", pid);
  }
  Store("r2",0);
  printf("%d가 R2을 가져옴\n", pid);
  Release(&lock2);
}
void take_r3(){
  pid_t pid;
  pid = getpid();

  Acquire(&lock3);

  while(Load("r3")==0){
    printf("%d 가 R3을 기다림\n", pid);
    Wait(&c3, &lock3);
    printf("%d 가 R3을 기다리다가 깨어남\n", pid);
  }
  Store("r3",0);
  printf("%d가 R3을 가져옴\n", pid);
  Release(&lock3);
}
void put_r1(){
  pid_t pid;
  pid = getpid();

  Acquire(&lock1);
  Store("r1", 1);
  Signal(&c1);
  printf("%d 가 R1을 놓음\n", pid);
  Release(&lock1);
}
void put_r2(){
  pid_t pid;
  pid = getpid();

  Acquire(&lock2);
  Store("r2", 1);
  Signal(&c2);
  printf("%d 가 R2을 놓음\n", pid);
  Release(&lock2);
}
void put_r3(){
  pid_t pid;
  pid = getpid();

  Acquire(&lock3);
  Store("r3", 1);
  Signal(&c3);
  printf("%d 가 R3을 놓음\n", pid);
  Release(&lock3);
}
void phil_a(){
  pid_t pid;
  pid = getpid();
  take_r1();
  printf("%d가 생각을 시작함\n", pid);
  sleep(1);
  printf("%d가 생각을 멈춤\n", pid);
  take_r2();
  printf("%d가 먹기 시작\n", pid);
  sleep(1);
  printf("%d가 먹기를 멈춤\n", pid);
  put_r1();
  put_r2();
}
void phil_b(){
  pid_t pid;
  pid = getpid();
  take_r2();
  printf("%d가 생각을 시작함\n", pid);
  sleep(1);
  printf("%d가 생각을 멈춤\n", pid);
  take_r3();
  printf("%d가 먹기 시작함\n", pid);
  sleep(1);
  printf("%d가 먹기를 멈춤\n", pid);
  put_r2();
  put_r3();
}
void phil_c(){ // C가 1번을 잡은 후 3번을 잡게 구현했다.
  pid_t pid;
  pid = getpid();
  take_r1();
  printf("%d가 생각을 시작함\n", pid);
  sleep(1);
  printf("%d가 생각을 멈춤\n", pid);
  take_r3();
  printf("%d가 먹기 시작함\n", pid);
  sleep(1);
  printf("%d가 먹기를 멈춤\n", pid);
  put_r1();
  put_r3();
}
