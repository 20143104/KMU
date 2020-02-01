/******************************************************************************
*problem : 이동평균                                           *
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
    int numdata;
    int T;
    int terms=0;
    int result;
    instream>>numdata;

    int array[256];

    for(int k=0; k<numdata; k++){
      instream>>array[k];
      }

      instream>>T;

      cout<<numdata-T+1<<" ";

      for(int k=0; k<(numdata-T+1); k++){
        int sum=0;
        for(int l=terms; l<(T+terms); l++){
          sum+=array[l];
          }
        terms++;
        result=sum/T;
        cout<<result<<" ";
        }
      cout<<endl;
      
   }
  instream.close();
  return 0;
}
