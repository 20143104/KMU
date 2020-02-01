#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SEMPERM 0600
#define TRUE 1
#define FALSE 0

typedef union   _semun {
             int val;
             struct semid_ds *buf;
             ushort *array;
             } semun;

int initsem (key_t semkey, int n) {
   int status = 0, semid;
   if ((semid = semget (semkey, 1, SEMPERM | IPC_CREAT | IPC_EXCL)) == -1)
   {
       if (errno == EEXIST)
                semid = semget (semkey, 1, 0);
   }
   else
   {
       semun arg;
       arg.val = n;
       status = semctl(semid, 0, SETVAL, arg);
   }
   if (semid == -1 || status == -1)
   {
       perror("initsem failed");
       return (-1);
   }
   return (semid);
}

int p (int semid) {
   struct sembuf p_buf;
   p_buf.sem_num = 0;
   p_buf.sem_op = -1;
   p_buf.sem_flg = SEM_UNDO;
   if (semop(semid, &p_buf, 1) == -1)
   {
      printf("p(semid) failed");
      exit(1);
   }
   return (0);
}

int v (int semid) {
   struct sembuf v_buf;
   v_buf.sem_num = 0;
   v_buf.sem_op = 1;
   v_buf.sem_flg = SEM_UNDO;
   if (semop(semid, &v_buf, 1) == -1)
   {
      printf("v(semid) failed");
      exit(1);
   }
   return (0);
}

// Shared variable by file
void reset(char *fileVar) {
// fileVar라는 이름의 텍스트 화일을 새로 만들고 0값을 기록한다.
  FILE *f = fopen(fileVar, "r");
  if(f==NULL){
      f = fopen(fileVar , "w");
      fprintf(f, "%d\n", 0);
  }
  fclose(f);
}

void Store(char *fileVar,int i) {
// fileVar 화일 끝에 i 값을 append한다.
  FILE *f = fopen(fileVar, "a+");
    while(!feof(f));
  fprintf(f, "%d\n", 0);
  fclose(f);
}

int Load(char *fileVar) {
// fileVar 화일의 마지막 값을 읽어 온다.
  int data;
  FILE *f = fopen(fileVar, "r");
  while(!feof(f))
    fscanf(f, "%d", &data);
  fclose(f);

  return data;
}

void add(char *fileVar,int i) {
// fileVar 화일의 마지막 값을 읽어서 i를 더한 후에 이를 끝에 append 한다.
  int data;
  pid_t pid = getpid();
  FILE *f = fopen(fileVar, "a+");
  while(!feof(f))
    fscanf(f, "%d", &data);
  fprintf(f, "%d\n", (i+data));
  fclose(f);
}

void sub(char *fileVar,int i) {
  pid_t pid = getpid();
  int data;
  FILE *f = fopen(fileVar, "a+");
  while(!feof(f))
    fscanf(f, "%d", &data);
  fprintf(f, "%d\n", (data-i));
  fclose(f);
// fileVar 화일의 마지막 값을 읽어서 i를 뺀 후에 이를 끝에 append 한다.
}

// Class Lock
typedef struct _lock {
   int semid;
} Lock;

void initLock(Lock *l, key_t semkey) {
   if ((l->semid = initsem(semkey,1)) < 0)
   // 세마포를 연결한다.(없으면 초기값을 1로 주면서 새로 만들어서 연결한다.)
      exit(1);
}

void Acquire(Lock *l) {
   p(l->semid);
}

void Release(Lock *l) {
   v(l->semid);
}

// Class CondVar
typedef struct _cond {
   int semid;
   char *queueLength;
} CondVar;

void initCondVar(CondVar *c, key_t semkey, char *queueLength) {
   c->queueLength = queueLength;
   reset(c->queueLength); // queueLength=0
   if ((c->semid = initsem(semkey,0)) < 0)
   // 세마포를 연결한다.(없으면 초기값을 0로 주면서 새로 만들어서 연결한다.)
      exit(1);
}

void Wait(CondVar *c, Lock *lock) {
  add(c->queueLength, 1);
  Release(lock);
  p(c->semid);
  Acquire(lock);
}

void Signal(CondVar *c) {
  if(Load(c->queueLength) >0){
    v(c->semid);
    sub(c->queueLength, 1);
  }
}

void Broadcast(CondVar *c) {
  while(Load(c->queueLength) > 0){
    v(c->semid);
    sub(c->queueLength,1);
  }
}



void main(int argc, char *argv[]){
  struct timeval bgn,end;
  gettimeofday(&bgn, NULL);
  int diff;
  key_t semkey = 0x200;
  key_t semkey2 = 0x100;
  key_t semkey3 = 0x300;
  int semid;
  pid_t pid;
  Lock lock;
  CondVar okToRead;
  CondVar okToWrite;

  pid = getpid();
  initLock(&lock, semkey);
  initCondVar(&okToRead, semkey2, "oktoread");
  initCondVar(&okToWrite, semkey3, "oktowrite");

  reset("AR");
  reset("AW");
  reset("WR");
  reset("WW");

  sleep(atoi(argv[1]));
  Acquire(&lock);

  while((Load("AW") + Load("AR")) > 0){
    gettimeofday(&end, NULL);
    diff = end.tv_sec - bgn.tv_sec;
    printf("process %d in writer waiting %ds\n", pid, diff);
    add("WW", 1);
    Wait(&okToWrite, &lock);
    gettimeofday(&end, NULL);
    diff = end.tv_sec - bgn.tv_sec;
    printf("process %d in writer wake up %ds\n", pid, diff);
    sub("WW",1);
  }

  gettimeofday(&end, NULL);
  diff = end.tv_sec - bgn.tv_sec;
  printf("process %d in writer %ds\n", pid, diff);
  add("AW", 1);

  Release(&lock);

  sleep(atoi(argv[2]));


  Acquire(&lock);
  gettimeofday(&end, NULL);
  diff = end.tv_sec - bgn.tv_sec;
  printf("process %d in writer exiting %ds\n", pid, diff);
  sub("AW", 1);
  if(Load("WW") > 0){
    Signal(&okToWrite);
  }
  else if(Load("WR") > 0){
    Broadcast(&okToRead);
  }
  Release(&lock);
  exit(0);

}
