#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int result(string &r, string &s){
  string array[100];
  int pos=0;
  string str="";
  for(int i=0; i<s.size(); i++){
    if('a'<s[i] && s[i]<'z')
      str+=s[i];
    else{
      if(str!=""){
        array[pos++]=str;
        str="";
      }
    }
  }
  if(str!="")
    array[pos++]=str;
  for(int i=0; i<pos; i++)
    cout<<array[i]<<" ";

  for(int i=0; i<pos; i++){
    if(array[i]==)
  }

}






int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
    cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;

  while(numtestcases--){
    string r,s;
    instream>>r>>s;
    result(r,s);
  }
  return 0;
}
