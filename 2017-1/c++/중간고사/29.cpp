/******************************************************************************
*problem : 실수표현                                        *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/
 #include<iostream>
 #include<fstream>
 #include<string>
 using namespace std;
 int getresult(string array,int size);
 int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail()){
    cerr<<"input file opening failed.\n";
  }
  int numtestcases;
  instream>>numtestcases;
  while(numtestcases--){
    string data;
    instream>>data;
    int len;
    len=data.length();
    cout<<getresult(data,len)<<endl;
  }
 }
int getresult(string array,int size){
  int check;
  int dig,flo,jum,e,op,ex,abnormal,noex;
  dig=flo=jum=e=op=ex=abnormal=noex=0;//정수부숫자 소수부숫자 점개수 e개수 plus개수  minus개수 지수부숫자
  for(int i=0; i<size; i++){
  if(array[i]!='.' && array[i]!='e' && array[i]!='E' && array[i]!= '+' && array[i]!='-' && (array[i]<'0' || array[i]>'9'))
  { return 0;}   ///지정되지않은 문자오면 0반환
  if(array[i]=='.')
    {jum++;}
  if(array[i]=='e' || array[i]=='E')
    {e++; check=i;}
  if(jum==0 && e==0){
    if('0'<=array[i] && array[i]<='9')
      {dig++;}
  }
  else if(e==0){
    if('0'<=array[i] && array[i]<='9')
      {flo++;}
    }
  }

  if(jum>1 || e>1)   //. e 2개이상 나오면
    {return 0;}

  if(e==1) //er가있을 때
    {
      if(array[check+1]=='\0') //e뒤에 아무것도 없을때
        {return 0;}
      for(int i=check+1; i<size; i++){
        if(array[i]!='+' && array[i]!='-'&&(array[i]<'0' || array[i]>'9'))   // +- 이외의 기호 나올때
          {return 0;}
        else if((array[i]=='+' || array[i]=='-') && ex==0)
          {op++;}
        else if((array[i]=='+' || array[i]=='-') && ex!=0)//숫자뒤에 부호가 나올때
          {return 0;}
        else if('0'<=array[i] && array[i]<='9')
          {ex++;}
      }
    }

  if(op>1)  ////부호 2개이상
    {return 0;}
  if(dig==0 && flo==0) //정수부 소수부
    {return 0;}
  if(jum==0 && e==0) //소수점 지수부
    {return 0;}
  if(e!=0 && ex==0) //e는 있는대 숫자가 없을때
    {return 0;}

  return 1;
}
