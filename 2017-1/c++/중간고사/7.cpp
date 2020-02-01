/******************************************************************************
*problem : 삼각형의 종류-2                                              *
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
     int data;
     instream>>data;

     for(int j=1; j<=data; j++)
     {
      int a=j;
       for(int k=1; k<=j; k++)
       {

         cout<<a<<" " ;
         a+=data-k;
       }
       cout<<endl;
     }

     }
     return 0;
     instream.close();
}
