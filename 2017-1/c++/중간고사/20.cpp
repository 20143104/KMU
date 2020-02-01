/******************************************************************************
*problem : 집합연산                                                *
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
    int numdata;
    int data;
    int sum=0;
    int *array_a = new int[131];
    int *array_b = new int[131];
    int *array_c = new int[131];

    instream>>numdata;

    for(int k=0; k<numdata; k++)
    {
      instream>>data;
      array_a[data]=1;
    }

    instream>>numdata;

    for(int k=0; k<numdata; k++)
    {
      instream>>data;
      array_b[data]=1;
    }
/////////////////////////////교집합///////////////
    for(int k=0; k<132; k++)
    {
      if(array_a[k]&array_b[k])
        {sum++; }
    }
    cout<<sum<<" ";
    for(int k=0; k<132; k++)
    {
      if(array_a[k]&array_b[k]) {cout<<k<<" ";}
    }
    cout<<endl;
///////////////////////////////합집합///////////////////////
    sum=0;
    for(int k=0; k<132; k++)
    {
      if(array_a[k]|array_b[k])
       {sum++;}
    }
    cout<<sum<<" ";
    for(int k=0; k<132; k++)
    {
      if(array_a[k]|array_b[k]) {cout<<k<<" ";}
    }
    cout<<endl;
  //////////////////////////////////차집합
    sum=0;
    for(int k=0; k<132; k++)
    {
      if(array_a[k]-array_b[k]>0) {array_c[k]=1; sum++;}
    }
    cout<<sum<<" ";
    for(int k=0; k<132; k++)
    {
      if(array_c[k]== 1){cout<<k<<" ";}
    }
    cout<<endl;
}
return 0;
instream.close();
}
