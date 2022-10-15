#include<stdio.h>

int n,a,b[11],l[11];
double best;
void dfs(int i,int last)
{
	int j;
	if(i==0)
	{
		double now=0;
		for(j=0;j<(1<<n);++j)
		{
			int cnt=0,k,sumb=0;
			double now2=1;
			for(k=0;k<n;++k)
				if(j&(1<<k))
				{
					now2*=l[k]/100.0;
					cnt++;
				}
				else
				{
					now2*=(100.0-l[k])/100.0;
					sumb+=b[k];
				}
			if(cnt<=n/2)
				now2*=(double)a/(double)(a+sumb);
			now+=now2;
		}
		if(now>best)
			best=now;
		return;
	}
	int flag=0;
	for(j=last;j<n;++j)
		if(l[j]<100)
		{
			flag=1;
			l[j]+=10;
			dfs(i-1,j);
			l[j]-=10;
		}
	if(!flag)
	{
		for(j=0;j<n;++j)
			if(l[j]<100)
				break;
		if(j<=n)
			dfs(0,last);
	}
}
int main()
{
	int k,i;
	freopen("assembly.in","r",stdin);
	freopen("assembly.out","w",stdout);
	scanf("%d%d%d",&n,&k,&a);
	for(i=0;i<n;++i)
		scanf("%d%d",&b[i],&l[i]);
	dfs(k,0);
	printf("%.6lf\n",best);
	return 0;
}
