/******************************************************************************
*problem : 입체사목게임
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

void game(int array[], int &n, int board[][8]){
  for(int i=0; i<n; i++){
  int check=5;
    if(i%2==0){
      for(int k=0; k<6; k++){
        if(board[check][array[i]]==0)
          {board[check][array[i]]=1; break;}
        else
          check--;
      }
    }
    else{
      for(int k=0; k<6; k++){
        if(board[check][array[i]]==0)
          {board[check][array[i]]=2; break;}
        else
          check--;
      }
    }
  }
}
int result(int board[][8]){
  for(int i=0; i<6; i++){
    for(int k=1; k<8; k++){
      if(k+3<=7){  //가로
        if(board[i][k]==1 && board[i][k+1]==1 && board[i][k+2]==1 && board[i][k+3]==1)  return 1;
        else if(board[i][k]==2&&board[i][k+1]==2&&board[i][k+2]==2 && board[i][k+3]==2) return 2;
      }
      if(i+3<=5){  // 세로
        if(board[i][k]==1 && board[i+1][k]==1 && board[i+2][k]==1 && board[i+3][k]==1) return 1;
        else if(board[i][k]==2&&board[i+1][k]==2 && board[i+2][k]==2 && board[i+3][k]==2) return 2;
      }
      if(i+3<=5 && k+3<=7){ //대각선
        if(board[i][k]==1&&board[i+1][k+1]==1 && board[i+2][k+2]==1 && board[i+3][k+3]==1) return 1;
        else if(board[i][k]==2&&board[i+1][k+1]==2 && board[i+2][k+2]==2 && board[i+3][k+3]==2) return 2;
      }
      if(i+3<=5 && k-3>=1){ // 대각선
        if(board[i][k]==1&&board[i+1][k-1]==1&&board[i+2][k-2]==1&&board[i+3][k-3]==1) return 1;
        if(board[i][k]==2&&board[i+1][k-1]==2&&board[i+2][k-2]==2&&board[i+3][k-3]==2) return 2;
      }

    }
  }
  return 0;
}

int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
     cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;


  while(numtestcases--){
    int numdata;
    instream>>numdata;
    int *array= new int[numdata];
    for(int i=0; i<numdata; i++)
      instream>>array[i];
    int board[6][8]={0,};
    game(array,numdata,board);
    cout<<result(board)<<endl;
    delete[] array;
  }
    return 0;
}
