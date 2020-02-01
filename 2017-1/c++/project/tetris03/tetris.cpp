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
  infoPane_ = new InfoPane(1,1,25,3);
  helpPane_ = new HelpPane(1,4,25,10);
  nextPane_ = new NextPane(1,14,25,8);
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
  init_pair(2, COLOR_GREEN, COLOR_BLACK);// infopane
  init_pair(3, COLOR_WHITE, COLOR_BLACK);// helppane
  init_pair(5, COLOR_BLUE, COLOR_BLACK); //보드 테두리
  init_pair(6, COLOR_RED, COLOR_BLACK); // statpane
  init_pair(7, COLOR_RED,COLOR_BLUE); // 벽돌색
  init_pair(8, COLOR_BLACK, COLOR_BLACK);
  init_pair(9, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(11, COLOR_CYAN, COLOR_BLACK);
  init_pair(10, COLOR_YELLOW, COLOR_BLACK);

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
void Tetris::updateinfopane(char *name){
  infoPane_->drawinfo(name);
}
void Tetris::updatestatpane(Block &block){
  statPane_->printnum(block);
}
void Tetris::updatenextpane(Block &block){
  nextPane_->printnextpane(block);
}
void Tetris::play(int board[][20],Block &block,int &inkey){
  switch(inkey){
    case KEY_LEFT:
    case 1:
      if(block.Checkleft(board))
        block.Moveleft(board);
      updateboardpane(board);
      break;
    case KEY_RIGHT:
    case 2:
      if(block.Checkright(board))
        block.Moveright(board);
      updateboardpane(board);
      break;
    case KEY_DOWN:
    case 3:
      if(block.Checkdown(board))
        block.Movedown(board);
      updateboardpane(board);
      break;
    case KEY_UP:
    case 5:
      if(block.Checkrotate(board))
        block.rotate(board);
      updateboardpane(board);
      break;
    case ' ':
    case 4:
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
    for(int i=0; i<10; i++){
      if(board[i][j]!=0)
        sum++;
    }
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
  statPane_->printscore(sc);
}
void Tetris::remove(int board[][20],int &row){
  for(int i=0; i<10; i++){
    board[i][row]=0;
  }
}
void Tetris::moveGravity(int board[][20],int &row){
  for(int i=0; i<10; i++){
    board[i][0]=0;
  }
  for(int i=0; i<10; i++){
    for(int j=row; j>1; j--){
      board[i][j]=board[i][j-1];
    }
  }
}
void Tetris::randomblock(Block *&gameblock, int a){
  if(a%7==0)
    gameblock = new Oblock();
  else if(a%7==1)
    gameblock = new Lblock();
  else if(a%7==2)
    gameblock = new Jblock();
  else if(a%7==3)
    gameblock = new Sblock();
  else if(a%7==4)
    gameblock = new Zblock();
  else if(a%7==5)
    gameblock = new Tblock();
  else if(a%7==6)
    gameblock = new Iblock();
}
