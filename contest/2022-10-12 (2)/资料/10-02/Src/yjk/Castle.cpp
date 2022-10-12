#include<stdio.h>
#include<stdlib.h>
#define oo 1000000000
long N,M;
long W[1010][1010],F[1010],dist[1010];
bool vis[1010];
long long Ans;

void SPFA(long S);
int main()
{
	freopen("Castle.in","r",stdin);
	freopen("Castle.out","w",stdout);
	long i,j,k,a,b,c;
	scanf("%ld%ld",&N,&M);
	for(i=1;i<=M;i++)
	{
		scanf("%ld%ld%ld",&a,&b,&c);
		if(a!=b)W[a][b]=W[b][a]=c;
	}
	for(i=1;i<=N;i++)dist[i]=oo;
	SPFA(1);
	for(i=2;i<=N;i++)
		for(j=1;j<=N;j++)
			if(W[i][j]!=0 && dist[i]==dist[j]+W[i][j])
				F[i]++;
	Ans=1;
	for(i=2;i<=N;i++)
		Ans=(Ans*F[i])%2147483647;	
	printf("%ld\n",Ans);
	return 0;
}
long queue[2000000];
void SPFA(long S)
{
	long h,t,i,j,k,G;
	h=t=1;
	dist[S]=0;
	vis[S]=true;
	queue[1]=S;
	while(h<=t)
	{
		k=queue[h];
		for(i=1;i<=N;i++)
		if(W[k][i]!=0)
		{
			if(dist[i]>dist[k]+W[k][i])
			{
				dist[i]=dist[k]+W[k][i];
				if(!vis[i])
				{vis[i]=true;t++;queue[t]=i;}
			}
		}
		h++;vis[k]=false;
	}
}
