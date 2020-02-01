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
        wattron(win_,COLOR_PAIR(5));
        mvwprintw(win_,j+1,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(5));
      }
      else if(board[i][j]==2){
        wattron(win_,COLOR_PAIR(2));
        mvwprintw(win_,j+1,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(2));
      }
      else if(board[i][j]==3){
        wattron(win_,COLOR_PAIR(9));
        mvwprintw(win_,j+1,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(9));
      }
      else if(board[i][j]==4){
        wattron(win_,COLOR_PAIR(6));
        mvwprintw(win_,j+1,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(6));
      }
      else if(board[i][j]==5){
        wattron(win_,COLOR_PAIR(11));
        mvwprintw(win_,j+1,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(11));
      }
      else if(board[i][j]==6){
        wattron(win_,COLOR_PAIR(3));
        mvwprintw(win_,j+1,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(3));
      }
      else if(board[i][j]==7){
        wattron(win_,COLOR_PAIR(10));
        mvwprintw(win_,j+1,2*i+1,"■ ");
        wattroff(win_,COLOR_PAIR(10));
      }
      else{
        wattron(win_,COLOR_PAIR(8));
        mvwprintw(win_,j+1,2*i+1,"11");
        wattroff(win_,COLOR_PAIR(8));
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
