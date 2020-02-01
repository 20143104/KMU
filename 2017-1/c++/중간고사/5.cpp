/******************************************************************************
*problem : 끝자리 숫자 계산하기                                      *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/


#include <iostream>
#include <fstream>
#include <cstdlib>
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
       instream >> numdata;
       int value=1;
       for(int j=0; j<numdata; j++)
       {
         int data, temp;
         instream >>data;
         temp=data%10;
         value *=temp;
         value %=10;
       }
       cout<<value<<endl;
    }
    return 0;
    instream.close();
    }
