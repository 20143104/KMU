#include"main.h"
#include<ctime>
#include<fstream>
#include <stdio.h>
#include<iostream>
#include<cstdlib>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <ncurses.h>

using namespace std;

int changefilekey(char cur_key){
  if(cur_key=='l')
    return 1;
  else if(cur_key=='r')
    return 2;
  else if(cur_key=='g')
    return 3;
  else if(cur_key=='d')
    return 4;
  else if(cur_key=='t')
    return 5;
}
int main(int argc, char* argv[]){
  ifstream instream;
  char *name = new char[100];
  unsigned int seed;
  bool isgameover=true;

  if(argc>1){
    instream.open(argv[1]);
    instream>>name>>seed;
  }
  else{
    cout<<"Enter your name"<<endl;
    cin>>name;
    seed = (time(NULL));
  }
  Tetris t;
  Score sc;
  int board[10][20]={0,}; //게임판 생성
  t.updateScreen(); //초기 게임 화면
  t.updateinfopane(name);
  int startkey = getch();
  if(startkey==10){  //enter키 시작
    srand(seed);
    Block *gameblock;
    Block *nextblock;
    int a = rand();
    int b = rand();
    t.randomblock(gameblock,a);
    t.randomblock(nextblock,b);
    gameblock->createblock(board); // 초기 블록 생성
    t.updateboardpane(board); //화면 표시
    t.updatenextpane(*nextblock);
    t.updatestatpane(*gameblock);
    while(isgameover){
      if(gameblock->Checkdown(board)==false){ //블록이 노이면
        t.isFullline(board,sc);//줄 다차면 블럭 제거후 밑으로 내린 후 점수 계산
        gameblock = nextblock;
        a=rand();
        t.randomblock(nextblock,a);
        if(gameblock->isGameover(board)){
          gameblock->createblock(board);
          t.updateboardpane(board);
          t.updatestatpane(*gameblock);
          t.updatenextpane(*nextblock);
          break;
        }
        gameblock->createblock(board);//블럭 생성
        t.updatestatpane(*gameblock);
        t.updatenextpane(*nextblock);
        t.updateboardpane(board);//보드판 갱신
      }

      if(argc>1){//인풋값이 있으면
        char cur_key;
        instream>>cur_key;
        if(cur_key=='q')
          break;
        int change=changefilekey(cur_key);//문자를 정수로 치환
        t.play(board,*gameblock,change);
        usleep(600000);
      }
      else{//키보드로 부터 입력 받아
        while(1){
          halfdelay(5);
          int ch = getch();

          if(ch==ERR){  // 키보드로부터 입력이 없으면
            if(gameblock->Checkdown(board))
              gameblock->Movedown(board);
            else
              break;
            t.updateboardpane(board);
          }
          if(ch == 113){
            isgameover = false;
            break;
          }
          t.play(board,*gameblock,ch);
        }
      }
    }
  cbreak();
  t.printEnd(sc);
  int outkey = getch();
  }
  return 0;
}
