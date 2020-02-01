#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include <stdio.h>

using namespace std;

#define mod 1000000

int getmax(int a, int b){
  return a>b? a:b;
}

int main(){
  char data[5001];
  int size;
  int dp[5001]={};
  dp[0]= 1;
  dp[1]= 1;
  string s;
  scanf("%s", data);
  s = data;
  size = s.size();

  for(int i=2; i<=size; i++){
    int n = i-1;
    if(data[n]>'0')
      dp[i] = dp[i-1]%mod;

    int m = (data[n-1]-'0')*10 +data[n]-'0';

    if(10<=m && m<=26)
      dp[i] = (dp[i]+dp[i-2])%mod;
  }

  printf("%d\n",dp[size]);
}
