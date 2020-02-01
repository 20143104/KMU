/******************************************************************************
*problem : 라이프게임
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
int judge(char array[][102],int &i, int &k){
  int count=0;
  if(array[i-1][k]=='O')
    count++;
  if(array[i-1][k+1]=='O')
    count++;
  if(array[i][k+1] =='O')
    count++;
  if(array[i+1][k+1]=='O')
    count++;
  if(array[i+1][k]=='O')
    count++;
  if(array[i+1][k-1]=='O')
    count++;
  if(array[i][k-1]=='O')
    count++;
  if(array[i-1][k-1]=='O')
    count++;

  return count;

}
int game(char array[][102], char array_copy[][102], int &row, int &col){
  int count=0;
  for(int i=1; i<row+1; i++){
    for(int k=1; k<col+1; k++){
      int n=judge(array,i,k);
      if(array[i][k]=='O' && n==2)
        array_copy[i][k]='O';
      else if(n==3)
        array_copy[i][k]='O';
      else
        array_copy[i][k]='X';
    }
  }
  for(int i=1; i<row+1; i++){
    for(int k=1; k<col+1; k++){
      array[i][k]=array_copy[i][k];
      if(array[i][k]=='O')  count++;
    }
  }
  return count;
}

int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
     cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;

  while(numtestcases--){
    int row,col,time;
    instream>>row>>col>>time;

    char array[102][102] = {'\0',};
    char array_copy[102][102]={'\0',};


    for(int i=1; i<row+1; i++){
      for(int k=1; k<col+1; k++){
        instream>>array[i][k];
        array_copy[i][k]=array[i][k];
      }
    }
    time--;
    while(time--)
      game(array,array_copy,row,col);

    cout<<game(array,array_copy,row,col)<<endl;


    for(int i=1; i<row+1; i++){
      for(int k=1; k<col+1; k++){
        cout<<array[i][k];
      }
      cout<<endl;
    }
  }
}
