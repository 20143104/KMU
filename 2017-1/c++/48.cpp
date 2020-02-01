/******************************************************************************
*problem : 빙고게임
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

class game{
public:
   int **array;
   int **mark;
public:
  game(){
    array = new int*[5];
    mark = new int*[5];
    for(int i=0; i<5; i++){
      array[i]= new int[5];
      mark[i]= new int[5];
    }
  }
  void setbingo(int _array[][5]){
    for(int i=0; i<5; i++){
      for(int k=0; k<5; k++){
        array[i][k]=_array[i][k];
      }
    }
    mark[2][2]=1;
  }
  void check(int s){
    for(int i=0; i<5; i++){
      for(int k=0; k<5; k++){
        if(array[i][k]==s)
          mark[i][k]=1;
      }
    }
  }
  int win(){
    for(int i=0; i<5; i++){ // 가로
      int sum=mark[i][0]+mark[i][1]+mark[i][2]+mark[i][3]+mark[i][4];
      if(sum==5)
        return 1;
    }
    for(int k=0; k<5; k++){ // 세로
      int sum=mark[0][k]+mark[1][k]+mark[2][k]+mark[3][k]+mark[4][k];
      if(sum==5)
        return 1;
    }
    int sum=0,sumreverse=0;
    for(int i=0; i<5; i++){ // 대각  반대각
      sum+=mark[i][i];
      sumreverse+=mark[5-1-i][i];
    }
    if(sum==5 || sumreverse==5)
      return 1;


    if((mark[0][0]+mark[0][4]+mark[4][0]+mark[4][4])==4)
      return 1;

    return 0;
  }
  void printmark(){
    for(int i=0; i<5; i++){
      for(int k=0; k<5; k++){
        cout<<mark[i][k]<<" ";
      }cout<<endl;
    }
  }
  void printbingo(){
    for(int i=0; i<5; i++){
      for(int k=0; k<5; k++){
        cout<<array[i][k]<<" ";
      }cout<<endl;
    }
  }

};

int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
     cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;

  while(numtestcases--){
    int array[5][5]={0,};
    for(int i=0; i<5; i++){
      for(int k=0; k<5; k++){
        instream>>array[i][k];
      }
    }
    game bingo;
    bingo.setbingo(array);
    int count=0;
    int call[75];
    for(int i=0; i<75; i++)
      instream>>call[i];
    while(1){
      bingo.check(call[count]);
      if(bingo.win())
        {break;}
      count++;
    }
    cout<<count+1<<endl;

  }
  return 0;
}
