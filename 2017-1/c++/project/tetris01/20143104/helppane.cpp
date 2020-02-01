#include<ncurses.h>
#include"main.h"
HelpPane::HelpPane(int x,int y,int w,int h): Pane(x,y,w,h){}
void HelpPane::draw(){
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  wattron(win_,COLOR_PAIR(3));
  for(int i=0; i<height_; i++)
    mvwhline(win_, i, 0, ACS_CKBOARD, width_);
  mvwprintw(win_,0,0,"HELP PANE");
  wattroff(win_,COLOR_PAIR(3));
  wrefresh(win_);
}
