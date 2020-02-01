#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#include<queue>

using namespace std;
int n;
int visit[1001];
int array[1001][1001];

void dfs(int v){
  printf("%d ", v);
  for(int i=1; i<=n; i++){
    if(array[v][i]==1 && visit[i]==0){
      visit[i]=1;
      dfs(i);
    }
  }
}
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

}
int main(){
  int m;
  int start;
  cin>>n>>m>>start;
  for(int i=0; i<m; i++){
    int p,q;
    cin>>p>>q;
    array[p][q]=1;
    array[q][p]=1;
  }
  visit[start]=1;
  dfs(start);
  printf("\n");
  bfs(start);
}
