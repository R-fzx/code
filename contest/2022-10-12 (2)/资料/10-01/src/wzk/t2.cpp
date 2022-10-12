#include <stdio.h>
#include <math.h>

long long f[70],g[70],p[70];
long long a,b,i,j;
#define OpenFile 1
int main(int argc, char *argv[])
{
	#if OpenFile
	freopen("t2.in","r",stdin);
	freopen("t2.out","w",stdout);
	#endif
	while(1)
	{
		scanf("%I64d%I64d",&a,&b);
		if(a==0&&b==0)
			return 0;
		for(i=61;i>=1;i-=1)
		{
			long long t;
			t=int(pow(b,double(1/double(i))));
			if(pow(t,i)>b)
				t--;
			if(pow(t+1,i)==b)
				t++;
			p[i]=t;
			g[i]=p[i];
			for(j=2;i*j<=61;j++)
				g[i]-=g[j*i];
		}
		long long fb=0;
		for(i=1;i<=61;i++)
			fb+=g[i]*i;

		for(i=61;i>=1;i-=1)
		{
			long long t;
			t=int(pow(a-1,double(1/double(i))));
			if(pow(t,i)>(a-1))
				t--;
			if(pow(t+1,i)==(a-1))
				t++;
			p[i]=t;
			g[i]=p[i];
			for(j=2;i*j<=61;j++)
				g[i]-=g[j*i];
		}
		long long fa=0;
		for(i=1;i<=61;i++)
			fa+=g[i]*i;
		printf("%I64d\n",fb-fa);
	}
	return 0;
}
