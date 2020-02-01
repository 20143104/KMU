/******************************************************************************
*problem : 소인수분해                                           *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/

#include<iostream>
#include<fstream>

using namespace std;

int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail()){
    cerr<<"input file opening failed.\n";
  }
  int numtestcases;
  instream>>numtestcases;

  for(int i=0; i<numtestcases; i++){
    int data;
    int terms=0;
    int checknum=0;
    int countnum=1;
    instream >> data;
    int array[32]={0,};
    int count[32]={0,};
    int array1[32]={0,};
    for(int k=2; k<=data; k++){
      if(data%k==0){
        while(data%k==0){
          array[terms]=k;
          terms++;
          data/=k;
        }
      }
    }
    ///////array 배열에는 data에 해당하는 소인수들이 저장되어 있다.
    for(int k=0; k<terms; k++){
      if(array[k]==array[k+1]){
        countnum++;
      }
      else{
        array1[checknum]=array[k];
        count[checknum]=countnum;
        checknum++;
        countnum=1;
      }
    }

    cout<<checknum<<" ";
    for(int k=0; k<checknum; k++){
      cout<<array1[k]<<" " <<count[k]<<" ";
    }
    cout<<endl;

  }
  instream.close();
  return 0;
}
