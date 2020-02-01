/******************************************************************************
*problem : 행렬덧셈                                           *
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
    cerr<<"input file openeing failed.\n";
  }
  int numtestcases;
  instream>>numtestcases;

  for(int i=0; i<numtestcases; i++){
    int row,col;
    instream>>row>>col;
    int array1[row][col];
    int array2[row][col];
    for(int k=0; k<row; k++){
      for(int l=0; l<col; l++){
        instream>>array1[k][l];
      }
    }
    for(int k=0; k<row; k++){
      for(int l=0; l<col; l++){
        instream>>array2[k][l];
      }
    }

    for(int k=0; k<row; k++){
      for(int l=0; l<col; l++){
        cout<<array1[k][l]+array2[k][l]<<" ";
      }
      cout<<endl;
    }
  }
  instream.close();
  return 0;
 }
