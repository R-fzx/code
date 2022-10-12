#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mod 10007

using namespace std;

struct ff
{
	int ll,c;

}a[100005]={0,0};

int sum[10005]={0},f[10005]={0},d[10005]={0};

int c[1005][1005]={0},tot=0,z[10005]={0},t;

void dfs(int k,int p)
{
	int i;

	for(i=d[k];i;i=a[i].ll)
	{
		dfs(a[i].c,k);
	
		sum[k]+=sum[a[i].c];
	}

	sum[k]++;
}

void work(int k)
{
	int i,ss,count;

	for(i=d[k];i;i=a[i].ll)
		work(a[i].c);

	for(i=d[k],tot=0;i;i=a[i].ll)
		z[++tot]=a[i].c;

	ss=1;

	count=sum[k]-1;

	for(i=tot;i>=1;i--)
	{
		ss=(long long)ss*f[z[i]]*c[count-1][sum[z[i]]-1]%mod;
	
		count-=sum[z[i]];
	}

	f[k]=ss;
}

void add(int ii,int jj)
{
	t++;

	a[t].ll=d[ii]; d[ii]=t; a[t].c=jj;
}

int main()
{
	int T,t1,i,j,j1,n;

	freopen("t1.in","r",stdin);
	freopen("t1.out","w",stdout);

	for(i=1,c[0][0]=1;i<=1000;i++)
		for(j=1,c[i][0]=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;

	cin>>T;

	while(T--)
	{
		cin>>n;
	
		memset(d,0,sizeof(d));
		memset(f,0,sizeof(f));
		memset(sum,0,sizeof(sum));
	
		t=0;
	
		for(i=1;i<=n;i++)
		{
			scanf("%d",&tot);
		
			for(j=1;j<=tot;j++)
			{
				scanf("%d",&j1);
			
				add(i,j1);
			}
		}
	
		dfs(1,0);
	
		work(1);
	
		printf("%ld\n",f[1]);
	}

	return 0;
}

