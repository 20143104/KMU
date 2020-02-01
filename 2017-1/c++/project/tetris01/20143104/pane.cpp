#include<ncurses.h>
#include"main.h"

Pane::Pane(int x, int y, int w, int h) :x_(x), y_(y), width_(w), height_(h){
  win_ = newwin(h, w, y, x);
}
Pane::~Pane(){
  delwin(win_);
}
void Pane::draw(){
  box(win_, 0, 0);
  wrefresh(win_);
}
