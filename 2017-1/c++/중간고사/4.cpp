/******************************************************************************
*problem : 주어진정수의 최대최소 구하기                                      *
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
      int numdata;
      instream>>numdata;
      int data_1,data_2,max,min;
      instream>> data_1;
      max=data_1;       //초기값 설정
      min=data_1;       //초기값 설정
      if (numdata==1)     //예외 데이터값이 1개일 경우
      {
      cout << max<<" " << min<< endl;
      }
      else
      {
        for(int j=1; j<numdata; j++)
         {
            instream >> data_2;
            if(max>data_2)
            {
              if(min<data_2){}
              else{min=data_2;}
            }
            else
            { max=data_2;   }
         }
       cout << max<<" " << min<< endl;
       }
    }
    return 0;
    instream.close();
    }
