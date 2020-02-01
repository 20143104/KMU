/******************************************************************************
*problem : 약수의합구하기                                             *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *          d                                                20143104 조승현   *
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
      int data,data1;
      instream>>data;
      data1=sqrt(data);
      int sum=1;
      int num=1;
      for(int j=2; j<=data1; j++)
      {
        if(data%j==0 && data/j==j){
          sum+=j; num+=1;
        }
        else{
        if(data%j==0)
         {sum = sum+j+data/j; num+=2;}
      }}
      cout << num<<" "<<sum<<endl;
    }
    return 0;
    instream.close();
}
