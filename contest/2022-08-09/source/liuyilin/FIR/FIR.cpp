#include<bits/stdc++.h>
using namespace std;
const int w=1000,W=1005;
int s[W][W];
inline int read(){
	int r=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r;
}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool vis[W][W];
bool ck(int x,int y){
	for(int i=0;i<4;i++)
		if(!s[x+dx[i]][y+dy[i]]) return 0;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(s[xx][yy]==s[x][y]&&!vis[xx][yy]){
			if(!ck(xx,yy)){
				vis[x][y]=0;
				return 0;
			}
		}
	}
	vis[x][y]=0;
	return 1;
}
void fl(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(s[xx][yy]==s[x][y]&&!vis[xx][yy]){
			fl(xx,yy);
		}
	}
	s[x][y]=0;
	vis[x][y]=0;
	return;
}
int n,k;
int mx[4]={1,1,0,-1};
int my[4]={0,1,1,1};
bool wn(int x,int y){
	int l1,l2,xx,yy;
	for(int i=0;i<4;i++){
		xx=x;yy=y;
		for(l1=0;xx>0&&xx<=w&&yy>0&&yy<=w&&s[xx][yy]==s[x][y];l1++){
			xx+=mx[i];yy+=my[i];
		}
		xx=x;yy=y;
		for(l2=0;xx>0&&xx<=w&&yy>0&&yy<=w&&s[xx][yy]==s[x][y];l2++){
			xx-=mx[i];yy-=my[i];
		}
//		cout<<l1+l2-1<<endl;
		if(l1+l2-1>=k) return 1;
	}
	return 0;
}
inline int typ(int stp){
	return stp&1?1:2;
}
int main(){
	freopen("FIR.in","r",stdin);
	freopen("FIR.out","w",stdout);
	n=read();k=read();
	int x,y;
	for(int i=1;i<=n;i++){
		x=read();y=read();
		if(s[x][y]){
			cout<<"illegal"<<endl;
			return 0;
		}
		s[x][y]=typ(i);
		int xx,yy;
		for(int k=0;k<4;k++){
			xx=x+dx[k];yy=y+dy[k];
			if(s[xx][yy]!=typ(i)&&ck(xx,yy))
				fl(xx,yy);
		}
		if(ck(x,y)){
			cout<<"illegal"<<endl;
			return 0;
		}
		if(wn(x,y)){
			if(i&1) cout<<"ITer ";
			else cout<<"Kitty ";
			cout<<i<<endl;
			return 0;
		}
//		for(int i=1;i<=10;i++){
//			for(int j=1;j<=10;j++)
//				cout<<s[i][j];
//			cout<<endl;
//		}
//		cout<<endl<<endl;
	}
	cout<<"draw"<<endl;
	return 0;
}
