#include"main.h"

void Block::Oblock(int board[][20]){
  x1=4; x2=5; x3=4; x4=5;
  y1=0; y2=0; y3=1; y4=1;
  board[x1][y1]=1;
  board[x2][y2]=1;
  board[x3][y3]=1;
  board[x4][y4]=1;
}
void Block::Movedown(int board[][20]){
  board[x1][y1+1]=board[x1][y1];
  board[x2][y2+1]=board[x2][y2];
  board[x3][y3+1]=board[x3][y3];
  board[x4][y4+1]=board[x4][y4];
  board[x1][y1]=0;
  board[x2][y2]=0;
  y1++; y2++; y3++; y4++;
}
bool Block::Checkdown(int board[][20]){
  if(y3+1<20 &&
  board[x3][y3+1]==0 && board[x4][y4+1]==0)
    return true;
  else
    return false;
}
void Block::Moveleft(int board[][20]){
  board[x1-1][y1]=board[x1][y1];
  board[x2-1][y2]=board[x2][y2];
  board[x3-1][y3]=board[x3][y3];
  board[x4-1][y4]=board[x4][y4];
  board[x2][y2]=0;
  board[x4][y4]=0;
  x1--;x2--;x3--;x4--;
}
bool Block::Checkleft(int board[][20]){
  if(x3-1>=0 && board[x3-1][y3]==0&&board[x1-1][y1]==0)
    return true;
  else
    return false;
}
void Block::Moveright(int board[][20]){
  board[x1+1][y1]=board[x1][y1];
  board[x2+1][y2]=board[x2][y2];
  board[x3+1][y3]=board[x3][y3];
  board[x4+1][y4]=board[x4][y4];
  board[x1][y1]=0;
  board[x3][y3]=0;
  x1++;x2++;x3++;x4++;
}
bool Block::Checkright(int board[][20]){
  if(x2+1<10 &&board[x2+1][y2]==0 && board[x4+1][y4]==0)
    return true;
  else
    return false;
}
