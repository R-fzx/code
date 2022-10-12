#include <stdio.h>
#include <stdlib.h>

const int N = 1000 + 10;
const int maxn = 1000000000;

bool mark[N];
long long g[N][N],dis[N],f[N];

int main()
{
	freopen("Castle.in","r",stdin);
    freopen("Castle.out","w",stdout);
	int n,m,u,v,val;
	long long ans;
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
	{
		dis[i]=maxn;
		for(int j=1; j<=n; j++)
			g[i][j]=maxn;
	}
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d",&u,&v,&val);
		if(u==v)
          continue;
		if(g[u][v]>val)
          g[u][v]=g[v][u]=val;
	}
	f[1]=1;
	ans=1;
	dis[1]=0;
	for (int t=1; t<=n; t++)
	{
		int j=0,k=maxn;
		for (int i=1; i<=n; i++)
			if(!mark[i] && dis[i]<k)
            {
              k=dis[i];
              j=i;
            }
		mark[j]=true;
        ans = ans * f[j] % 2147483647;
        for (int i=1; i<=n; i++)
			if(!mark[i])
			{
				k=dis[j]+g[j][i];
				if(dis[i]==k)
                   f[i]++;
				else if(dis[i]>k)
				{
					dis[i]=k;
                    f[i]=1;
				}
			}
	}
	printf("%I64d\n",ans);
	return 0;
}
