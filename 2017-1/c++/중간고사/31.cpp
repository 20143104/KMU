/******************************************************************************
*problem : 시이저암호기법                                        *
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
 string print(string array,int size, int move);
 int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail()){
    cerr<<"input file opening failed.\n";
  }
  int numtestcases;
  instream>>numtestcases;
  while(numtestcases--){
   int m;
   string data;
   instream>>m;
   instream>>data;
   int n;
   n=data.length();
   cout<<print(data,n,m)<<endl;
   }
   return 0;
   instream.close();
}
string print(string array,int size, int move){
  for(int i=0; i<size; i++){
    if('A'<=array[i]&& array[i]<='Z'){
      if(array[i]+move>'Z'){
        array[i]=array[i]+(move-26);
      }
      else
        array[i]=array[i]+move;
    }
    else if('a'<=array[i]&& array[i]<='z'){
      if(array[i]+move>'z'){
        array[i]=array[i]+(move-26);
      }
      else
        array[i]=array[i]+move;
    }
  }
  return array;
}
