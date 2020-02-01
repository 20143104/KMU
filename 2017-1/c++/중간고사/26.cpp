/******************************************************************************
*problem : 0이아닌마지막자리수구하기                                           *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/
 #include <iostream>
 #include <fstream>
 #include <cmath>

 using namespace std;

 int getmin(int a, int b);

 int main(){
  ifstream instream;
  instream.open("input.txt");

  if(instream.fail()){
    cerr<<"input file opening failed.\n";
  }

  int numtestcases;
  instream>>numtestcases;

  for(int i=0; i<numtestcases; i++){
    int numdata,data;
    instream >> numdata;
    int mult=1;
    int count_two=0;
    int count_five=0;
    int count;
    for(int k=0; k<numdata; k++){
      instream>>data;

      while(data%2==0){
        data/=2;
        count_two++;
      }
      while(data%5==0){
        data/=5;
        count_five++;
      }
      data%=10;
      mult*=data;
      mult%=10;
    }

    if(count_two>count_five){
      count=count_two-count_five;
      for(int k=0; k<count; k++){
        mult*=2;
        mult%=10;
      }
    }
    else if(count_two<count_five){
      count=count_five-count_two;
      for(int k=0; k<count; k++){
        mult*=5;
        mult%=10;
      }
    }

    cout<<mult<<" "<<getmin(count_two,count_five)<<endl;
  }
  instream.close();
  return 0;
 }
 int getmin(int a, int b){
   if(a>b)
    {return b;}
   else
    {return a;}
 }
