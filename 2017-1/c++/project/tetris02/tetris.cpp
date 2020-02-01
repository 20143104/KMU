#include"main.h"

Tetris::Tetris(){
  setlocale(LC_CTYPE, "ko_KR.utf-8"); /* 로케일 설정을 했는데도 */
  initscr();
  start_color();
  init_color(COLOR_BLACK,0,0,0);
  curs_set(0);
  keypad(stdscr,true);
  noecho();
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
void Tetris::incolor(){
  init_pair(1, COLOR_BLUE, COLOR_BLUE); //벽돌아닌색
  init_pair(5, COLOR_BLUE, COLOR_BLACK); //보드 테두리
  init_pair(3, COLOR_WHITE, COLOR_BLACK);// helppane
  init_pair(2, COLOR_GREEN, COLOR_BLACK);// infopane
  init_pair(6, COLOR_RED, COLOR_BLACK); // statpane
  init_pair(7, COLOR_RED,COLOR_BLUE); // 벽돌색
  init_pair(4, COLOR_CYAN,COLOR_BLUE); // 벽돌색
}
void Tetris::updateScreen(){
  incolor();
  infoPane_->draw();
  helpPane_->draw();
  nextPane_->draw();
  boardPane_->draw();
  statPane_->draw();
}
void Tetris::updateboardpane(int board[][20]){
  incolor();
  boardPane_->printframe(board);
}
void Tetris::printEnd(Score &sc){
  boardPane_->printEnd(sc);
}
void Tetris::play(int board[][20],Block &block,int &inkey){
  updateboardpane(board);
  switch(inkey){
    case 1:
    case KEY_LEFT:
      if(block.Checkleft(board))
        block.Moveleft(board);
      updateboardpane(board);
      break;
    case 2:
    case KEY_RIGHT:
      if(block.Checkright(board))
        block.Moveright(board);
      updateboardpane(board);
      break;
    case KEY_UP:
      break;
    case 3:
    case KEY_DOWN:
      if(block.Checkdown(board))
        block.Movedown(board);
      updateboardpane(board);
      break;
    case 4:
    case ' ':
      while(block.Checkdown(board)){
        block.Movedown(board);
      }
      updateboardpane(board);
      break;
  }
}
void Tetris::isFullline(int board[10][20],Score &sc){
  int count=0;
  for(int j=0; j<20; j++){
    int sum=0;
    for(int i=0; i<10; i++)
      sum+=board[i][j];
    if(sum==10){
      count++;
      remove(board,j);
      moveGravity(board,j);
    }
  }
  for(int i=0; i<count; i++)
    sc.upScore();
  sc.setLevel();
  sc.setNumblock();
  statPane_->drawscore(sc);
}
void Tetris::remove(int board[][20],int &row){
  for(int i=0; i<10; i++){
    board[i][row]=0;
  }
}
void Tetris::moveGravity(int board[][20],int &row){
  int tempx,tempy;
  for(int i=0; i<10; i++){
    board[i][0]=0;
  }
  for(int i=0; i<10; i++){
    for(int j=row; j>1; j--){
      board[i][j]=board[i][j-1];
    }
  }
}
bool Tetris::isGameover(int board[][20]){
  if(board[4][1]==1 || board[5][1]==1)
    return true;
  else
    return false;
}
