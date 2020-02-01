/******************************************************************************
*problem : 짝수 마방진
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int makeplus(int i, int k){
  if(i-k>=0)
    return (i-k);
  else
    return -1*(i-k);
}
void oddmabangjin(int **array,int n){
  int row = 0;
  int col = n/2;
  int num=1;
  array[row][col]=1;
  int tempcol,temprow;
  while(num<n*n){
    tempcol=(col+1)%n;
    temprow= (row-1+n)%n;
    if(array[temprow][tempcol]==0){
      col=tempcol;
      row=temprow;
      array[row][col]=++num;
    }
    else{
      row=(row+1)%n;
      array[row][col]=++num;
    }
  }
}
void n_4(int n){
  int a=1;
  int array[50][50]={0,};
  int arraycopy[50][50]={0,};
  int arrayreverse[50][50]={0,};

  for(int i=0; i<n; i++){
    for(int k=0; k<n; k++){
      array[i][k]=a++;
      arraycopy[i][k]=array[i][k];
      arrayreverse[i][n-k-1]=array[i][k];
    }
  }

  for(int i=0; i<n; i++){
    for(int k=0; k<n; k++){
      if((makeplus(i,k)%4)==0){
        array[i][k]=n*n+1-arraycopy[i][k];
        array[i][n-k-1]=n*n+1-arrayreverse[i][k];
      }
    }
  }

  for(int i=0; i<n; i++){
    for(int k=0; k<n; k++){
      cout<<array[i][k]<<" ";
    }cout<<endl;
  }

/*  for(int i=0; i<n; i++){
    delete array[i];
    delete arraycopy[i];
    delete arrayreverse[i];
  }
  delete[] array;
  delete[] arraycopy;
  delete[] arrayreverse;*/
}
void n_2(int n){
  int **array = new int*[n];
  int **arrayhalf = new int*[n/2];
  for(int i=0; i<n; i++){
    array[i]=new int[n];
  }
  for(int i=0; i<n/2; i++){
    arrayhalf[i]=new int[n/2];
  }

  oddmabangjin(arrayhalf,n/2);

  for(int i=0; i<n/2; i++){
    for(int k=0; k<n/2; k++){
      if(i<=n/4){ //L
        array[2*i][k*2]=arrayhalf[i][k]*4;
        array[2*i][k*2+1]=arrayhalf[i][k]*4-3;
        array[2*i+1][k*2]=arrayhalf[i][k]*4-2;
        array[2*i+1][k*2+1]=arrayhalf[i][k]*4-1;
      }
      else if(i==n/4+1){ //U
        array[2*i][k*2]=arrayhalf[i][k]*4-3;
        array[2*i][k*2+1]=arrayhalf[i][k]*4;
        array[2*i+1][k*2]=arrayhalf[i][k]*4-2;
        array[2*i+1][k*2+1]=arrayhalf[i][k]*4-1;
      }
      else{ //X
        array[2*i][k*2]=arrayhalf[i][k]*4-3;
        array[2*i][k*2+1]=arrayhalf[i][k]*4;
        array[2*i+1][k*2]=arrayhalf[i][k]*4-1;
        array[2*i+1][k*2+1]=arrayhalf[i][k]*4-2;
      }
      if(i==n/4 && k==n/4){ //u
        array[2*i][k*2]=arrayhalf[i][k]*4-3;
        array[2*i][k*2+1]=arrayhalf[i][k]*4;
        array[2*i+1][k*2]=arrayhalf[i][k]*4-2;
        array[2*i+1][k*2+1]=arrayhalf[i][k]*4-1;
      }
      if(i==n/4+1 && k==n/4){ // l
        array[2*i][k*2]=arrayhalf[i][k]*4;
        array[2*i][k*2+1]=arrayhalf[i][k]*4-3;
        array[2*i+1][k*2]=arrayhalf[i][k]*4-2;
        array[2*i+1][k*2+1]=arrayhalf[i][k]*4-1;
      }
    }
  }

  for(int i=0; i<n; i++){
    for(int k=0; k<n; k++){
      cout<<array[i][k]<<" ";
    }cout<<endl;
  }

/*  for(int i=0; i<n; i++)
    delete array[i];
  for(int i=0; i<n/2; i++)
    delete arrayhalf[i];

  delete[] array;
  delete[] arrayhalf; */
}

int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
     cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;

  while(numtestcases--){
    int n;
    instream>>n;

    if(n%4==0)
      n_4(n);
    else
      n_2(n);
  }
  return 0;
}
