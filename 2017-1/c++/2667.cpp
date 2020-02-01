#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>

using namespace std;

int visit[30][30];
int array[30][30];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int dfs(int x,int y,int cnt){
  if(visit[x][y]>0)
   return cnt-1;
  visit[x][y] = cnt;
  for(int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(array[nx][ny]==1)
      cnt = dfs(nx,ny,++cnt);
  }
  return cnt;
}
int main(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++){
    for(int k=1; k<=n; k++){
      scanf("%1d", &array[i][k]);
    }
  }
  vector<int> v;
  for(int i=1; i<=n; i++){
    for(int k=1; k<=n; k++){
      if(array[i][k]==1 && visit[i][k]==0){
        int cnt = dfs(i,k,1);
        v.push_back(cnt);
      }
    }
  }
  cout<<v.size()<<endl;
  sort(v.begin(),v.end());
  for(int i=0; i<v.size(); i++)
    cout<<v[i]<<endl;
}
