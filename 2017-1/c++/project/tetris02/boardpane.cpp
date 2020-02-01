#include"main.h"
#include <ncursesw/curses.h>
#include<locale.h>
BoardPane::BoardPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
void BoardPane::draw(){
  wattron(win_, COLOR_PAIR(5));
  for (int i=0; i<height_; i++)
  mvwhline(win_, i, 0, ACS_CKBOARD, width_);
  box(win_, 0, 0);
  wattroff(win_, COLOR_PAIR(5));
  wrefresh(win_);
}
void BoardPane::printframe(int board[][20]){
  for(int i=0; i<10; i++){
    for(int j=0; j<20; j++){
      if(board[i][j]==1){
        wattron(win_,COLOR_PAIR(7));
        mvwprintw(win_,j+1,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(7));
    }
      else{
        wattron(win_,COLOR_PAIR(1));
        mvwprintw(win_,j+1,2*i+1,"11");
        wattroff(win_,COLOR_PAIR(1));
      }
    }
  }
  wrefresh(win_);
}
void BoardPane::printEnd(Score &sc){
  mvwprintw(win_,5,7,"Game Over");
  mvwprintw(win_,7,5,"Press Any Key");
  mvwprintw(win_,9,7,"Score : %d",sc.getScore());
  wrefresh(win_);
}
