/******************************************************************************
*problem : 해밍거리                                  *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
void convert(int &data,int array[32]){
  int i=0;
  while(data!=0){
    array[i++]=data%2;
    data/=2;
  }
}
void weight(int array[32]){
  int count=0;
  for(int i=0; i<=31; i++){
    if(array[i]==1)
      count++;
  }
  cout<<count<<" ";
}
void distance(int array1[32],int array2[32]){
  int count=0;
  for(int i=0; i<32; i++){
    if(array1[i]!=array2[i])
      count++;
  }
  cout<<count<<endl;
}
int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
    cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;
  while(numtestcases--){
    int data1,data2;
    instream>>data1>>data2;
    int array1[32]={0,};
    int array2[32]={0,};
    convert(data1,array1);
    convert(data2,array2);
    weight(array1);
    weight(array2);
    distance(array1,array2);
  }
}
