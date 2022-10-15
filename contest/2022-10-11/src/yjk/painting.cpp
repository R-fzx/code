#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MOD 1000000007
long N,M,K;
long Ans;
long F[10][10][10],map[10][10],hash[10];
void Dfs(long n,long m);
int main()
{
	freopen("painting.in","r",stdin);
	freopen("painting.out","w",stdout);
	long i,j,k;
	for(N=1;N<=3;N++)
		for(M=1;M<=3;M++)
			for(K=1;K<=3;K++)
			{
				Ans=0;
				memset(map,0,sizeof(map));
				Dfs(1,1);
				printf("F[%ld][%ld][%ld]=%ld\n",N,M,K,Ans);
			}
	return 0;
}

void Dfs(long n,long m)
{
	if(m==M+1)
	{
		m--;
		if(n!=N)
			Dfs(n+1,1);
		else
		{
			if(n==2&&m==2&&K==2)
			N++,N--;
			long j,k,i;
			long t1=0,t2=0,flag=false;
			for(i=1;i<M;i++)
			{
				t1=0,t2=0;
				memset(hash,0,sizeof(hash));
				for(j=1;j<=i;j++)
					for(k=1;k<=N;k++)
						hash[map[k][j]]++;
				for(i=1;i<=K;i++)if(hash[i]!=0)t1++;
				memset(hash,0,sizeof(hash));
				for(j=i+1;j<=M;j++)
					for(k=1;k<=N;k++)
						hash[map[k][j]]++;
				for(i=1;i<=K;i++)if(hash[i]!=0)t2++;
				if(t1!=t2){flag=true;break;}
			}
			if(flag==false)Ans=(Ans+1)%MOD;
			//for(i=1;i<=N;i++)
		//	{
			//	for(j=1;j<=M;j++)
				//	printf("%ld ",map[i][j]);
				//printf("\n");
		//	}
		//	printf("\n");
		}
		return ;
	}
	for(long i=1;i<=K;i++)
	{
		map[n][m]=i;
		Dfs(n,m+1);
	}
}
