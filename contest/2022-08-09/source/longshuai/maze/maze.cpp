#include<bits/stdc++.h>
using namespace std;
const int maxn=20+5;
int n,m;
long long k,ans;
long long a[maxn][maxn];
void dfs(int x,int y,long long sum){
	if(x==n&&y==m){
		if(sum==k)ans++;
		return;
	}
	long long tmp=a[x][y];
	a[x][y]=0;
	if(x<n&&a[x+1][y]!=0)dfs(x+1,y,tmp^a[x+1][y]);
	if(y<m&&a[x][y+1]!=0)dfs(x,y+1,tmp^a[x][y+1]);
	a[x][y]=tmp;
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",&a[i][j]);
	dfs(1,1,a[1][1]);
	printf("%lld\n",ans);
	return 0;
}
