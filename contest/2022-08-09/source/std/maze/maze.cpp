#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<int,long long> mp[22];
int n,m,x,a[22][22];
long long ans;
void dfs(int i,int j,int sum)
{
	if (!a[i][j]) return;
	if (i+j==n+1)
	{
		mp[i][sum]++;
		return;
	}
	if (i<n) dfs(i+1,j,sum^a[i+1][j]);
	if (j<m) dfs(i,j+1,sum^a[i][j+1]);
}
void getans(int i,int j,int sum)
{
	if (!a[i][j]) return;
	if (i+j==n+1)
	{
		ans+=mp[i][x^sum^a[i][j]];
		return;
	}
	if (i>1) getans(i-1,j,sum^a[i-1][j]);
	if (j>1) getans(i,j-1,sum^a[i][j-1]);
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d%d%d",&n,&m,&x);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	dfs(1,1,a[1][1]);
	getans(n,m,a[n][m]);
	printf("%lld\n",ans);
	return 0;
} 
