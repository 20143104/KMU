/******************************************************************************
*problem : 삼각형 면적                                             *
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
  int ax,ay,bx,by,cx,cy;
  instream>>ax>>ay>>bx>>by>>cx>>cy;
  int S=(bx-ax)*(cy-ay)-(cx-ax)*(by-ay);
  if(S<0)
   cout<<abs(S)<<" "<<-1<<endl;
  else if(S>0)
   cout<<S<<" "<<1<<endl;
  else
   cout<<0<<" "<<0<<endl;
 }
 return 0;
 instream.close();
}
