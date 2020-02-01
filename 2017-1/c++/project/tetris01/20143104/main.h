#include<ncurses.h>
class Pane {
protected :
  int width_, height_;
  int x_, y_;
  WINDOW *win_;
public:
  Pane(int x, int y, int w, int h);
  virtual ~Pane();
  virtual void draw();
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
};
class StatPane : public Pane {
  public:
    StatPane(int x, int y, int w, int h);
    void draw();
};
class Tetris {
  Pane *infoPane_, *helpPane_, *nextPane_, *boardPane_, *statPane_;
  public:
    Tetris();
    ~Tetris();
    void play();
    void updateScreen();
    };
