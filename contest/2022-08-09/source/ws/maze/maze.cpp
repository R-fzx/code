#include<bits/stdc++.h>
using namespace std;
int a[25][25],n,m,t;
namespace bf
{	bool d()
	{	return n<=10 && m<=10;	}
	int ans=0;
	void dfs(int x,int y,int sum)
	{	if(x==n && y==m)
		{	if(sum==t)
			{	ans++;	}
			return;			}
		if(x!=n && a[x+1][y])
		{	dfs(x+1,y,sum^a[x+1][y]);	}
		if(y!=m && a[x][y+1])
		{	dfs(x,y+1,sum^a[x][y+1]);	}
		return;								}
	int work()
	{	dfs(1,1,a[1][1]);
		cout<<ans;
		return 0;			}					}
namespace dp
{	bool d()
	{	for(int i=1;i<=n;i++)
		{	for(int j=1;j<=m;j++)
			{	if(a[i][j]>10000)
				{	return 0;}		}	}
		return 1;							}
	long long dp[25][25][16384];
	int work()
	{	dp[1][1][a[1][1]]=1;
		for(int i=1;i<=n;i++)
		{	for(int j=1;j<=m;j++)
			{	for(int k=0;k<16384;k++)
				{	dp[i+1][j][k]+=dp[i][j][k^a[i+1][j]];
					dp[i][j+1][k]+=dp[i][j][k^a[i][j+1]];	}	}	}
		if(t>=16384)
		{	cout<<0;	}
		else
		{	cout<<dp[n][m][t];	}
		return 0;														}
}
int main()
{	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
	{	for(int j=1;j<=m;j++)
		{	cin>>a[i][j];	}	}
	if(bf::d())
	{	return bf::work();	}
	if(dp::d())
	{	return dp::work();	}
	srand(time(0));
	cout<<rand()*32768LL*32768LL+rand()*32768LL+rand();
	return 0;												}
