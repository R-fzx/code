#include<bits/stdc++.h>

using namespace std;
int n,m,k,b[22][22];
unordered_map<int,long long>mp[22][22];
struct E{
  int x,y,w,_x,_y;
};
inline void bfs(){
  queue<E>q;
  q.push({1,1,0,1,1});
  mp[1][1][0]=1;
  while(!q.empty()){
    E cur(q.front());
    q.pop();
    bool fl(mp[cur.x][cur.y].count(cur.w^b[cur.x][cur.y]));
    mp[cur.x][cur.y][(cur.w^b[cur.x][cur.y])]+=mp[cur._x][cur._y][cur.w];
    if(fl)continue;
    cur.w^=b[cur.x][cur.y];
    cur._x=cur.x;
    cur._y=cur.y;
    if(b[cur.x+1][cur.y]){
      cur.x++;
      q.push(cur);
      cur.x--;
    }
    if(b[cur.x][cur.y+1]){
      cur.y++;
      q.push(cur);
    }
  }
}
inline int read(){
  int r(0);char ch(getchar());
  while(ch<'0'||ch>'9')ch=getchar();
  while(ch>='0'&&ch<='9')r=(r<<1)+(r<<3)+ch-'0',ch=getchar();
  return r;
}

int main(){
  freopen("maze.in","r",stdin),freopen("maze.out","w",stdout);
  n=read(),m=read(),k=read();
  for(int i(1);i<=n;i++){
    for(int j(1);j<=m;j++){
      b[i][j]=read();
    }
  }
  bfs();
  cout<<mp[n][m][k];
  return 0;
}