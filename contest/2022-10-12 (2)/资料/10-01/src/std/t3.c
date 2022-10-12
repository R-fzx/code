#include <stdio.h>
long tmp[1005]={0},ans[505][10005]={0};
int main()
{
	long i,n,kk,j;
	freopen("t3.in","r",stdin);
	freopen("t3.out","w",stdout);
	scanf("%ld\n",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%ld ",&kk);
	ans[1][1]=0; ans[2][1]=1;
	for(i=3;i<=n;i++)
	{
		memset(tmp,0,sizeof(tmp));
		for(j=1;j<=1000;j++)
			ans[i][j]=(ans[i-1][j]+ans[i-2][j])*(i-1);
		for(j=1;j<=1000;j++)
			if(ans[i][j]>=10)
			{
				ans[i][j+1]+=ans[i][j]/10;
				ans[i][j]=ans[i][j]%10;
			}
	}
	for(i=1000;i>1;i--)
		if(ans[n][i])
			break;
	for(;i>=1;i--)
		printf("%ld",ans[n][i]);
	return 0;
}
