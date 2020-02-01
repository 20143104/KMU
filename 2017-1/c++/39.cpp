/******************************************************************************
*problem : 국제표준도서번호                                  *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;


int isnum(string data,int &l){
  int country=0,publish=0,book=0,hypen=0,checksum=0;
  if(l>13)  return 0;
  for(int i=0; i<l; i++){
    if(i<l-1){
      if(!(('0'<=data[i] && data[i]<='9') || data[i]=='-'))
        return 0;
    }
    if(data[i]=='-')
      hypen++;
    if('0'<=data[i]&& data[i]<='9' && hypen==0)
      country++;
    if('0'<=data[i]&& data[i]<='9' && hypen==1)
      publish++;
    if('0'<=data[i]&& data[i]<='9' && hypen==2)
      book++;
    if(('0'<=data[i]&& data[i]<='9' && hypen==3) || (data[i]=='X' && hypen==3))
      checksum++;
    }
  if(country==0 || publish==0 || book==0 || checksum!=1)
    return 0;
  if(country>5 || publish>7 || book>6)
    return 0;
  if(!(hypen ==3))
    return 0;

  char array[9]={'\0',};
  int count=0,num=0;
  while(num<9){
    if('0'<=data[count]&& data[count]<='9'){
      array[num]=data[count];
      num++;
      count++;
    }
    else
      count++;
  }

  int sum=0;
  int k=10;
  for(int i=0; i<9; i++){
    //cout<<(array[i]-48);
    sum+=(array[i]-48)*k--;
  }
  int i=0;
  for(; 11*i<sum; i++);
  i*=11;
  sum=i-sum;
  if(sum!=10){
    char final = sum+48;
    if(data[l-1]!=final)
      {return 0;}
  }
  else{
    if(data[l-1]!='X')
      {return 0;}
  }

  return 1;
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
     int len=data.size();
     cout<<isnum(data, len)<<endl;
   }
   return 0;
 }
