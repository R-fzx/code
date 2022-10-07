#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int m,k;
bool a[3000],vis[3000];
inline int get(int s)
{
	int res(0);
	int now = 1<<(k-1);
	for(int i = s,j = 1;j <= k;i++,j++)
	{
		if(i > m) i = 1;
		res += now*a[i];
		now >>= 1;
	}
	return res;
} 
inline void dfs(int s)
{
	if(s == m-k+1)
	{
		bool flag(true);
		for(int i = s-k+1; i < s; i++)if(vis[get(i)])flag=false;
		if(flag)
		{
			for(int i = 1; i <= m; i++)
				printf("%d",a[i]);
			puts("");
			fclose(stdin);
			fclose(stdout);
			exit(0);
		}
	}
	else
	{
		a[s] = 0;
		int now = get(s-k+1);
		if(!vis[now])
		{
			vis[now] = true;
			dfs(s+1);
			vis[now] = false;
		}
		a[s] = 1;
		now = get(s-k+1);
		if(!vis[now])
		{
			vis[now] = true;
			dfs(s+1);
			vis[now] = false;
		}
	}
}
int main()
{
	freopen("taiko.in","r",stdin);
	freopen("taiko.out","w",stdout);
	scanf("%d",&k);
	m = 1<<k;
	for(int i = 1; i <= k; i++)a[i] = 0;
	for(int j = m; j >= m-k+1; j--)a[j] = 1;
	vis[0] = true;
	for(int i = m-k+1; i <= m; i++)
	vis[get(i)] = true;
	printf("%d ",m); 
	dfs(k+1);
	return 0;
}
