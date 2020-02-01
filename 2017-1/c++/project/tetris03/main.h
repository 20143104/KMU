#include <ncursesw/curses.h>
#include <locale.h>
#include<time.h>
#include<ncurses.h>
#include<fstream>
#include <stdio.h>
#include<iostream>
#include <unistd.h>
#include<cstdlib>
class Score{
private:
  int score;
  int level;
  int numblock;
public:
  Score();
  int getScore();
  void upScore();
  void setLevel();
  int getLevel();
  void setNumblock();
  int getNumblock();
};

class Block{
protected:
  int x1,x2,x3,x4,y1,y2,y3,y4;
  int state,trait;
public:
  virtual void createblock(int board[][20]){}
  virtual void Movedown(int board[][20]){}
  virtual bool Checkdown(int board[][20]){}
  virtual void Moveleft(int board[][20]){}
  virtual bool Checkleft(int board[][20]){}
  virtual void Moveright(int board[][20]){}
  virtual bool Checkright(int board[][20]){}
  virtual void rotate(int board[][20]){}
  virtual bool Checkrotate(int board[][20]){}
  virtual bool isGameover(int board[][20]){}
  virtual int getx1(){ return x1;}
  virtual int getx2(){ return x2;}
  virtual int getx3(){ return x3;}
  virtual int getx4(){ return x4;}
  virtual int gety1(){ return y1;}
  virtual int gety2(){ return y2;}
  virtual int gety3(){ return y3;}
  virtual int gety4(){ return y4;}
  virtual int gettrait() {return trait;}
  virtual int getnum() {}
};
class Lblock : public Block{
private:
  static int num;
public:
  Lblock();
  virtual void createblock(int board[][20]);
  virtual void Movedown(int board[][20]);
  virtual bool Checkdown(int board[][20]);
  virtual void Moveleft(int board[][20]);
  virtual bool Checkleft(int board[][20]);
  virtual void Moveright(int board[][20]);
  virtual bool Checkright(int board[][20]);
  virtual bool isGameover(int board[][20]);
  virtual bool Checkrotate(int board[][20]);
  virtual void rotate(int board[][20]);
  virtual int getnum() {return num;}
};
class Oblock : public Block{
private:
  static int num;
public:
  Oblock();
  virtual void createblock(int board[][20]);
  virtual void Movedown(int board[][20]);
  virtual bool Checkdown(int board[][20]);
  virtual void Moveleft(int board[][20]);
  virtual bool Checkleft(int board[][20]);
  virtual void Moveright(int board[][20]);
  virtual bool Checkright(int board[][20]);
  virtual bool isGameover(int board[][20]);
  virtual int getnum() {return num;}
};
class Jblock : public Block{
private:
  static int num;
public:
  Jblock();
  virtual void createblock(int board[][20]);
  virtual void Movedown(int board[][20]);
  virtual bool Checkdown(int board[][20]);
  virtual void Moveleft(int board[][20]);
  virtual bool Checkleft(int board[][20]);
  virtual void Moveright(int board[][20]);
  virtual bool Checkright(int board[][20]);
  virtual bool Checkrotate(int board[][20]);
  virtual void rotate(int board[][20]);
  virtual bool isGameover(int board[][20]);
  virtual int getnum() {return num;}
};
class Sblock : public Block{
private:
  static int num;
public:
  Sblock();
  virtual void createblock(int board[][20]);
  virtual void Movedown(int board[][20]);
  virtual bool Checkdown(int board[][20]);
  virtual void Moveleft(int board[][20]);
  virtual bool Checkleft(int board[][20]);
  virtual void Moveright(int board[][20]);
  virtual bool Checkright(int board[][20]);
  virtual bool isGameover(int board[][20]);
  virtual bool Checkrotate(int board[][20]);
  virtual void rotate(int board[][20]);
  virtual int getnum() {return num;}
};
class Zblock : public Block{
private:
  static int num;
public:
  Zblock();
  virtual void createblock(int board[][20]);
  virtual void Movedown(int board[][20]);
  virtual bool Checkdown(int board[][20]);
  virtual void Moveleft(int board[][20]);
  virtual bool Checkleft(int board[][20]);
  virtual void Moveright(int board[][20]);
  virtual bool Checkright(int board[][20]);
  virtual bool isGameover(int board[][20]);
  virtual void rotate(int board[][20]);
  virtual bool Checkrotate(int board[][20]);
  virtual int getnum() {return num;}
};
class Tblock : public Block{
private:
  static int num;
public:
  Tblock();
  virtual void createblock(int board[][20]);
  virtual void Movedown(int board[][20]);
  virtual bool Checkdown(int board[][20]);
  virtual void Moveleft(int board[][20]);
  virtual bool Checkleft(int board[][20]);
  virtual void Moveright(int board[][20]);
  virtual bool Checkright(int board[][20]);
  virtual bool isGameover(int board[][20]);
  virtual bool Checkrotate(int board[][20]);
  virtual void rotate(int board[][20]);
  virtual int getnum() {return num;}
};
class Iblock : public Block{
private:
  static int num;
public:
  Iblock();
  virtual void createblock(int board[][20]);
  virtual void Movedown(int board[][20]);
  virtual bool Checkdown(int board[][20]);
  virtual void Moveleft(int board[][20]);
  virtual bool Checkleft(int board[][20]);
  virtual void Moveright(int board[][20]);
  virtual bool Checkright(int board[][20]);
  virtual bool isGameover(int board[][20]);
  virtual void rotate(int board[][20]);
  virtual bool Checkrotate(int board[][20]);
  virtual int getnum() {return num;}
};

class Pane {
protected :
  int width_, height_;
  int x_, y_;
  WINDOW *win_;
public:
  Pane(int x, int y, int w, int h);
  virtual ~Pane();
  virtual void draw();
  virtual void printscore(Score &sc){}
  virtual void printframe(int board[][20]){}
  virtual void drawinfo(char *name){}
  virtual void printnextpane(Block &block){}
  virtual void printEnd(Score &sc){}
  virtual void printnum(Block &block){}
};
class InfoPane : public Pane {
  public:
  InfoPane(int x, int y, int w, int h);
  void draw();
  void drawinfo(char *name);
};
class HelpPane : public Pane{
public:
  HelpPane(int x,int y,int w,int h);
  void draw();
};
class NextPane : public Pane{
public:
  NextPane(int x,int y,int w,int h);
  void draw();
  void printnextpane(Block &block);
};
class BoardPane : public Pane {
  public:
    BoardPane(int x, int y, int w, int h);
    void draw();
    void printframe(int board[][20]);
    void printEnd(Score &sc);
};
class StatPane : public Pane {
  public:
    StatPane(int x, int y, int w, int h);
    void draw();
    void printscore(Score &sc);
    void printnum(Block &block);
};
class Tetris {
  Pane *infoPane_, *helpPane_, *nextPane_, *boardPane_, *statPane_;
  public:
    Tetris();
    ~Tetris();
    void play(int board[][20],Block &block,int &inkey);
    void updateScreen();
    void updateboardpane(int board[][20]);
    void updatenextpane(Block &block);
    void updateinfopane(char *name);
    void updatestatpane(Block &block);
    void incolor();
    void printEnd(Score &sc);
    void isFullline(int board[][20],Score &sc);
    void remove(int board[][20],int &row);
    void moveGravity(int board[][20], int &row);
    void randomblock(Block*& gameblock, int a);
  };
