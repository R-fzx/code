//travel
#include<bits/stdc++.h>
using namespace std;

const int NUM=205;

int n,m,maxn;
int ind[NUM],num[NUM],head[NUM],tempin[NUM],ansnum[NUM],cnt[NUM],edge[NUM][NUM*NUM];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int a,b;
		a=read(),b=read();
		++ind[b];
		++tempin[b];
		
		edge[a][++cnt[a]]=b;
	}
	
	for(int j=1;j<=n;++j)
	{
		if(ind[j]==0)
			ansnum[++maxn]=j;
	}
	
	for(int i=1;i<=n;++i)
	{
		if(ind[i]!=0)
			continue;
		
		int ans=0;
		
		for(int j=1;j<=cnt[i];++j)
			--tempin[edge[i][j]];
		
		for(int j=1;j<=n;++j)
		{
			if(tempin[j]==0 && j!=i)
				num[++ans]=j;
		}
		
		if(ans>maxn)
		{
			maxn=ans;
			
			for(int j=1;j<=maxn;++j)
				ansnum[j]=num[j];
		}
		
		for(int j=1;j<=cnt[i];++j)
			++tempin[edge[i][j]];
	}
	
	cout<<maxn<<endl;
	for(int i=1;i<=maxn;++i)
		cout<<ansnum[i]<<" ";
	
	return 0;
}
