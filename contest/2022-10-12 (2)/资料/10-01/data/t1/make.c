#include <stdio.h>
long i,t1,la,n,T,tot[10005]={0},z[1005][1005]={0};
int main()
{
	long j;
	freopen("t1.in","w",stdout);
	srand((unsigned)time(NULL));
	T=1;
	printf("%ld\n",T);
	for(t1=1;t1<=T;t1++)
	{
		n=5;
		memset(tot,0,sizeof(tot));
		printf("%ld\n",n);
		for(i=n;i>=2;i--)
		{
			la=rand()%(i-1)+1;
			z[la][++tot[la]]=i;
		}
		for(i=1;i<=n;i++)
		{
			printf("%ld",tot[i]);
			for(j=1;j<=tot[i];j++)
				printf(" %ld",z[i][j]);
			printf("\n");
		}
	}
	return 0;
}
