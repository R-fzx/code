#include <stdio.h>
long long f[105]={0};
long long check(long long mi,long long p)
{
	long long mid,l=1,r=p,o,i;
	while(l<r)
	{
		mid=(l+r+1)/2;
		for(o=p,i=1;i<=mi;i++)
			o=o/mid;
		if(o>=1)
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
long long work(long long c)
{
	long long i,max,ans=0,o,j;
	memset(f,0,sizeof(f));
	for(i=61;i>=1;i--)
	{
		f[i]=check(i,c);
		for(j=2;j*i<=61;j++)
			f[i]-=f[i*j];
		ans+=i*f[i];
	}
	return ans;
}
int main()
{
	long long a,b;
	freopen("t2.in","r",stdin);
	freopen("t2.out","w",stdout);
	while(1)
	{
		scanf("%I64d %I64d\n",&a,&b);
		if(a==0 && b==0)
			break;
		printf("%I64d\n",work(b)-work(a-1));
	}
	return 0;
}
