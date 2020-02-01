/******************************************************************************
*problem : 선분의 교차
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/
#include<iostream>
#include<fstream>
#include"MyPoint.h"
#include"MyLineSegment.h"
using namespace std;

int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
     cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;
  while(numtestcases--){
    int ax,ay,bx,by,cx,cy,dx,dy;
    instream>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
    MyPoint p1(ax,ay);
    MyPoint p2(bx,by);
    MyPoint p3(cx,cy);
    MyPoint p4(dx,dy);

    MyLineSegment line1(p1,p2);
    MyLineSegment line2(p3,p4);

    if(line1.properIntersection(line2))
      cout<<"1"<<endl;
    else if(line1.improperIntersection(line2))
      cout<<"2"<<endl;
    else
      cout<<"0"<<endl;
  }
  return 0;
}
