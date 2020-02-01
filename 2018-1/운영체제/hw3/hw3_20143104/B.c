#include "a.h"

void main(){
  /*
  struct timeval bgn,end;
  gettimeofday(&bgn, NULL);
  gettimeofdat(&end, NULL);
  //diff = end.tv_sec - bgn.tc_sec;
  int diff;*/
  pid_t pid;

  key_t semkey = 0x100;
  key_t semkey2 = 0x200;
  key_t semkey3 = 0x300;
  key_t semkey4 = 0x400;
  key_t semkey5 = 0x500;
  key_t semkey6 = 0x600;
  key_t semkey7 = 0x700;
  key_t semkey8 = 0x800;

  initLock(&lock1, semkey);
  initLock(&lock2, semkey2);
  initLock(&lock3, semkey3);
  initLock(&lock_all, semkey7);

  initCondVar(&c1, semkey4, "c1");
  initCondVar(&c2, semkey5, "c2");
  initCondVar(&c3, semkey6, "c3");
  initCondVar(&c_all, semkey8, "c_all");

  reset_resc("r1");
  reset_resc("r2");
  reset_resc("r3");

  reset_all("resc");
  int i=0;
  for(i=0; i<100; i++){
    pid = getpid();
    phil_b();
  }


  exit(0);
}
