#include<stdio.h>
long f[201][1001];
int main()
{
	long i,j,k,n;
	freopen("t3.in","r",stdin);freopen("t3.out","w",stdout);
	f[1][0]=1;
	f[2][0]=1;f[2][1]=1;
	scanf("%ld",&n);
	for(i=3;i<=n;i++)
	{
		//f[i]=(f[i-1]+f[i-2])*(i-1);
		k=0;
		f[i][0]=f[i-1][0];
		for(j=1;j<=f[i][0];j++)
		{
			f[i][j]=f[i-1][j]+f[i-2][j]+k;
			if(f[i][j]>=10){k=f[i][j]/10;f[i][j]%=10;}else k=0;
		}
		while(k)
		{
			f[i][0]++;f[i][f[i][0]]=k%10;k/=10;
		}
		for(j=1;j<=f[i][0];j++)
		{
			f[i][j]=f[i][j]*(i-1)+k;
			if(f[i][j]>=10){k=f[i][j]/10;f[i][j]%=10;}else k=0;
		}
		while(k)
		{
			f[i][0]++;f[i][f[i][0]]=k%10;k/=10;
		}
	}
	for(i=f[n][0];i>=1;i--)
		printf("%ld",f[n][i]);
	printf("\n");
	return 0;
}
