/******************************************************************************
*problem : 절단대각선                                        *
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

int result(int (*array)[100],int size);
int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail()){
    cerr<<"input file opening failed.\n";
  }

  int numtestcases;
  instream>>numtestcases;
  while(numtestcases--){
    int n;
    instream>> n;
    int data[100][100];
    int reversedata[100][100];
    for(int i=0; i<n; i++){
      for(int k=0; k<n; k++){
        instream>>data[i][k];
      }
    }
    int k,l;
    for(int i=0; i<n; i++){
      for(k=0, l=n-1; l>=0, k<n; l--,k++){
        reversedata[i][k]=data[i][l];
      }
    }

    int getmax,reversegetmax;
    getmax = result(data,n);
    reversegetmax = result(reversedata,n);

    if(getmax>reversegetmax)
      {cout<<getmax<<endl;}
    else
      {cout<<reversegetmax<<endl;}
  }
  return 0;
  instream.close();
}
int result(int (*array)[100],int size){
  int *sum = new int[size];
  for(int i=0; i<size; i++){
    for(int k=0; k<size; k++){
      if(i==k)
        {sum[0]=sum[0]+array[i][k];}
      for(int l=1; l<size; l++){
        if(k-i==size-l || k-i == -l)
          {sum[l]=sum[l]+array[i][k];}
      }
    }
  }
  int max=0;
  for(int i=0; i<size; i++){
    if(max<sum[i]){
      max=sum[i];
    }
  }
  return max;
}
