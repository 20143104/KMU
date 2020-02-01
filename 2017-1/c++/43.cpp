/******************************************************************************
*problem : 모르스부호                                      *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<stack>
using namespace std;
void morth(string data){
  string mor[] = { ".-", "-...", "-.-.", "-..", ".", "..-.","--.", "....", "..",
   ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",".-.", "...", "-",
    "..-", "...-", ".--", "-..-","-.--", "--.." };


  int len=data.size();
  char alpha = 'A';
  string str="";

  for(int i=0; i<len; i++){
    if(data[i]=='#'){
      for(int k=0; k<26; k++){
        if(str==mor[k])
          {cout<<char(alpha+k);}
      }
      str="";
      cout<<"_";
    }
    else if(data[i]=='|'){
      for(int k=0; k<26; k++){
        if(str==mor[k])
          {cout<<char(alpha+k);}
      }
      str="";
    }
    else
      {str+=data[i];}
  }
  for(int k=0; k<26; k++){
    if(str==mor[k])
      {cout<<char(alpha+k);}
  }
  cout<<endl;

}
int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
     cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;


  while(numtestcases--){
    string data;
    instream>>data;
    morth(data);
  }
    return 0;
}
