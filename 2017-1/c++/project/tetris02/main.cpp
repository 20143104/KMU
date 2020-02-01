#include"main.h"
#include<time.h>
#include<ncurses.h>
#include<fstream>
#include <stdio.h>
#include<iostream>
#include <unistd.h>
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
}

int main(int argc, char* argv[]){
  ifstream instream;
  char name[100]={};
  int id;
  bool isgameover=true;
  if(argc>1){
    instream.open(argv[1]);
    //instream>>name>>id;
  }
  Tetris t;
  t.updateScreen(); //초기 게임 화면
  int startkey = getch();
  if(startkey==10){  //enter키 시작
    Block gameblock;
    Score sc;
    int board[10][20]={0,}; //게임판 생성
    gameblock.Oblock(board); // 초기 블록 생성
    t.updateboardpane(board); //화면 표시
    while(isgameover){
      if(!(gameblock.Checkdown(board))){ //내려갈 곳 없으면
        t.isFullline(board,sc);//줄 다차면 블럭 제거후 밑으로 내린 후 점수 계산
        if(t.isGameover(board))//생성될수 없으면 게임오버
          break;
        gameblock.Oblock(board);//블럭 생성
      }
      t.updateboardpane(board);//보드판 갱신
      if(argc>1){//인풋값이 있으면
        char cur_key;
        instream>>cur_key;
        if(cur_key=='q')
          break;
        int change=changefilekey(cur_key);//문자를 정수로 치환
        t.play(board,gameblock,change);
        usleep(500000);
      }

      else{//키보드로 부터 입력 받아
        while(1){
          halfdelay(5);
          int ch = getch();
          if(ch==ERR){  // 키보드로부터 입력이 없으면
            if(gameblock.Checkdown(board))
              gameblock.Movedown(board);
            else
              break;
            t.updateboardpane(board);
          }
          if(ch == 113){
            isgameover = false;
            break;
          }
          t.play(board,gameblock,ch);
        }
      }
    }
  cbreak();
  t.printEnd(sc);
  int outkey = getch();
  }
  return 0;
}
