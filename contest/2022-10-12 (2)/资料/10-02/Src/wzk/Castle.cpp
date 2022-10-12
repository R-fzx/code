#include <stdio.h>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
int disp[2000],num[2000];
int map[1020][1020];
int n,m;

void dfs(int x)
{
	int i;
	for(i=1;i<=n;i++)
		if(map[x][i]!=2147483640)
		{
			if(disp[i]==-1)
			{
				disp[i]=disp[x]+map[x][i];
				num[i]=1;
				dfs(i);		
			}
			else
			{
				if(disp[i]>disp[x]+map[x][i])
				{
					disp[i]=disp[x]+map[x][i];
					num[i]=1;
					dfs(i);					
				}
				else if(disp[i]==disp[x]+map[x][i])
					num[i]++;
			}
		}
}

#define OpenFile 0
int main()
{
	#if OpenFile
	freopen("Castle.in","r",stdin);
	freopen("Castle.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			map[i][j]=2147483640;
	for(i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d",&a,&b);
		scanf("%d",&c);
		map[a][b]=Min(c,map[a][b]);
		map[b][a]=map[a][b];
	}
	for(i=1;i<=n;i++)
		disp[i]=-1;
	disp[1]=0;
	num[1]=1;	
	dfs(1);
	int ans=1;
	for(i=1;i<=n;i++)
	{
		ans*=num[i];
		ans=ans%2147483647;
	}
	printf("%d\n",ans);
	return 0;
}
