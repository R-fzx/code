#include<stdio.h>
long a[1001][1001];
bool b[1001];
long d[1001];
long f[1001];
int main()
{
	freopen("Castle.in","r",stdin);freopen("Castle.out","w",stdout);
	long i,j,k,n,m,x,y,z,ix;
	long long s;
	scanf("%ld%ld",&n,&m);
	for(i=1;i<=n;i++)
	{
		d[i]=1000000000;
		for(j=1;j<=n;j++)
			a[i][j]=1000000000;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%ld%ld%ld",&x,&y,&z);
		if(x==y)continue;
		if(a[x][y]>z){a[x][y]=z;a[y][x]=z;}
	}
	f[1]=1;
	s=1;
	d[1]=0;
	for(ix=1;ix<=n;ix++)
	{
		j=0;k=1000000000;
		for(i=1;i<=n;i++)
			if(b[i]==0&&d[i]<k){k=d[i];j=i;}
		if(j==0)break;
		b[j]=1;s=s*f[j];if(s>=2147483647)s%=2147483647;
		for(i=1;i<=n;i++)
			if(b[i]==0)
			{
				k=d[j]+a[j][i];
				if(d[i]==k)f[i]++;
				else
				if(d[i]>k)
				{
					d[i]=k;f[i]=1;
				}
			}
	}
	printf("%I64d\n",s);
	return 0;
}
