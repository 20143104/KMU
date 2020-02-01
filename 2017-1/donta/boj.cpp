#include<iostream>
#include <map>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;


int main(){
  string data="";
  while(!(cin.fail())){
    string data1="";
    cin>>data1;
    cout<<data1<<endl;
  }



  long long sum=0;
  string array="";
  for(int i=0; i<data.size(); i++){
    if(data[i]==','){
      for(int k=0; k<array.size(); k++)
        sum+=(array[k]-48)*pow(10,array.size()-1-k);
      array="";
    }
    else{
      array+=data[i];
    }
  }
  for(int k=0; k<array.size(); k++)
    sum+=(array[k]-48)*pow(10,array.size()-1-k);

  return 0;
}
