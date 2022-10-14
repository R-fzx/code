//bus
#include<bits/stdc++.h>
using namespace std;

const int NUM=1e5+5;

int n,ans;
int a[NUM],f[NUM][25],fir[10*NUM];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void make_st()
{
	for(int i=1;(1<<i)<=n;++i)
		for(int x=1;x+(1<<i)-1<=n;++x)
			f[x][i]=min(f[x][i-1],f[x+(1<<(i-1))][i-1]);
}

inline int query(int x,int y)
{
	int d=log2(y-x+1);
	return min(f[x][d],f[y-(1<<d)+1][d]);
}

signed main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		f[i][0]=a[i];
		if(!fir[a[i]])
			fir[a[i]]=i;
	}
	
	make_st();
	
	int r=n+1,lastr=n+1;
	while(r>1)
	{
		int tempp=query(1,r-1);
//		cout<<tempp;
		lastr=r;
		r=fir[tempp];
//		cout<<r<<endl;
		ans+=(lastr-fir[tempp])*a[fir[tempp]];
	} 
	
	cout<<ans;
	
	return 0;
}

