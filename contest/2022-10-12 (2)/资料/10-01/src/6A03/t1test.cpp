#include<stdio.h>
long a[1001][1001],f[1001],s,n;
bool b[1001];
void dfs(long x)
{
	if(x>n)
	{
		long i,j,k;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=a[i][0];j++)
				if(f[i]>f[a[i][j]])return;
			for(j=1;j<a[i][0];j++)
				for(k=j+1;k<=a[i][0];k++)
					if(f[a[i][j]]>f[a[i][k]])return;
		}
		s++;
		return;
	}
	long i,j;
	for(i=1;i<=n;i++)
		if(b[i]==0)
		{
			f[x]=i;
			b[i]=1;
			dfs(x+1);
			b[i]=0;
		}
	return;
}
int main()
{
	long i,j,k,ix,t;
	freopen("t1.in","r",stdin);freopen("t1.out","w",stdout);
	scanf("%ld",&t);
	for(ix=1;ix<=t;ix++)
	{
		s=0;
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a[i][0]);
			for(j=1;j<=a[i][0];j++)
				scanf("%ld",&a[i][j]);
		}
		dfs(1);
		printf("%ld\n",s);
	}
	return 0;
}
/*
长度 种数 
(1,1)&(1,1)=2,1
(2,1)&(1,1)=3,2
(1,1)&(2,1)=3,1
(2,1)&(2,1)=4,3
*/
