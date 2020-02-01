/******************************************************************************
*problem : 수직수평선분의교차                                             *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *          d                                                20143104 조승현   *
 * **************차*************************************************************/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;
int ishorizon(int a,int b,int c,int d);


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
     int x1,y1,x2,y2,x3,y3,x4,y4,temp;
     instream>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
     if(x1>x2)
     { temp=x2; x2=x1; x1=temp;}
     if(y1>y2)
     { temp=y2; y2=y1; y1=temp;}
     if(x3>x4)
     { temp=x4; x4=x3; x3=temp;}
     if(y3>y4)
     { temp=y4; y4=y3; y3=temp;}
     if(ishorizon(x1,y1,x2,y2))
     {
      if((x3>=x1&& x3<=x2 && y3==y1)||(x3>=x1&& x3<=x2 && y4==y1))
      cout <<2<<endl;
      else if((x3==x2&& y1>=y3 &&y1<=y4) || x3==x1&&y1>=y3 &&y1<=y4)
      cout <<2<<endl;
      else if(x3>x1&&x3<x2&&y1>y3&&y1<y4)
      cout <<1<<endl;
      else
      cout <<0<<endl;
      }
      else
      {
       if((x1==x3&&y3>=y1&&y3<=y2) || (x1==x4&&y3>=y1&&y3<=y2))
       cout <<2<<endl;
       else if((y2==y3&&x1>=x3&&x1<=x4) || (y1==y3&&x1>=x3&&x1<=x4))
       cout<<2<<endl;
       else if(x3<x1&&x4>x1&&y1<y3&&y2>y3)
       cout<<1<<endl;
       else
       cout<<0<<endl;
      }
     }
}
int ishorizon(int a,int b,int c,int d)
{
 if(b==d)
 return 1;
 else
 return 0;
}
