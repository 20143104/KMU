/******************************************************************************
*problem : ipv4주소변환                                       *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/


#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
    cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;
  while(numtestcases--){
    int n;
    instream>>n;
    unsigned int data1,data2,data3,data4;
    if(n==1){
      char jum;
      unsigned int sum=0;
      instream>>data1>>jum>>data2>>jum>>data3>>jum>>data4;
      data1<<=24;
      data2<<=16;
      data3<<=8;
      sum+=data1+data2+data3+data4;
      cout<<sum<<endl;
    }
    else{
      unsigned int data;
      instream >>data;
      unsigned int mask = 0Xff;
      data1=(mask)&(data>>24);
      data2=(mask)&(data>>16);
      data3=(mask)&(data>>8);
      data4=(mask)&data;
      cout<<data1<<'.'<<data2<<'.'<<data3<<'.'<<data4<<endl;
    }
  }
}
