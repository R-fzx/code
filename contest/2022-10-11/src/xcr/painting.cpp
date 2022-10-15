#include<stdio.h>

const long long bigp=1000000007;
long long mi(long long a,long long b)
{
	if(b==0)
		return 1;
	long long ans=mi(a,b>>1);
	ans=ans*ans%bigp;
	if(b&1)
		ans=ans*a%bigp;
	return ans;
}
long long s[2011][2011],c[2011][2011],c2[2011],ni[2011],mij[2011];
int main()
{
	int n,m,k,i,j;
	freopen("painting.in","r",stdin);
	freopen("painting.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(m==1)
	{
		printf("%I64d\n",mi(k,n));
		return 0;
	}
	s[0][0]=1;
	for(i=1;i<=n;++i)
	{
		s[i][0]=0;
		for(j=1;j<=i;++j)
			s[i][j]=(s[i-1][j-1]+s[i-1][j]*j)%bigp;
	}
	for(i=0;i<=n;++i)
	{
		c[i][0]=1;
		for(j=1;j<=i;++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%bigp;
	}
	for(i=1;i<=n;++i)
	{
		ni[i]=mi(i,bigp-2);
		mij[i]=mi(i,n*(m-2));
	}
	long long ans=0,a=1,jc=1;
	for(i=1;i<=n&&i<=k;++i)
	{
		long long ans2=0;
		a=a*(k-i+1)%bigp;
		jc=jc*i%bigp;
		c2[0]=1;
		for(j=1;j<=i;++j)
			c2[j]=c2[j-1]*(k-i-j+1)%bigp*ni[j]%bigp;
		for(j=0;j<=i;++j)
			ans2=(ans2+c[i][j]*c2[i-j]%bigp*mij[j])%bigp;
		ans=(ans+ans2*jc%bigp*s[n][i]%bigp*s[n][i]%bigp*a)%bigp;
	}
	printf("%I64d\n",ans);
	return 0;
}
