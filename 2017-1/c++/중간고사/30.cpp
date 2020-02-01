/******************************************************************************
*problem : 시이저암호문복호기법                                        *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/
 #include<iostream>
 #include<fstream>
 #include<string>
 #include<algorithm>
 #include<cmath>
 using namespace std;
 string change(string array,int size, int move);
 double analysis(string array,int size);
 int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail()){
    cerr<<"input file opening failed.\n";
  }
  int numtestcases;
  instream>>numtestcases;
  while(numtestcases--){
    string data;
    string tempdata;
    int n;
    instream>>data;
    n=data.length();
    double result[26] = {0,};
    for(int i=0; i<26; i++){
      tempdata=change(data, n , i);
      result[i] = analysis(tempdata,n);
    }
    double min;
    int temp1;
    for(int i=0; i<25; i++){
      if(i==0){
        min=result[i];
        temp1=i;
      }
      if(min>result[i+1]){
        min=result[i+1];
        temp1=i+1;
      }
    }
    cout<<change(data,n,temp1)<<endl;

  }
  return 0;
  instream.close();
}
string change(string array,int size, int move){
  for(int i=0; i<size; i++){
    if('A'<=array[i]&& array[i]<='Z'){
      if(array[i]+move>'Z'){
        array[i]=array[i]+move-26;
      }
      else
        array[i]=array[i]+move;
    }
    else if('a'<=array[i]&& array[i]<='z'){
      if(array[i]+move>'z'){
        array[i]=array[i]+move-26;
      }
      else
        array[i]=array[i]+move;
      }
    }
  return array;
}
double analysis(string array,int size){
  double sum=0;
  double kaisquare=0.0;
  double count[26] = {0,};
  double frequent[26] = {8.167,1.492,2.782,4.253,12.702,2.228,2.015,6.094,6.996,
   0.153,0.772,4.025,2.406,6.749,7.507,1.929,0.095,5.987,6.327,9.056,
   2.758,0.978,2.360,0.150,1.974,0.074};
  for(int i=0; i<size; i++){
    for(int k=0; k<26; k++){
      if(array[i]=='a'+k || array[i]=='A'+k)
      { count[k]++; sum++;}
    }
  }
  for(int i=0; i<26; i++){
    double temp=count[i]/sum*100;
    kaisquare+=temp*temp/frequent[i];
  }
  return kaisquare;
}
