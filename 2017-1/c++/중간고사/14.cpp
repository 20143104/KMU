/******************************************************************************
*problem : 다각형면적                                             *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>

void getresult(int data,int array_x[],int array_y[]);

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
  int data;
  instream>>data;

  int *array_x=new int[data+1]; //배열 초기화
  int *array_y=new int[data+1];

  for(int j=0; j<data; j++){     //x,y값 받기
   instream >> array_x[j] >> array_y[j];
  }
  array_x[data]=array_x[0];  //p0=pn
  array_y[data]=array_y[0];

  getresult(data, array_x,array_y); //결과값 출력하는 함수
  delete [] array_x;
  delete [] array_y;
 }

  return 0;
  instream.close();
}
void getresult(int data,int array_x[],int array_y[])
{
    int S=0;

    for(int j=0; j<data; j++)
    {
     S+=((array_x[j]+array_x[j+1])*(array_y[j+1]-array_y[j]));
    }

    if(S<0)
     cout<<abs(S)<<" "<<-1<<endl;
    else if(S>0)
     cout<<S<<" "<<1<<endl;
    else
     cout<<0<<" "<<0<<endl;
}
