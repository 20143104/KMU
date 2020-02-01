/******************************************************************************
*problem : 해밍수                                                *
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
#include <list>
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
    unsigned int max = pow(2,32)-1;
    list<unsigned int>array;

    for(int j=0; ;j++)
    {
      if(pow(2,j)>max/2) break;
      for(int k=0; ;k++)
      {
        if(pow(2,j)*pow(3,k)>max/3) break;
        for(int l=0; ;l++)
        {
          array.push_front(pow(2,j)*pow(3,k)*pow(5,l));
          if(pow(2,j)*pow(3,k)*pow(5,l)>max/5) break;
        }
      }
    }
    int q=0;
    array.sort();
    list<unsigned int>::iterator itor=array.begin();
    for(itor=array.begin(); itor!=array.end(); itor++,q++)
    {
      if((data-1)==q) {cout<<*itor<<endl; break;}
    }
}
return 0;
instream.close();
}
