#include<stdio.h>
long f[49000001];
int main()
{
	long i,j,a,b;
	long long s,q;
	for(i=2;i<=7000;i++)
		if(f[i]==0)
		{
			s=i;q=i;j=0;
			while(1)
			{
				j++;
				s=s*q;
				if(s>49000000)break;
				f[s]=j;
			}
		}
	freopen("t2.in","r",stdin);freopen("t2.out","w",stdout);
	while(1)
	{
		scanf("%ld%ld",&a,&b);
		if(a==0&&b==0)return 0;
		j=0;
		for(i=a;i<=b;i++)
			j+=f[i];
		j=j-a;j=j+b+1;
		printf("%ld\n",j);
	}
	return 0;
}
