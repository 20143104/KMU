#include <ncursesw/curses.h>
#include <locale.h>
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
private:
  int x1,x2,x3,x4,y1,y2,y3,y4;
public:
  void Oblock(int board[][20]);
  void Movedown(int board[][20]);
  bool Checkdown(int board[][20]);
  void Moveleft(int board[][20]);
  bool Checkleft(int board[][20]);
  void Moveright(int board[][20]);
  bool Checkright(int board[][20]);
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
  virtual void drawscore(Score &sc){}
  virtual void printframe(int board[][20]){}
  virtual void printEnd(Score &sc){}
};
class InfoPane : public Pane {
  public:
  InfoPane(int x, int y, int w, int h);
  void draw();
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
    void drawscore(Score &sc);
};
class Tetris {
  Pane *infoPane_, *helpPane_, *nextPane_, *boardPane_, *statPane_;
  public:
    Tetris();
    ~Tetris();
    void play(int board[][20],Block &block,int &inkey);
    void updateScreen();
    void updateboardpane(int board[][20]);
    void incolor();
    void printEnd(Score &sc);
    void isFullline(int board[][20],Score &sc);
    void remove(int board[][20],int &row);
    void moveGravity(int board[][20], int &row);
    bool isGameover(int board[][20]);
  };
