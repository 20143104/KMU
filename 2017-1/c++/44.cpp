/******************************************************************************
*problem : 홀수 마방진
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


void mabangjin(int &n){
  int array[50][50]={0,};
  int row = 0;
  int col = n/2;
  int num=1;
  array[row][col]=1;
  int tempcol,temprow;
  while(num<n*n){
    tempcol=(col+1)%n;
    temprow= (row-1+n)%n;
    if(array[temprow][tempcol]==0){
      col=tempcol;
      row=temprow;
      array[row][col]=++num;
    }
    else{
      row=(row+1)%n;
      array[row][col]=++num;
    }

  }
  for(int i=0; i<n; i++){
    for(int k=0; k<n; k++){
      cout<<array[i][k]<<" ";
    }
    cout<<endl;
  }
}
int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
     cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;


  while(numtestcases--){
    int n;
    instream>>n;
    mabangjin(n);
  }
    return 0;
}
