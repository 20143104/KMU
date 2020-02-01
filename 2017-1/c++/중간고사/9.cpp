/******************************************************************************
*problem : 삼각형의 종류-1                                                       *
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
      int a,b,c;
      instream >>a>>b>>c;
      if((a+b)<=c)
       cout<<0<<endl;
      else{
        if(a==b && b==c)
        cout<<1<<endl;
        else{
          if((c*c)==(a*a)+(b*b))
          cout<<2<<endl;
          else{
            if(a==b || b==c)
            cout<<3<<endl;
            else
            cout<<4<<endl;
          }
        }
      }
    }

     return 0;
     instream.close();
}
