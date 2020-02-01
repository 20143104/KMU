/******************************************************************************
*problem : 패리티비트                                                        *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include<algorithm>

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
   int checknum=0;
   instream>>numdata;
   int *data=new int[numdata-1];
   int *data1=new int[numdata-1];
   int *count=new int[numdata-1];
   for(int k=0; k<numdata; k++)
    instream>>data[k];
/////////////////////////////////////////////////////
   sort(data,data+numdata);  ///////////크기 순으로 정렬
/////////////////////////////////////////////////////
   data[numdata]=-1;
   for(int k=0; k<numdata; k++)
   {
     if(data[k]!=data[k+1])
       {data1[checknum]=data[k]; checknum++;}
     else
       count[checknum]++;
   }

   int maxcount;
   maxcount=count[0];
   for(int k=0; k<checknum; k++)
   {
     if(maxcount<count[k+1])
       maxcount =count[k+1];
   }
   int finalcount=0;
   for(int k=0; k<checknum; k++)
     {if(maxcount==count[k]) finalcount++;}
   cout<<finalcount<<" "<<maxcount+1<<" ";
   for(int k=0; k<checknum; k++)
     {if(maxcount==count[k]) cout<<data1[k]<<" ";}
  cout<<endl;

 }
return 0;
instream.close();
}
