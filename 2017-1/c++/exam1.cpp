#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int updown(char array[][100],int &row, int &col){
  int mid = row/2;
  if(row%2==0){
    for(int i=0; i<mid; i++){
      for(int k=0; k<col; k++){
        if(array[mid-i-1][k]==array[mid+i][k]);
        else
          return 0;
      }
    }
    return 1;
  }
  if(row%2==1){
    for(int i=0; i<=mid; i++){
      for(int k=0; k<col; k++){
        if(array[mid-i][k]==array[mid+i][k]);
        else
          return 0;
      }
    }
  }
  return 1;
}
int rightleft(char array[][100], int &row, int &col){
  int mid = col/2;
  if(col%2==0){
    for(int i=0; i<mid; i++){
      for(int k=0; k<row; k++){
        if(array[k][mid-i-1]==array[k][mid+i]);
        else
          return 0;
      }
    }
    return 1;
  }
  if(col%2==1){
    for(int i=0; i<=mid; i++){
      for(int k=0; k<row; k++){
        if(array[k][mid-i]==array[k][mid+i]);
        else
          return 0;
      }
    }
  }
  return 1;
}
int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
    cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;

  while(numtestcases--){
    int row, col;
    instream>>row>>col;
    char array[100][100]={'\0'};
    for(int i=0; i<row; i++){
      for(int k=0; k<col; k++){
        instream>>array[i][k];
      }
    }
    if(updown(array,row,col) && rightleft(array,row,col))
      cout<<3<<endl;
    else if(updown(array,row,col))
      cout<<1<<endl;
    else if(rightleft(array,row,col))
      cout<<2<<endl;
    else
      cout<<0<<endl;
  }
  return 0;
}
