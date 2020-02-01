#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#include<queue>

using namespace std;
int visit[20001];
vector <int>array[20001];
int v,e;


bool bfs(int start){
  queue<int> q;
  q.push(start);
  visit[start]=1;
  while(!q.empty()){
    int cur = q.front();
    q.pop();

    for(int i=0; i<array[cur].size(); i++){
      int next = array[cur][i];
      if(visit[next]==0){
        visit[next]=-visit[cur];
        q.push(next);
      }
      else{
        if(visit[next]==visit[cur])
          return false;
      }
    }
  }
  return true;
}
int main(){
  int numtestcases;
  cin>>numtestcases;
  while(numtestcases--){
    cin>>v>>e;
    bool result = true;
    for(int i=1; i<=v; i++){
      array[i].clear();
      visit[i]=0;
    }
    for(int i=0; i<e; i++){
      int p,q;
      cin>>p>>q;
      array[p].push_back(q);
      array[q].push_back(p);
    }
    for(int i=1; i<=v; i++){
      if(visit[i]==0)
        result = result && bfs(i);
    }
    if(result == true)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
