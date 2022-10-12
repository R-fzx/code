#include <stdio.h>
int main()
{
	long n,i,j,o1,o2,tmp,pr[1005]={0};
	freopen("t3.in","w",stdout);
	srand((unsigned)time(NULL));
	n=rand()%199+2;
	printf("%ld\n",n);
	for(i=1;i<=n;i++)
		pr[i]=i;
	for(i=1;i<=1000;i++)
	{
		o1=rand()%n+1; o2=rand()%n+1;
		tmp=pr[o1];
		pr[o1]=pr[o2];
		pr[o2]=tmp;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(pr[i]==j)
				printf("1");
			else
				printf("0");
			if(j==n)
				printf("\n");
			else
				printf(" ");
		}
	return 0;
}
