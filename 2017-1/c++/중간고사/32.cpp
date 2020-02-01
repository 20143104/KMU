/******************************************************************************
*problem : 체크썸                                        *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/
 #include<iostream>
 #include<fstream>

 using namespace std;
 int ischecksum(unsigned long data);
 int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail()){
    cerr<<"input file opening failed.\n";
  }
  int numtestcases;
  instream>>numtestcases;
  while(numtestcases--){
    unsigned long n;
    instream >>n;
    cout<<ischecksum(n)<<endl;
    }
    return 0;
    instream.close();
}
int ischecksum(unsigned long data){
  unsigned long base = 0x00ff;
  unsigned long a,b,c,d;
  a=(base<<24) & data;
  b=(base<<16) & data;
  c=(base<<8) & data;
  a>>=24;
  b>>=16;
  c>>=8;
  unsigned long sum;
  sum = a+b+c;

  while(sum>256)
    {sum-=256;}
  sum=255-sum;
  d=data&base;
  if(sum==d)
    return 1;
  else
    return 0;
}
