/******************************************************************************
*problem : cross puzzle
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
int row,col;
class position{
public:
  int x,y;
public:
  position(int _x,int _y):x(_x),y(_y){}
};

int result(char **board,string call, int len){
  vector<position>po;
  for(int i=1; i<=row; i++){
    for(int k=1; k<=col; k++){
      if(board[i][k]==call[0]){
        position xy(i,k);
        po.push_back(xy);
      }
    }
  }

  for(int i=0; i<po.size(); i++){
    if(po[i].x-len+1>=1){ //up
      int l;
      for(l=0; l<len; l++){
        if(board[po[i].x-l][po[i].y]!=call[l])
          break;
      }
      if(l==len){
        cout<<po[i].x<<" "<<po[i].y<<" ";
        return 0;
      }
    }
    if(po[i].y+len-1<=col){ //right
      int l;
      for(l=0; l<len; l++){
        if(board[po[i].x][po[i].y+l]!=call[l])
          break;
      }
      if(l==len){
        cout<<po[i].x<<" "<<po[i].y<<" ";
        return 2;
      }
    }
    if(po[i].x+len-1<=row){ //down
      int l;
      for(l=0; l<len; l++){
        if(board[po[i].x+l][po[i].y]!=call[l])
          break;
      }
      if(l==len){
        cout<<po[i].x<<" "<<po[i].y<<" ";
        return 4;
      }
    }
    if(po[i].y-len+1>=1){ //left
      int l;
      for(l=0; l<len; l++){
        if(board[po[i].x][po[i].y-l]!=call[l])
          break;
      }
      if(l==len){
        cout<<po[i].x<<" "<<po[i].y<<" ";
        return 6;
      }
    }
    if((po[i].x-len+1>=1) && (po[i].y+len-1<=col)){ // 1
      int l;
      for(l=0; l<len; l++){
        if(board[po[i].x-l][po[i].y+l]!= call[l])
          break;
      }
      if(l==len){
        cout<<po[i].x<<" "<<po[i].y<<" ";
        return 1;
      }
    }
    if((po[i].x+len-1<=row)&&(po[i].y+len-1<=col)){ // 3
      int l;
      for(l=0; l<len; l++){
        if(board[po[i].x+l][po[i].y+l]!= call[l])
          break;
      }
      if(l==len){
        cout<<po[i].x<<" "<<po[i].y<<" ";
        return 3;
      }
    }
    if((po[i].x+len-1<=row)&&(po[i].y-len+1>=1)){ // 5
      int l;
      for(l=0; l<len; l++){
        if(board[po[i].x+l][po[i].y-l]!= call[l])
          break;
      }
      if(l==len){
        cout<<po[i].x<<" "<<po[i].y<<" ";
        return 5;
      }
    }
    if((po[i].x-len+1>=1) &&(po[i].y-len+1>=1)){ // 7
      int l;
      for(l=0; l<len; l++){
        if(board[po[i].x-l][po[i].y-l]!= call[l])
          break;
      }
      if(l==len){
        cout<<po[i].x<<" "<<po[i].y<<" ";
        return 7;
      }
    }
  }
  return -1;

}
int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
     cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;

  while(numtestcases--){
    instream>>row>>col;
    char **board = new char*[row+1];
    for(int i=0; i<row+1; i++)
      board[i]=new char[col+1];

    for(int i=1; i<=row; i++){
      for(int k=1; k<=col; k++){
        instream>>board[i][k];
      }
    }

    int numcall;
    instream>>numcall;
    while(numcall--){
      string call;
      instream>>call;
      int len = call.size();
      cout<<result(board,call,len)<<endl;
    }
  }
  return 0;
}
