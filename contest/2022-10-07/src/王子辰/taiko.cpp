#include<cstdio>
#include<cstring>
#include<cstdlib>
int n,m,a[3000],res;
bool vis[3000];
inline bool dfs(int x)
{
	if(x==m+1) return true;
	a[x]=0;
	int p=0;
	for(int i=x,j=0;i>=x-n+1;i--,j++)
		p+=a[i]<<j;
	if(!vis[p])
	{
		vis[p]=1;
		if(dfs(x+1)) return true;
		vis[p]=0;
	}
	p=0;
	a[x]=1;
	for(int i=x,j=0;i>=x-n+1;i--,j++)
		p+=a[i]<<j;
	if(!vis[p])
	{
		vis[p]=1;
		if(dfs(x+1)) return true;
		vis[p]=0;
	}
	return false;
}
int main()
{
	freopen("taiko.in","r",stdin);
	freopen("taiko.out","w",stdout);
	scanf("%d",&n);
	m=1<<n;
	vis[0]=1;
	if(dfs(n+1))
	{
		printf("%d ",m);
		for(int i=1;i<=m-1;i++)
			printf("%d",a[i]);
		printf("1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
