#include"main.h"
int Lblock::num=0;
int Oblock::num=0;
int Jblock::num=0;
int Sblock::num=0;
int Zblock::num=0;
int Tblock::num=0;
int Iblock::num=0;
Lblock::Lblock(){
  x1=4; x2=4; x3=4; x4=5;
  y1=0; y2=1; y3=2; y4=2;
  state = 0;
  trait=1;
}
void Lblock::createblock(int board[][20]){
  num++;
  board[x1][y1]=1;
  board[x2][y2]=1;
  board[x3][y3]=1;
  board[x4][y4]=1;
}
void Lblock::Movedown(int board[][20]){
  if(state==0){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x4][y4]=0;
    y1++; y2++; y3++; y4++;
  }
  else if(state==1){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x4][y4]=0;
    y1++; y2++; y3++; y4++;
  }
  else if(state==2){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x3][y3]=0;
    board[x4][y4]=0;
    y1++; y2++; y3++; y4++;
  }
  else if(state==3){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    y1++; y2++; y3++; y4++;
  }
}
bool Lblock::Checkdown(int board[][20]){
  if(state==0){
    if(y4+1<20 && board[x3][y3+1]==0 && board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(y3+1<20 && board[x1][y1+1]==0 && board[x2][y2+1]==0 && board[x3][y3+1]==0)
      return true;
    else
      return false;
  }
  else if(state==2){
    if(y1+1<20 && board[x1][y1+1]==0 && board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
  else if(state==3){
    if(y4+1<20 && board[x1][y1+1]==0 && board[x2][y2+1]==0 && board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
}
void Lblock::Moveleft(int board[][20]){
  if(state==0){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
  else if(state==1){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x3][y3]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
  else if(state==2){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    x1--;x2--;x3--;x4--;
  }
  else if(state==3){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
}
bool Lblock::Checkleft(int board[][20]){
  if(state==0){
    if(x3-1>=0 && board[x1-1][y1]==0&&board[x2-1][y2]==0 && board[x3-1][y3]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(x1-1>=0 && board[x1-1][y1]==0 && board[x4-1][y4] ==0)
      return true;
    else
      return false;
  }
  else if(state==2){
    if(x4-1>=0 && board[x1-1][y1]==0 && board[x2-1][y2]==0 && board[x4-1][y3]==0)
      return true;
    else
      return false;
  }
  else if(state==3){
    if(x3-1>=0 && board[x3-1][y3]==0 && board[x4-1][y4]==0)
      return true;
    else
      return false;
  }
}
void Lblock::Moveright(int board[][20]){
  if(state==0){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    x1++;x2++;x3++;x4++;
  }
  else if(state==1){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
  else if(state==2){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
  else if(state==3){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x3][y3]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
}
bool Lblock::Checkright(int board[][20]){
  if(state==0){
    if(x4+1<10 &&board[x1+1][y1]==0 && board[x2+1][y2]==0 && board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(x4+1<10 && board[x3+1][y3]==0 && board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==2){
    if(x3+1<10 && board[x1+1][y1]==0 && board[x2+1][y2]==0 && board[x3+1][y3]==0)
      return true;
    else
      return false;
  }
  else if(state==3){
    if(x1+1<10 && board[x1+1][y1]==0 && board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
}
bool Lblock::isGameover(int board[][20]){
  if(board[x1][y1]!=0 || board[x2][y2]!=0 || board[x3][y3]!=0 || board[x4][y4]!=0)
    return true;
  else
    return false;
}
bool Lblock::Checkrotate(int board[][20]){
  if(state==0){
    if(x1-1>=0 &&board[x1-1][y1+1]==0&&board[x3+1][y3-1]==0&&board[x4][y4-2]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(y1+1<20 &&board[x1+1][y1+1]==0&&board[x3-1][y3-1]==0&&board[x4-2][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==2){
    if(x1+1<10&&board[x1+1][y1-1]==0&&board[x3-1][y3+1]==0&&board[x4][y4+2]==0)
      return true;
    else
      return false;
  }
  else if(state==3){
    if(y1-1>=0&&board[x1-1][y1-1]==0&&board[x3+1][y3+1]==0&&board[x4+2][y4]==0)
      return true;
    else
      return false;
  }
}
void Lblock::rotate(int board[][20]){
  if(state==0){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1-1][y1+1]=1;
    board[x2][y2]=1;
    board[x3+1][y3-1]=1;
    board[x4][y4-2]=1;
    x1-=1; y1+=1;
    x3+=1; y3-=1;
    y4-=2;
  }
  else if(state==1){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1+1][y1+1]=1;
    board[x2][y2]=1;
    board[x3-1][y3-1]=1;
    board[x4-2][y4]=1;
    x1+=1; y1+=1;
    x3-=1; y3-=1;
    x4-=2;
  }
  else if(state==2){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1+1][y1-1]=1;
    board[x2][y2]=1;
    board[x3-1][y3+1]=1;
    board[x4][y4+2]=1;
    x1+=1; y1-=1;
    x3-=1; y3+=1;
    y4+=2;
  }
  else if(state==3){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1-1][y1-1]=1;
    board[x2][y2]=1;
    board[x3+1][y3+1]=1;
    board[x4+2][y4]=1;
    x1-=1; y1-=1;
    x3+=1; y3+=1;
    x4+=2;
  }
  state+=1;
  state%=4;
}

Oblock::Oblock(){
  x1=4; x2=5; x3=4; x4=5;
  y1=0; y2=0; y3=1; y4=1;
  trait=7;
}
void Oblock::createblock(int board[][20]){
  num++;
  board[x1][y1]=7;
  board[x2][y2]=7;
  board[x3][y3]=7;
  board[x4][y4]=7;
}
void Oblock::Movedown(int board[][20]){
  board[x1][y1+1]=board[x1][y1];
  board[x2][y2+1]=board[x2][y2];
  board[x3][y3+1]=board[x3][y3];
  board[x4][y4+1]=board[x4][y4];
  board[x1][y1]=0;
  board[x2][y2]=0;
  y1++; y2++; y3++; y4++;
}
bool Oblock::Checkdown(int board[][20]){
  if(y3+1<20 &&
  board[x3][y3+1]==0 && board[x4][y4+1]==0)
    return true;
  else
    return false;
}
void Oblock::Moveleft(int board[][20]){
  board[x1-1][y1]=board[x1][y1];
  board[x2-1][y2]=board[x2][y2];
  board[x3-1][y3]=board[x3][y3];
  board[x4-1][y4]=board[x4][y4];
  board[x2][y2]=0;
  board[x4][y4]=0;
  x1--;x2--;x3--;x4--;
}
bool Oblock::Checkleft(int board[][20]){
  if(x3-1>=0 && board[x3-1][y3]==0&&board[x1-1][y1]==0)
    return true;
  else
    return false;
}
void Oblock::Moveright(int board[][20]){
  board[x1+1][y1]=board[x1][y1];
  board[x2+1][y2]=board[x2][y2];
  board[x3+1][y3]=board[x3][y3];
  board[x4+1][y4]=board[x4][y4];
  board[x1][y2]=0;
  board[x3][y4]=0;
  x1++;x2++;x3++;x4++;
}
bool Oblock::Checkright(int board[][20]){
  if(x2+1<10 &&board[x2+1][y2]==0 && board[x4+1][y4]==0)
    return true;
  else
    return false;
}
bool Oblock::isGameover(int board[][20]){
  if(board[x1][y1]!=0 || board[x2][y2]!=0 || board[x3][y3]!=0 || board[x4][y4]!=0)
    return true;
  else
    return false;
}

Jblock::Jblock(){
  x1=5; x2=5; x3=5; x4=4;
  y1=0; y2=1; y3=2; y4=2;
  state=0;
  trait=2;
}
void Jblock::createblock(int board[][20]){
  num++;
  board[x1][y1]=2;
  board[x2][y2]=2;
  board[x3][y3]=2;
  board[x4][y4]=2;
}
void Jblock::Movedown(int board[][20]){
  if(state==0){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x4][y4]=0;
    y1++; y2++; y3++; y4++;
  }
  else if(state==1){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    y1++; y2++; y3++; y4++;
  }
  else if(state==2){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x3][y3]=0;
    board[x4][y4]=0;
    y1++; y2++; y3++; y4++;
  }
  else if(state==3){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x4][y4]=0;
    y1++; y2++; y3++; y4++;
  }
}
bool Jblock::Checkdown(int board[][20]){
  if(state==0){
    if(y3+1<20 && board[x3][y3+1]==0 && board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(y4+1<20 && board[x1][y1+1]==0 && board[x2][y2+1]==0 && board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
  else if(state==2){
    if(y1+1<20 && board[x1][y1+1]==0 && board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
  else if(state==3){
    if(y3+1<20 && board[x1][y1+1]==0 && board[x2][y2+1]==0 && board[x3][y3+1]==0)
      return true;
    else
      return false;
  }
}
void Jblock::Moveleft(int board[][20]){
  if(state==0){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    x1--;x2--;x3--;x4--;
  }
  else if(state==1){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x3][y3]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
  else if(state==2){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
  else if(state==3){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
}
bool Jblock::Checkleft(int board[][20]){
  if(state==0){
    if(x4-1>=0 && board[x1-1][y1]==0&&board[x2-1][y2]==0 && board[x4-1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(x1-1>=0 && board[x1-1][y1]==0&&board[x4-1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==2){
    if(x3-1>=0 && board[x1-1][y1]==0&&board[x2-1][y2]==0 && board[x3-1][y3]==0)
      return true;
    else
      return false;
  }
  else if(state==3){
    if(x3-1>=0 &&board[x3-1][y3]==0 && board[x4-1][y4]==0)
      return true;
    else
      return false;
  }
}
void Jblock::Moveright(int board[][20]){
  if(state==0){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
  else if(state==1){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
  else if(state==2){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    x1++;x2++;x3++;x4++;
  }
  else if(state==3){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x3][y3]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
}
bool Jblock::Checkright(int board[][20]){
  if(state==0){
    if(x2+1<10 &&board[x1+1][y1]==0 && board[x2+1][y2]==0 && board[x3+1][y3]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(x3+1<10 && board[x3+1][y3]==0 && board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==2){
    if(x4+1<10 &&board[x1+1][y1]==0 && board[x2+1][y2]==0 && board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==3){
    if(x1+1<10 &&board[x1+1][y1]==0 && board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
}
bool Jblock::Checkrotate(int board[][20]){
  if(state==0){
    if(x3+1<10&&board[x1-1][y1+1]==0&&board[x3+1][y3-1]==0&&board[x4+2][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(y3-1>=0 &&board[x1+1][y1+1]==0&&board[x3-1][y3-1]==0&&board[x4][y4-2]==0)
      return true;
    else
      return false;
  }
  else if(state==2){
    if(x3-1>=0&&board[x1+1][y1-1]==0&&board[x3-1][y3+1]==0&&board[x4-2][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==3){
    if(y3+1<20&&board[x1-1][y1-1]==0&&board[x3+1][y3+1]==0&&board[x4][y4+2]==0)
      return true;
    else
      return false;
  }
}
void Jblock::rotate(int board[][20]){
  if(state==0){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1-1][y1+1]=2;
    board[x2][y2]=2;
    board[x3+1][y3-1]=2;
    board[x4+2][y4]=2;
    x1-=1; y1+=1;
    x3+=1; y3-=1;
    x4+=2;
  }
  else if(state==1){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1+1][y1+1]=2;
    board[x2][y2]=2;
    board[x3-1][y3-1]=2;
    board[x4][y4-2]=2;
    x1+=1; y1+=1;
    x3-=1; y3-=1;
    y4-=2;
  }
  else if(state==2){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1+1][y1-1]=2;
    board[x2][y2]=2;
    board[x3-1][y3+1]=2;
    board[x4-2][y4]=2;
    x1+=1; y1-=1;
    x3-=1; y3+=1;
    x4-=2;
  }
  else if(state==3){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1-1][y1-1]=2;
    board[x2][y2]=2;
    board[x3+1][y3+1]=2;
    board[x4][y4+2]=2;
    x1-=1; y1-=1;
    x3+=1; y3+=1;
    y4+=2;
  }
  state+=1;
  state%=4;
}
bool Jblock::isGameover(int board[][20]){
  if(board[x1][y1]!=0 || board[x2][y2]!=0 || board[x3][y3]!=0 || board[x4][y4]!=0)
    return true;
  else
    return false;
}

Sblock::Sblock(){
  x1=4; x2=4; x3=5; x4=5;
  y1=0; y2=1; y3=1; y4=2;
  state=0;
  trait=3;
}
void Sblock::createblock(int board[][20]){
  num++;
  board[x1][y1]=3;
  board[x2][y2]=3;
  board[x3][y3]=3;
  board[x4][y4]=3;
}
void Sblock::Movedown(int board[][20]){
  if(state==0){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x3][y3]=0;
    y1++; y2++; y3++; y4++;
  }
  if(state==1){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    y1++; y2++; y3++; y4++;
  }
}
bool Sblock::Checkdown(int board[][20]){
  if(state==0){
    if(y4+1<20 &&board[x4][y4+1]==0&& board[x2][y2+1]==0)
      return true;
    else
      return false;
  }
  if(state==1){
    if(y1+1<20 && board[x1][y1+1]==0 && board[x2][y2+1]==0 && board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
}
void Sblock::Moveleft(int board[][20]){
  if(state==0){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
  else if(state==1){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x2][y2]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;

  }
}
bool Sblock::Checkleft(int board[][20]){
  if(state==0){
    if(x1-1>=0 && board[x1-1][y1]==0&&board[x2-1][y2]==0&& board[x4-1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(x1-1>=0 && board[x1-1][y1]==0 && board[x3-1][y3]==0)
      return true;
    else
      return false;
  }
}
void Sblock::Moveright(int board[][20]){
  if(state==0){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
  else if(state==1){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x3][y3]=0;
    x1++;x2++;x3++;x4++;
  }
}
bool Sblock::Checkright(int board[][20]){
  if(state==0){
    if(x4+1<10 &&board[x1+1][y1]==0&&board[x3+1][y3]==0&& board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(x4+1<10 && board[x2+1][y2]==0 && board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
}
bool Sblock::isGameover(int board[][20]){
  if(board[x1][y1]!=0 || board[x2][y2]!=0 || board[x3][y3]!=0 || board[x4][y4]!=0)
    return true;
  else
    return false;
}
bool Sblock::Checkrotate(int board[][20]){
  if(state==0){
    if(x1-1>=0&&board[x1-1][y1+1]==0&&board[x4][y4-2]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(y4+2<20 && board[x3+1][y3+1]==0 && board[x4][y4+2]==0)
      return true;
    else
      return false;
  }
}
void Sblock::rotate(int board[][20]){
  if(state==0){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1-1][y1+1]=3;
    board[x2][y2]=3;
    board[x3-1][y3-1]=3;
    board[x4][y4-2]=3;
    x1-=1; y1+=1;
    x3-=1; y3-=1;
    y4-=2;
  }
  else if(state==1){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1+1][y1-1]=3;
    board[x2][y2]=3;
    board[x3+1][y3+1]=3;
    board[x4][y4+2]=3;
    x1+=1; y1-=1;
    x3+=1; y3+=1;
    y4+=2;
  }
  state+=1;
  state%=2;
}

Zblock::Zblock(){
  x1=5; x2=5; x3=4; x4=4;
  y1=0; y2=1; y3=1; y4=2;
  state=0;
  trait = 4;
}
void Zblock::createblock(int board[][20]){
  num++;
  board[x1][y1]=4;
  board[x2][y2]=4;
  board[x3][y3]=4;
  board[x4][y4]=4;
}
void Zblock::Movedown(int board[][20]){
  if(state==0){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x3][y3]=0;
    y1++; y2++; y3++; y4++;
  }
  else if(state==1){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    y1++; y2++; y3++; y4++;
  }
}
bool Zblock::Checkdown(int board[][20]){
  if(state==0){
    if(y4+1<20 &&
    board[x2][y2+1]==0 && board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(y1+1<20 && board[x1][y1+1]==0 && board[x2][y2+1]==0 && board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
}
void Zblock::Moveleft(int board[][20]){
  if(state==0){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
  else if(state==1){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x3][y3]=0;
    x1--;x2--;x3--;x4--;
  }
}
bool Zblock::Checkleft(int board[][20]){
  if(state==0){
    if(x3-1>=0 && board[x1-1][y1]==0&&board[x3-1][y3]==0&&board[x4-1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(x4-1>=0 && board[x2-1][y2]==0 && board[x4-1][y4]==0)
      return true;
    else
      return false;
  }
}
void Zblock::Moveright(int board[][20]){
  if(state==0){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
  else if(state==1){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x2][y2]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
}
bool Zblock::Checkright(int board[][20]){
  if(state==0){
    if(x1+1<10 &&board[x1+1][y1]==0 && board[x2+1][y2]==0&& board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(x1+1<10 && board[x1+1][y1]==0 && board[x3+1][y3]==0)
      return true;
    else
      return false;
  }
}
bool Zblock::isGameover(int board[][20]){
  if(board[x1][y1]!=0 || board[x2][y2]!=0 || board[x3][y3]!=0 || board[x4][y4]!=0)
    return true;
  else
    return false;
}
void Zblock::rotate(int board[][20]){
  if(state==0){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1+1][y1+1]=4;
    board[x2][y2]=4;
    board[x3+1][y3-1]=4;
    board[x4][y4-2]=4;
    x1+=1; y1+=1;
    x3+=1; y3-=1;
    y4-=2;
  }
  else if(state==1){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1-1][y1-1]=4;
    board[x2][y2]=4;
    board[x3-1][y3+1]=4;
    board[x4][y4+2]=4;
    x1-=1; y1-=1;
    x3-=1; y3+=1;
    y4+=2;
  }
  state+=1;
  state%=2;
}
bool Zblock::Checkrotate(int board[][20]){
  if(state==0){
    if(x1+1<10 &&board[x1+1][y1+1]==0&& board[x4][y4-2]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(y4+2<20 &&board[x3-1][y3+1]==0&& board[x4][y4+2]==0)
      return true;
    else
      return false;
  }
}

Tblock::Tblock(){
  x1=4; x2=3; x3=4; x4=5;
  y1=0; y2=1; y3=1; y4=1;
  state=0;
  trait=5;
}
void Tblock::createblock(int board[][20]){
  num++;
  board[x1][y1]=5;
  board[x2][y2]=5;
  board[x3][y3]=5;
  board[x4][y4]=5;
}
void Tblock::Movedown(int board[][20]){
  if(state==0){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x4][y4]=0;
    y1++; y2++; y3++; y4++;
  }
  else if(state==1){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x4][y4]=0;
    y1++; y2++; y3++; y4++;
  }
  else if(state==2){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x3][y3]=0;
    board[x2][y2]=0;
    board[x4][y4]=0;
    y1++; y2++; y3++; y4++;
  }
  else if(state==3){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    y1++; y2++; y3++; y4++;
  }
}
bool Tblock::Checkdown(int board[][20]){
  if(state==0){
    if(y3+1<20 &&
    board[x2][y2+1]==0 && board[x3][y3+1]==0 && board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(y2+1<20&&board[x1][y1+1]==0 && board[x2][y2+1]==0)
      return true;
    else
      return false;
  }
  else if(state==2){
    if(y1+1<20&&board[x1][y1+1]==0&&board[x2][y2+1]==0&&board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
  else if(state==3){
    if(y4+1<20&&board[x1][y1+1]==0&&board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
}
void Tblock::Moveleft(int board[][20]){
  if(state==0){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
  else if(state==1){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
  else if(state==2){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    x1--;x2--;x3--;x4--;
  }
  else if(state==3){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
}
bool Tblock::Checkleft(int board[][20]){
  if(state==0){
    if(x2-1>=0 && board[x2-1][y2]==0&&board[x1-1][y1]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(x1-1>=0&&board[x1-1][y1]==0&&board[x2-1][y2]==0&&board[x4-1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==2){
    if(x4-1>=0&&board[x1-1][y1]==0&&board[x4-1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==3){
    if(x4-1>=0&&board[x2-1][y2]==0&&board[x3-1][y3]==0&&board[x4-1][y4]==0)
      return true;
    else
      return false;
  }
}
void Tblock::Moveright(int board[][20]){
  if(state==0){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    x1++;x2++;x3++;x4++;
  }
  else if(state==1){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
  else if(state==2){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
  else if(state==3){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
}
bool Tblock::Checkright(int board[][20]){
  if(state==0){
    if(x4+1<10 &&board[x1+1][y1]==0 && board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(x2+1<10 && board[x2+1][y2]==0&&board[x3+1][y3]==0&&board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state==2){
    if(x2+1<10&&board[x1+1][y1]==0&& board[x2+1][y2]==0)
      return true;
    else
      return false;
  }
  else if(state==3){
    if(x1+1<10&&board[x1+1][y1]==0&& board[x2+1][y2]==0&&board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
}
bool Tblock::isGameover(int board[][20]){
  if(board[x1][y1]!=0 || board[x2][y2]!=0 || board[x3][y3]!=0 || board[x4][y4]!=0)
    return true;
  else
    return false;
}
bool Tblock::Checkrotate(int board[][20]){
  if(state==0){
    if(y2+1<20 && board[x2][y2+1]==0)
      return true;
    else
      return false;
  }
  else if(state==1){
    if(x2+1<10 && board[x2+1][y2]==0)
      return true;
    else
      return false;
  }
  else if(state==2){
    if(y2-1>=0 && board[x2][y2-1]==0)
      return true;
    else
      return false;
  }
  else if(state==3){
    if(x2-1>=0 && board[x2-1][y2]==0)
      return true;
    else
      return false;
  }
}
void Tblock::rotate(int board[][20]){
  if(state==0){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1-1][y1+1]=5;
    board[x2+1][y2+1]=5;
    board[x3][y3]=5;
    board[x4-1][y4-1]=5;
    x1-=1; y1+=1;
    x2+=1; y2+=1;
    x4-=1; y4-=1;
  }
  else if(state==1){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1+1][y1+1]=5;
    board[x2+1][y2-1]=5;
    board[x3][y3]=5;
    board[x4-1][y4+1]=5;
    x1+=1; y1+=1;
    x2+=1; y2-=1;
    x4-=1; y4+=1;
  }
  else if(state==2){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1+1][y1-1]=5;
    board[x2-1][y2-1]=5;
    board[x3][y3]=5;
    board[x4+1][y4+1]=5;
    x1+=1; y1-=1;
    x2-=1; y2-=1;
    x4+=1; y4+=1;
  }
  else if(state==3){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1-1][y1-1]=5;
    board[x2-1][y2+1]=5;
    board[x3][y3]=5;
    board[x4+1][y4-1]=5;
    x1-=1; y1-=1;
    x2-=1; y2+=1;
    x4+=1; y4-=1;
  }
  state+=1;
  state%=4;
}

Iblock::Iblock(){
  x1=4; x2=4; x3=4; x4=4;
  y1=0; y2=1; y3=2; y4=3;
  state = 0;
  trait=6;
}
void Iblock::createblock(int board[][20]){
  num++;
  board[x1][y1]=6;
  board[x2][y2]=6;
  board[x3][y3]=6;
  board[x4][y4]=6;
}
void Iblock::Movedown(int board[][20]){
  if(state==0){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    y1++; y2++; y3++; y4++;
  }
  else if(state==1){
    board[x1][y1+1]=board[x1][y1];
    board[x2][y2+1]=board[x2][y2];
    board[x3][y3+1]=board[x3][y3];
    board[x4][y4+1]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    y1++; y2++; y3++; y4++;
  }
}
bool Iblock::Checkdown(int board[][20]){
  if(state==0){
    if(y4+1<20 &&
      board[x4][y4+1]==0)
      return true;
      else
      return false;
  }
  else if(state==1){
    if(y1+1<20 && y2+1<20 && y3+1<20 && y4+1<20 &&
    board[x1][y1+1]==0 && board[x2][y2+1]==0 &&
    board[x3][y3+1]==0 && board[x4][y4+1]==0)
      return true;
    else
      return false;
  }
}
void Iblock::Moveleft(int board[][20]){
  if(state==0){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
  else if(state==1){
    board[x1-1][y1]=board[x1][y1];
    board[x2-1][y2]=board[x2][y2];
    board[x3-1][y3]=board[x3][y3];
    board[x4-1][y4]=board[x4][y4];
    board[x4][y4]=0;
    x1--;x2--;x3--;x4--;
  }
}
bool Iblock::Checkleft(int board[][20]){
  if(state==0){
    if(x3-1>=0 && board[x1-1][y1]==0 && board[x2-1][y2]==0&&board[x3-1][y3]==0 && board[x4-1][y4]==0)
      return true;
    else
      return false;
  }
  else if(state){
    if(x1-1>=0 && board[x1-1][y1]==0)
      return true;
    else
      return false;
  }
}
void Iblock::Moveright(int board[][20]){
  if(state==0){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    x1++;x2++;x3++;x4++;
  }
  else if(state==1){
    board[x1+1][y1]=board[x1][y1];
    board[x2+1][y2]=board[x2][y2];
    board[x3+1][y3]=board[x3][y3];
    board[x4+1][y4]=board[x4][y4];
    board[x1][y1]=0;
    x1++;x2++;x3++;x4++;
  }
}
bool Iblock::Checkright(int board[][20]){
  if(state==0){
    if(x2+1<10 &&board[x1+1][y1]==0 && board[x2+1][y2]==0 && board[x3+1][y1]==0 && board[x4+1][y4]==0)
      return true;
    else
    return false;
  }
  else if(state==1){
    if(x4+1<10 && board[x4+1][y4]==0)
      return true;
    else
      return false;
  }
}
bool Iblock::isGameover(int board[][20]){
  if(board[x1][y1]!=0 || board[x2][y2]!=0 || board[x3][y3]!=0 || board[x4][y4]!=0)
    return true;
  else
    return false;
}
void Iblock::rotate(int board[][20]){
  if(state==1){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1+1][y1-1]=6;
    board[x2][y2]=6;
    board[x3-1][y3+1]=6;
    board[x4-2][y4+2]=6;
    x1+=1; y1-=1;
    x3-=1; y3+=1;
    x4-=2; y4+=2;
  }
  else if(state==0){
    board[x1][y1]=0;
    board[x2][y2]=0;
    board[x3][y3]=0;
    board[x4][y4]=0;
    board[x1-1][y1+1]=6;
    board[x2][y2]=6;
    board[x3+1][y3-1]=6;
    board[x4+2][y4-2]=6;
    x1-=1; y1+=1;
    x3+=1; y3-=1;
    x4+=2; y4-=2;
  }
  state+=1;
  state%=2;
}
bool Iblock::Checkrotate(int board[][20]){
  if(state==0){
    if(x1-1>=0 && x4+2<10 && board[x1-1][y1+1]==0 &&board[x3+1][y3-1]==0
      && board[x4+2][y4-2]==0)
     return true;
    else
      return false;
  }
  if(state==1){
    if(y1-1>=0 && y4+2<20 && board[x1+1][y1-1]==0&&board[x3-1][y3+1]==0&&
    board[x4-2][y4+2]==0)
      return true;
    else
      return false;
  }

}
