#include<bits/stdc++.h>
using namespace std;
const int N=22;
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
int a[N][N];
int n,m,k;
int dfs(int x,int y,int s){
	if(x>n||y>m) return 0;
	if(!a[x][y]) return 0;
	int ss=s^a[x][y];
	if(x==n&&y==m&&ss==k) return 1;
	return dfs(x+1,y,ss)+dfs(x,y+1,ss);
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read();
	cout<<dfs(1,1,0)<<endl;
	return 0;
}
