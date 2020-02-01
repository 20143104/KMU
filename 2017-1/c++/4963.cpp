#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>

using namespace std;

int visit[55][55];
int array[55][55];

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

void dfs(int x,int y){
  visit[x][y] = 1;
  for(int i=0; i<8; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(array[nx][ny]==1 && visit[nx][ny]==0)
      dfs(nx,ny);
  }
}
int main(){
  while(true){
    int a,b;
    int cnt=0;
    cin>>a>>b;
    if(a==0 && b==0)
      return 0;

    for(int i=0;i<55;i++){
      for(int k=0;k<55;k++){
        visit[i][k]=0;
        array[i][k]=0;
      }
    }
    for(int i=1; i<=b; i++){
      for(int k=1; k<=a; k++){
        cin>>array[i][k];
      }
    }
    for(int i=1; i<=b; i++){
      for(int k=1; k<=a; k++){
        if(array[i][k]==1 && visit[i][k]==0){
          dfs(i,k);
          cnt++;
        }
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}
