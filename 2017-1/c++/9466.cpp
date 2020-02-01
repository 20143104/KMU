#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>

using namespace std;
int visit[100001];
int check[100001];
int array[100001];
int V;

int bfs(int start){
  if(visit[start]!=0)
    return start;
  visit[start]=1;
  return bfs(array[start]);
}

int main(){
  int numtestcases;
  cin>>numtestcases;
  while(numtestcases--){
    for(int i=0; i<100001; i++)
      array[i] = check[i] = visit[i] =0;
    cin>>V;
    for(int i=1; i<=V; i++)
      cin>>array[i];

    int cnt=0;
    for(int i=1; i<=V; i++){
      if(visit[i]==0 || check[i]==0){
        if(bfs(i)==i){
          check[i]=1;
          cnt++;
        }
      }
    }

    cout<<V-cnt<<endl;
  }


}
