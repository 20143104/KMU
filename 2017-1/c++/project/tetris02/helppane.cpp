#include"main.h"

HelpPane::HelpPane(int x,int y,int w,int h): Pane(x,y,w,h){}
void HelpPane::draw(){
  wattron(win_,COLOR_PAIR(3));
  box(win_,0,0);
  mvwprintw(win_,0,0,"HELP PANE");
  mvwprintw(win_,2,2,"Enter : start");
  mvwprintw(win_,4,2,"↑ : turnblock");
  mvwprintw(win_,5,2,"→ : moveright");
  mvwprintw(win_,6,2,"↓ : movedown");
  mvwprintw(win_,7,2,"← : moveleft");
  mvwprintw(win_,8,2,"spacebar : movebottom");
  mvwprintw(win_,9,2,"q : quit game");
  wattroff(win_,COLOR_PAIR(3));
  wrefresh(win_);
}
