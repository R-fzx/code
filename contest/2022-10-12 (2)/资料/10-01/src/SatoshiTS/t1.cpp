#include<stdio.h>
#include<stdlib.h>

int c[1001][1001];

int main()
{
	int i,j,k,m,n;
	freopen("t1.in","r",stdin);
	freopen("t1.out","w",stdout);
	c[0][0]=1;
	for(i=1;i<=1000;i++)
	{
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%10007;
	}
	int T,t;
	for(T=1;T<=t;T++)
	{
	
	}
	
	return 0;
}
