#include<ncurses.h>
#include"main.h"

Tetris::Tetris(){
  initscr();
  start_color();
  init_color(COLOR_BLACK,0,0,0);
  cbreak();
  refresh();
  infoPane_ = new InfoPane(1,1,25,5);
  helpPane_ = new HelpPane(1,6,25,12);
  nextPane_ = new NextPane(1,18,25,5);
  boardPane_ = new BoardPane(30,0,22,22);
  statPane_ = new StatPane(60,3,20,20);
}
Tetris::~Tetris(){
  delete infoPane_;
  delete helpPane_;
  delete nextPane_;
  delete boardPane_;
  delete statPane_;
  endwin();
}
void Tetris::play(){
  int input;
  updateScreen();
  input = getch();
}
void Tetris::updateScreen(){
  infoPane_->draw();
  helpPane_->draw();
  nextPane_->draw();
  boardPane_->draw();
  statPane_->draw();
  }
