#include<ncurses.h>
#include"main.h"

NextPane::NextPane(int x,int y,int w,int h): Pane(x,y,w,h){}
void NextPane::draw(){
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  wattron(win_,COLOR_PAIR(4));
  for(int i=0; i<height_; i++)
    mvwhline(win_, i, 0, ACS_CKBOARD, width_);
  mvwprintw(win_,0,0,"NEXT PANE");
  wattroff(win_,COLOR_PAIR(4));
  wrefresh(win_);
}
