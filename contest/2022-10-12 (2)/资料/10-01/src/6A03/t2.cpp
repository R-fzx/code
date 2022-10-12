#include<stdio.h>
#include<math.h>
long long f[65];
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
	long long a,b,i,j,k,s,t,ans;
	freopen("t2.in","r",stdin);
	freopen("t2.out","w",stdout);
	while(1)
	{
		scanf("%I64d%I64d",&a,&b);
		if(a==0&&b==0)break;
		for(i=60;i>=1;--i)
		{
			t=floor(pow(b,1/(double)i)-0.000001),s=ceil(pow(a,1/(double)i)-0.000001);
			if(i<=5)
			{
				t+=2;
				while(mi(t,i)>b)t--;
				if(s-2>=0)
					s=s-2;
				else s=0;
				while(mi(s,i)<a)s++;
			}
			f[i]=t-s+1;
			for(j=2;i*j<=60;++j)
				f[i]-=f[i*j];
		}
		ans=0;
		for(i=1;i<=60;++i)
			ans+=f[i]*i;
		printf("%I64d\n",ans);
	}
	return 0;
}
