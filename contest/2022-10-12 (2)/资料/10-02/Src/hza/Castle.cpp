#include<stdio.h>
#include<stdlib.h>

int n,m;
const int MAX=2000;
const int INF=100000000;
int map[MAX][MAX];
int dist[MAX];
int f[MAX];
int q[MAX];
int hash[MAX];
int front,end;

int min(int a,int b)
{
	return a<b?a:b;
}

void init()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			map[i][j]=2*INF;
		}
	}
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==b)continue;
		map[a-1][b-1]=min(map[a-1][b-1],c);
		map[b-1][a-1]=min(map[a-1][b-1],map[b-1][a-1]);
		map[a-1][b-1]=map[b-1][a-1];
	}
}

void SPFA()
{
	for(int i=0;i<=n;i++)
	{
		dist[i]=INF;
	}
	front=0;
	end=0;
	q[0]=0;
	f[0]=1;
	dist[0]=0;
	while(front<=end)
	{
		int j=q[front];
		for(int i=0;i<n;i++)
		{
			if(map[j][i]<INF)
			{
				if(dist[i]==dist[j]+map[j][i])
				{
					f[i]++;
					continue;
				}
				if(dist[i]>dist[j]+map[j][i])
				{
					dist[i]=dist[j]+map[j][i];
					f[i]=1;
					if(!hash[i])
					{
						hash[i]=1;
						q[++end]=i;
					}
				}
			}
		}
		++front;
		hash[j]=0;
	}
}

int main()
{
	freopen("Castle.in","r",stdin);
	freopen("Castle.out","w",stdout);
	init();
	SPFA();
	long long answer=1;
	for(int i=1;i<n;i++)
	{
		f[i]=0;
		for(int j=0;j<n;j++)
		{
			if(map[j][i]+dist[j]==dist[i])
			{
				++f[i];
				f[i]=f[i]%2147483647;
			}
		}
		answer=answer%2147483647;
		answer=answer*f[i];
		answer=answer%2147483647;
	}
	printf("%lld",answer);
}
