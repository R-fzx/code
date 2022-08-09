#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=55,M=2e4+100;
int dp[N][N][M];
int a[N][N];
int n,m,x,ans;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	}
	return x*f;
}
void dfs(int x2,int y2,int xr){
	if(x2==n&&y2==m){
		if(xr==x)ans++;
		return;
	}
	if(a[x2+1][y2]!=0){
		xr^=a[x2+1][y2];
		dfs(x2+1,y2,xr);
	}
	if(a[x2][y2+1]!=0){
		xr^=a[x2][y2+1];
		dfs(x2,y2+1,xr);
	}
}
signed main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read(),m=read(),x=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read();
//	if(n<=10&&m<=10){
//		dfs(1,1,a[1][1]);
//		printf("%lld",ans);
//		return 0;
//	}
	dp[1][1][a[1][1]]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1)continue;
			if(a[i][j]==0)continue;
			for(int k=0;k<=16384;k++){
				if(a[i-1][j]!=0)
				dp[i][j][k]+=dp[i-1][j][k^a[i][j]];
				if(a[i][j-1]!=0)
				dp[i][j][k]+=dp[i][j-1][k^a[i][j]];
			}
		}
	}
	printf("%lld",dp[n][m][x]);
	return 0;
}
/*
3 3 1
1 1 5
2 3 1
0 4 5
*/
