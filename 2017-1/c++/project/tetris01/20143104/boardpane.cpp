#include<ncurses.h>
#include"main.h"

BoardPane::BoardPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
void BoardPane::draw(){
  init_pair(5, COLOR_BLUE, COLOR_BLACK);
  wattron(win_, COLOR_PAIR(5));
  for (int i=0; i<height_; i++)
  mvwhline(win_, i, 0, ACS_CKBOARD, width_);
  box(win_, 0, 0);
  wattroff(win_, COLOR_PAIR(5));
  wrefresh(win_);
}
