#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

long long f[70];
long long A,B,Num,tot,Ans;
long long x,y,k,Q,limit;
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
	freopen("t2.in","r",stdin);
	freopen("t2.out","w",stdout);
	long i,j;
	while(1)
	{
		scanf("%I64d%I64d",&A,&B);
		if(A==0)break;
		for(i=64;i>=1;--i)
		{
			long long qb=(long long)floor(pow(B,1/(double)i)+1e-10),qa=(long long)ceil(pow(A,1/(double)i)-1e-10);
			if(i<=5)
			{
				for(qb=qb+2;mi(qb,i)>B;--qb);
				for(qa=qa-2>=0?qa-2:0;mi(qa,i)<A;++qa);
			}
			f[i]=qb-qa+1;
			for(j=2;i*j<=64;++j)
				f[i]-=f[i*j];
		}
		Ans=0;
		for(i=1;i<=64;++i)
			Ans+=f[i]*i;
		printf("%I64d\n",Ans);
	}
	return 0;
}
