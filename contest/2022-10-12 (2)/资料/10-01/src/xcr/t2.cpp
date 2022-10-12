#include<stdio.h>
#include<math.h>
long long f[71];

long long mi(long long a,long long b)
{
	if(b==0)
		return 1;
	long long ans=mi(a,b>>1);
	ans*=ans;
	if(b&1)
		ans=ans*a;
	return ans;
}
int main()
{
	long long a,b,i,j,k;
	freopen("t2.in","r",stdin);
	freopen("t2.out","w",stdout);
	while(1)
	{
		scanf("%I64d%I64d",&a,&b);
		if(a==0)
			break;
		for(i=64;i>=1;--i)
		{
			long long qb=floor(pow(b,1/(double)i)+1e-10),qa=ceil(pow(a,1/(double)i)-1e-10);
			if(i<=5)
			{
				for(qb=qb+2;mi(qb,i)>b;--qb);
				for(qa=qa-2>=0?qa-2:0;mi(qa,i)<a;++qa);
			}
			f[i]=qb-qa+1;
			for(j=2;i*j<=64;++j)
				f[i]-=f[i*j];
		}
		long long ans=0;
		for(i=1;i<=64;++i)
			ans+=f[i]*i;
		printf("%I64d\n",ans);
	}
	return 0;
}
