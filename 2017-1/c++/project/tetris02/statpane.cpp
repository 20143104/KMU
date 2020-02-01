#include"main.h"

StatPane::StatPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
void StatPane::draw(){
  wattron(win_, COLOR_PAIR(6));
  box(win_, 0, 0);
  mvwprintw(win_, 0, 5, "STATISTICS");
  mvwprintw(win_, 1, 3, "SCORE : ");
  mvwprintw(win_, 1, 12, "%d",0);
  mvwprintw(win_, 2, 3, "LEVEL : ");
  mvwprintw(win_, 2, 12, "%d",1);
  mvwprintw(win_, 3, 3, "BLOCK : ");
  mvwprintw(win_, 3, 12, "%d",0);

  wattroff(win_, COLOR_PAIR(6));
  wrefresh(win_);
}
void StatPane::drawscore(Score &sc){
  wattron(win_, COLOR_PAIR(6));
  box(win_, 0, 0);
  mvwprintw(win_, 0, 5, "STATISTICS");
  mvwprintw(win_, 1, 12, "%d",sc.getScore());
  mvwprintw(win_, 2, 12, "%d",sc.getLevel());
  mvwprintw(win_, 3, 12, "%d",sc.getNumblock());
  wattroff(win_, COLOR_PAIR(6));
  wrefresh(win_);
}
