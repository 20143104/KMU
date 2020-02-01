/******************************************************************************
*problem : 삼각형의 종류-2                                              *
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
      double a_x,a_y,b_x,b_y,c_x,c_y;
      instream>>a_x>>a_y>>b_x>>b_y>>c_x>>c_y;
      double l1,l2,l3;
      l1=(b_x-a_x)*(b_x-a_x)+(b_y-a_y)*(b_y-a_y);
      l2=(b_x-c_x)*(b_x-c_x)+(b_y-c_y)*(b_y-c_y);
      l3=(c_x-a_x)*(c_x-a_x)+(c_y-a_y)*(c_y-a_y);
      double temp;
      for(int j=0; j<2; j++)
      {
        if(l1>l2)
        {
          temp=l2;
          l2=l1;
          l1=temp;
        }
        if(l2>l3)
        {
          temp=l3;
          l3=l2;
          l2=temp;
        }
      }
    if(sqrt(l3)>=sqrt(l1)+sqrt(l2))
     cout<<0<<endl;
    else if(l3==l1+l2)
     cout<<1<<endl;
    else if(l3>l1+l2)
     cout<<2<<endl;
    else if(l3<l1+l2)
     cout<<3<<endl;
    }
    return 0;
    instream.close();
}
