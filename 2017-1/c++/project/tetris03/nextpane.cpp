#include"main.h"

NextPane::NextPane(int x,int y,int w,int h): Pane(x,y,w,h){}
void NextPane::draw(){
  wattron(win_,COLOR_PAIR(5));
  box(win_,0,0);
  mvwprintw(win_,0,0,"NEXT PANE");
  wattroff(win_,COLOR_PAIR(5));
  wrefresh(win_);
}
void NextPane::printnextpane(Block &block){
  int board[7][5]={0,};
  board[block.getx1()][block.gety1()]=block.gettrait();
  board[block.getx2()][block.gety2()]=block.gettrait();
  board[block.getx3()][block.gety3()]=block.gettrait();
  board[block.getx4()][block.gety4()]=block.gettrait();
  for(int i=0; i<7; i++){
    for(int j=0; j<4; j++){
      if(board[i][j]==1){
        wattron(win_,COLOR_PAIR(5));
        mvwprintw(win_,j+2,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(5));
      }
      else if(board[i][j]==2){
        wattron(win_,COLOR_PAIR(2));
        mvwprintw(win_,j+2,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(2));
      }
      else if(board[i][j]==3){
        wattron(win_,COLOR_PAIR(9));
        mvwprintw(win_,j+2,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(9));
      }
      else if(board[i][j]==4){
        wattron(win_,COLOR_PAIR(6));
        mvwprintw(win_,j+2,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(6));
      }
      else if(board[i][j]==5){
        wattron(win_,COLOR_PAIR(11));
        mvwprintw(win_,j+2,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(11));
      }
      else if(board[i][j]==6){
        wattron(win_,COLOR_PAIR(3));
        mvwprintw(win_,j+2,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(3));
      }
      else if(board[i][j]==7){
        wattron(win_,COLOR_PAIR(10));
        mvwprintw(win_,j+2,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(10));
      }
      else{
        wattron(win_,COLOR_PAIR(8));
        mvwprintw(win_,j+2,2*i+1,"11");
        wattroff(win_,COLOR_PAIR(8));
      }
    }
  }
  wrefresh(win_);
}
