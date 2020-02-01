/******************************************************************************
*problem : 디지털시계
*                                                                             *
******************************************************************************/

/******************************************************************************
* 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
*                                                          20143104 조승현   *
* ***************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
     cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;

  while(numtestcases--){
    string data;
    int num;
    instream>>data>>num;
  }
  return 0;
}
