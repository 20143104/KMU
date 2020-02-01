#include"main.h"

Score::Score():score(0),level(1),numblock(0){}

int Score::getScore(){
  return score;
}
void Score::upScore(){
  score+=2;
}
void Score::setLevel(){
  level = score/50+1;
}
int Score::getLevel(){
  return level;
}
void Score::setNumblock(){
  numblock=score/2*10;
}
int Score::getNumblock(){
  return numblock;
}
