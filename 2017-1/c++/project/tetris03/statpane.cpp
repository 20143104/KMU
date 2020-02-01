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
  wattron(win_,COLOR_PAIR(10));
  mvwprintw(win_, 5, 1,"■ ");
  mvwprintw(win_, 5, 3,"■ ");
  mvwprintw(win_, 6, 1,"■ ");
  mvwprintw(win_, 6, 3,"■ ");
  mvwprintw(win_, 6, 5,":0");
  wattroff(win_,COLOR_PAIR(10));

  wattron(win_,COLOR_PAIR(5));
  mvwprintw(win_, 8, 1,"■ ");
  mvwprintw(win_, 9, 1,"■ ");
  mvwprintw(win_, 10, 1,"■ ");
  mvwprintw(win_, 10, 3,"■ ");
  mvwprintw(win_, 10, 5,":0");
  wattroff(win_,COLOR_PAIR(5));

  wattron(win_,COLOR_PAIR(2));
  mvwprintw(win_, 12, 3,"■ ");
  mvwprintw(win_, 13, 3,"■ ");
  mvwprintw(win_, 14, 3,"■ ");
  mvwprintw(win_, 14, 1,"■ ");
  mvwprintw(win_, 14, 5,":0");
  wattroff(win_,COLOR_PAIR(2));

  wattron(win_,COLOR_PAIR(9));
  mvwprintw(win_, 16, 1,"■ ");
  mvwprintw(win_, 17, 1,"■ ");
  mvwprintw(win_, 17, 3,"■ ");
  mvwprintw(win_, 18, 3,"■ ");
  mvwprintw(win_, 18, 5,":0");

  wattroff(win_,COLOR_PAIR(9));

  wattron(win_,COLOR_PAIR(6));
  mvwprintw(win_, 5, 11,"■ ");
  mvwprintw(win_, 6, 11,"■ ");
  mvwprintw(win_, 6, 9,"■ ");
  mvwprintw(win_, 7, 9,"■ ");
  mvwprintw(win_, 7, 11,":0");

  wattroff(win_,COLOR_PAIR(6));

  wattron(win_,COLOR_PAIR(11));
  mvwprintw(win_, 10, 9,"■ ");
  mvwprintw(win_, 10, 11,"■ ");
  mvwprintw(win_, 10, 13,"■ ");
  mvwprintw(win_, 9, 11,"■ ");
  mvwprintw(win_, 10, 15,":0");

  wattroff(win_,COLOR_PAIR(11));

  wattron(win_,COLOR_PAIR(3));
  mvwprintw(win_, 12, 9,"■ ");
  mvwprintw(win_, 13, 9,"■ ");
  mvwprintw(win_, 14, 9,"■ ");
  mvwprintw(win_, 15, 9,"■ ");
  mvwprintw(win_, 15, 11,":0");

  wattroff(win_,COLOR_PAIR(3));

  wrefresh(win_);
}
void StatPane::printscore(Score &sc){
  wattron(win_, COLOR_PAIR(6));
  box(win_, 0, 0);
  mvwprintw(win_, 0, 5, "STATISTICS");
  mvwprintw(win_, 1, 12, "%d",sc.getScore());
  mvwprintw(win_, 2, 12, "%d",sc.getLevel());
  mvwprintw(win_, 3, 12, "%d",sc.getNumblock());
  wattroff(win_, COLOR_PAIR(6));
  wrefresh(win_);
}
void StatPane::printnum(Block &block){
  if(block.gettrait()==1){
    wattron(win_,COLOR_PAIR(5));
    mvwprintw(win_,10,6,"%d",block.getnum());
    wattroff(win_,COLOR_PAIR(5));
  }
  else if(block.gettrait()==2){
    wattron(win_,COLOR_PAIR(2));
    mvwprintw(win_,14,6,"%d",block.getnum());
    wattroff(win_,COLOR_PAIR(2));
  }
  else if(block.gettrait()==3){
    wattron(win_,COLOR_PAIR(9));
    mvwprintw(win_,18,6,"%d",block.getnum());
    wattroff(win_,COLOR_PAIR(9));
  }
  else if(block.gettrait()==4){
    wattron(win_,COLOR_PAIR(6));
    mvwprintw(win_,7,12,"%d",block.getnum());
    wattroff(win_,COLOR_PAIR(6));
  }
  else if(block.gettrait()==5){
    wattron(win_,COLOR_PAIR(11));
    mvwprintw(win_,10,16,"%d",block.getnum());
    wattroff(win_,COLOR_PAIR(11));
  }
  else if(block.gettrait()==6){
    wattron(win_,COLOR_PAIR(3));
    mvwprintw(win_,15,12,"%d",block.getnum());
    wattroff(win_,COLOR_PAIR(3));
  }
  else if(block.gettrait()==7){
    wattron(win_,COLOR_PAIR(10));
    mvwprintw(win_,6,6,"%d",block.getnum());
    wattroff(win_,COLOR_PAIR(10));
  }
  wrefresh(win_);
}
