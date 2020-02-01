/******************************************************************************
*problem : 사각형과 점과의 거리                                            *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *          d                                                20143104 조승현   *
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
    int x1,y1,x2,y2,x3,y3;
    instream>>x1>>y1>>x2>>y2>>x3>>y3;
    int l1,l2;
    if(x3>=x1 && x3<=x2 && y3>y2)
    {
      l2=y3-y2;
      l1=l2*l2;
    }
    else if(x3>=x1 && x3<=x2 && y3<y1)
    {
      l2=y1-y3;
      l1=l2*l2;
    }
    else if(y3>=y1 && y3<=y2 && x3<x1)
    {
      l2=x1-x3;
      l1=l2*l2;
    }
    else if(y3>=y1 && y3<=y2 && x3>x2)
    {
      l2=x3-x2;
      l1=l2*l2;
    }
    else if(x3<x1 && y3>y2)
    {
      l1=(x3-x1)*(x3-x1)+(y3-y2)*(y3-y2);
      l2=abs(x3-x1)+abs(y3-y2);
    }
    else if(x3<x1 && y3<y1)
    {
      l1=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
      l2=abs(x3-x1)+abs(y3-y1);
    }
    else if(x3>x2 && y3<y1)
    {
      l1=(x3-x2)*(x3-x2)+(y3-y1)*(y3-y1);
      l2=abs(x3-x2)+abs(y3-y1);
    }
    else if(x3>x2 && y3>y2)
    {
      l1=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
      l2=abs(x3-x2)+abs(y3-y2);
    }
    else
    { l1=0; l2=0;}
    cout<<l1<<" "<< l2<<endl;
    }
    return 0;
    instream.close();
}
