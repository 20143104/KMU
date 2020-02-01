#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#include<queue>

using namespace std;
int n;
int visit[1001];
int array[1001];

void dfs(int v){
  if(visit[v])
    return;
  visit[v]=1;
  dfs(array[v]);
}
/*
void bfs(int v){
  queue<int> q;
  for(int i=0; i<=n; i++) visit[i]=0;

  q.push(v);
  visit[v]=1;
  while(!q.empty()){
    int vector = q.front();
    q.pop();
    printf("%d ", vector);

    for(int i=1; i<=n; i++){
      if(array[vector][i]==1 && visit[i]==0){
        visit[i]=1;
        q.push(i);
      }
    }
  }
  printf("\n");

}*/
int main(){
  int numtestcases;
  int count=0;
  cin>>numtestcases;
  while(numtestcases--){
    int m;
    cin>>m;
    for(int i=1; i<=m; i++)
      cin>>array[i];

    for(int i=1; i<=m; i++){
      if(!visit[i]){
        dfs(i);
        count++;
      }
    }
    cout<<count<<'\n';
    for(int i=1; i<=1000; i++){
      array[i]=0;
      visit[i]=0;
    }
    count=0;
  }
}
