/******************************************************************************
*problem : 숫자맞추기게임                                                *
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
    int result[10000];
    for(int k=0; k<10000; k++)
      result[k]=k;
    int numdata;
    instream>>numdata;
    int *array = new int[3];
    int *array_s = new int[3];

    for(int k=0; k<numdata; k++)
    {
      int data,s,b;
      instream>>data>>s>>b;



      for(int j=0; j<10000; j++)
      {
        int count_s=0;
        int count_b=0;
        array[0]=data/1000;
        array[1]=data%1000/100;
        array[2]=data%100/10;
        array[3]=data%10;
        array_s[0]=result[j]/1000;
        array_s[1]=result[j]%1000/100;
        array_s[2]=result[j]%100/10;
        array_s[3]=result[j]%10;

        for(int m=0; m<4; m++)
        {
          if(array[m]==array_s[m]) {count_s++; array[m]=-1; array_s[m]= -1;continue;}
          for(int n=0; n<4; n++)
          {
            if(m==n) {continue;}
            if(array[m]==array_s[n]) {count_b++; break;}
          }
        }   ///////////////////스트라이크와 볼 개수 구하는 함수

        if(count_s==s && count_b==b)
         {continue;}
        else
         {result[j]=-1;}
      }
     }
     int count=0;
     for(int j=0; j<10000; j++)
     {if(result[j]!=-1) {count++;}}

     if(count==0)
      {cout<<-2<<endl;}
     else if(count>=2)
      {cout<<-1<<endl;}
     else if(count==1)
      {
        for(int j=0; j<10000; j++)
          {if(result[j]!=-1) {cout<<result[j]<<endl; break;}}
      }
   }
   return 0;
   instream.close();
 }
