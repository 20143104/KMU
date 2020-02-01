/******************************************************************************
*problem : 해밍코드                                       *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

void convert1(int array[33]){
  int count1=0,count2=0,count4=0,count8=0,count16=0;
  for(int i=1; i<=16; i++){
    int k=2*i-1;
    if(array[k]==1) count1++;
  }
  for(int i=1; i<=8; i++){
    int k=4*i-2;
    if(array[k]==1) count2++;
    if(array[k+1]==1) count2++;
  }
  for(int i=1; i<=4; i++){
    int k=8*i-4;
    for(int j=0; j<4; j++){
      if(array[k++]==1) count4++;
    }
  }
  for(int i=1; i<=2; i++){
    int k=16*i-8;
    for(int j=0; j<8; j++){
      if(array[k++]==1) count8++;
    }
  }
  for(int i=16; i<=31; i++){
    if(array[i]==1) count16++;
  }
  if(count1%2==1)
    array[1]=1;
  if(count2%2==1)
    array[2]=1;
  if(count4%2==1)
    array[4]=1;
  if(count8%2==1)
    array[8]=1;
  if(count16%2==1)
    array[16]=1;
}
int check(int array[33]){
  int sum=0;
  int count1=0,count2=0,count4=0,count8=0,count16=0;
  for(int i=1; i<=16; i++){
    int k=2*i-1;
    if(array[k]==1) count1++;
  }
  for(int i=1; i<=8; i++){
    int k=4*i-2;
    if(array[k]==1) count2++;
    if(array[k+1]==1) count2++;
  }
  for(int i=1; i<=4; i++){
    int k=8*i-4;
    for(int j=0; j<4; j++){
      if(array[k++]==1) count4++;
    }
  }
  for(int i=1; i<=2; i++){
    int k=16*i-8;
    for(int j=0; j<8; j++){
      if(array[k++]==1) count8++;
    }
  }
  for(int i=16; i<=31; i++){
    if(array[i]==1) count16++;
  }

  if(count1%2==1)
    sum+=1;
  if(count2%2==1)
    sum+=2;
  if(count4%2==1)
    sum+=4;
  if(count8%2==1)
    sum+=8;
  if(count16%2==1)
    sum+=16;

  return sum;
}
void change(int array[33], int k){
  if(array[k]==0)
    array[k]=1;
  else
    array[k]=0;
}
int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail())
    cerr<<"input file opening failed.\n";

  int numtestcases;
  instream>>numtestcases;
  while(numtestcases--){
    int k,data;
    instream>>k>>data;
    int array[33]={0,};
    int i=1;

    if(k==0){
      while(data!=0 && i<33){
        if(i==1 || i==2 || i==4 || i==8 || i==16){
          i++; continue;
        }
        array[i++]=data%2;
        data/=2;
      }
      int sum=0;
      convert1(array);
      for(int k=32; k>=1; k--){
        sum+=array[k]*pow(2,(k-1));
      }
      cout<<sum<<endl;
    }
    else{
      while(data!=0 && i<33){
        array[i++]=data%2;
        data/=2;
      }
      int sum=0;
      int checknum = check(array);
      if(checknum)
        {change(array, checknum);}
      for(int k=32; k>=1; k--){
        if(k==1 || k==2 || k==4 || k==8 || k==16){continue;}
        int num=sqrt(k);
        if(k>16)
          num=4;
        sum+=array[k]*pow(2,(k-2-num));
      }
      cout<<sum<<endl;
    }
  }
}
