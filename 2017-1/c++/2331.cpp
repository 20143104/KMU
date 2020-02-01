#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>

using namespace std;
int array[1000000];
int A,P;
int ans=1;


int main(){
  cin>>A>>P;
  while(array[A]==0){
    array[A]=ans++;
    int s=0;
    for(int i=A; i; i/=10) s+= pow(i%10,P);
    A=s;
  }

  cout<<array[A]-1<<endl;

}
