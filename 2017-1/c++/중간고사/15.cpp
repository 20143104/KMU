/******************************************************************************
*problem : 패리티비트                                                        *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

int main(void)
{
 ifstream instream;
 instream.open("input.txt");
 if(instream.fail())
 {
  cerr<<"input file opening failed.\n";
 }
 int numtestcases;

 instream>>numtestcases;
 for(int i=0; i<numtestcases; i++)
 {
  int *array=new int[31];
  unsigned result=0;
  int count=0;

  int data;
  instream>>data;

///////////////2진수로변환
  int k=0;
  if(data==1)
  array[0]=1;
  while(data>1)
  {
   array[k]=data%2;
   k++;
   data=data/2;
   if(data==1)
   array[k]=data;
  }

//////1의 숫자 개수
  for(int j=31; j>=0; j--)
  {
   if(array[j]==1)
   count++;
  }

  if(count%2==1)
  array[31]=1;
  //////10진수로 변환
  for(int j=31; j>=0; j--)
  {
   result +=array[j]*pow(2,j);
  }
  cout <<result<<endl;
}
return 0;
instream.close();
}
