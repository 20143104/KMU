#include"main.h"

InfoPane::InfoPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
void InfoPane::draw(){
  wattron(win_, COLOR_PAIR(2));
  box(win_,0,0);
  mvwprintw(win_, 0,0, "INFO PANE");
  wattroff(win_, COLOR_PAIR(2));
  wrefresh(win_);
}
void InfoPane::drawinfo(char *name){
  wattron(win_, COLOR_PAIR(2));
  mvwprintw(win_, 1,9, "%s", name);
  wattroff(win_, COLOR_PAIR(2));
  wrefresh(win_);
}
