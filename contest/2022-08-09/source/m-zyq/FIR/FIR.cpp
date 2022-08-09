#include<bits/stdc++.h>

using namespace std;
int n,p,b[1009][1009],tx[8]={0,0,1,-1,1,-1,1,-1},ty[8]={1,-1,0,0,1,-1,-1,1};
inline int read(){
  int r(0);char ch(getchar());
  while(ch<'0'||ch>'9')ch=getchar();
  while(ch>='0'&&ch<='9')r=(r<<1)+(r<<3)+ch-'0',ch=getchar();
  return r;
}
inline bool check(int x,int y,int color){
  if(!b[x][y])return true;
  for(int i(0);i<4;i++){
    int nx(tx[i]+x),ny(ty[i]+y);
    if(nx<=0||ny<=0||(b[nx][ny]&&b[nx][ny]!=color))continue;
    if(check(nx,ny,color))return true;
  }
  return false;
}
inline void del(int x,int y,int color){
  b[x][y]=0;
  for(int i(0);i<4;i++){
    int nx(tx[i]+x),ny(ty[i]+y);
    if(nx<=0||ny<=0||(b[nx][ny]!=color))continue;
    del(nx,ny,color);
  }
}
inline bool win(int x,int y,int color){
  for(int i(0);i<4;i++){
    int j(i<<1),k(j+1),cnt(1);
    for(int u(x+tx[j]),v(y+ty[j]);b[u][v]==color&&cnt<p;u+=tx[j],v+=ty[j])cnt++;
    for(int u(x+tx[k]),v(y+ty[k]);b[u][v]==color&&cnt<p;u+=tx[k],v+=ty[k])cnt++;
    if(cnt>=p)return true;
  }
  return false;
}
int main(){
  freopen("FIR.in","r",stdin),freopen("FIR.out","w",stdout);
  cin>>n>>p;
  int color(2),_n(n);
  while(n--){//1 ITer 2 Kitty (_n-n)
    int x(read()),y(read());
    if(b[x][y]){
      puts("illegal");
      return 0;
    }
    int _color(color);
    color=(color==1?2:1);
    b[x][y]=color;
    for(int i(0);i<4;i++){
      int nx(x+tx[i]),ny(y+ty[i]);
      if(b[nx][ny]!=_color)continue;
      if(!check(nx,ny,_color))del(nx,ny,_color);
    }
    if(!check(x,y,color)){
      puts("illegal");
      return 0;
    }  
    if(win(x,y,color)){
      if(color==1){
        cout<<"ITer "<<_n-n;
      }else{
        cout<<"Kitty "<<_n-n;
      }
      return 0;
    }
    
  }
  puts("draw");
  return 0;
}
/*
20 5 2 3 3 3 3 2 2 2 4 3 2 4 5 3 1 3 3 4 5 5 2 3 3 3 2 3 2 5 6 3 1 5 3 3 1 5 1 5 1 5
*/