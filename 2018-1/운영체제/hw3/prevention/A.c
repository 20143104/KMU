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


  initLock(&lock1, semkey);
  initLock(&lock2, semkey2);
  initLock(&lock3, semkey3);

  initCondVar(&c1, semkey4, "c1");
  initCondVar(&c2, semkey5, "c2");
  initCondVar(&c3, semkey6, "c3");

  reset_resc("r1");
  reset_resc("r2");
  reset_resc("r3");

  int i=0;
  for(i=0; i<100; i++){
    pid = getpid();
    phil_a();
  }


  exit(0);
}
