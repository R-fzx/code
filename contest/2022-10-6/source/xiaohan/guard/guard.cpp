#include<bits/stdc++.h>
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int n,l,k,a[205];
double p[205],ans,f[205][205][505];
int main()
{	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	n=read(),l=read(),k=read();
	for(register int i=1;i<=n;++i)
	{	int x=read();
		p[i]=x/100.0; 
	}
	for(register int i=1;i<=n;++i)a[i]=read();
	n++; 
	p[n]=1,l++,a[n]=k;
	f[0][0][200]=1;
	for(register int i=0;i<=n;++i)
		for(register int j=0;j<=i;++j)
			for(register int k=0;k<=400;++k)
			{	int now=min(a[i+1]+k,400);
				f[i+1][j][k]+=f[i][j][k]*(1-p[i+1]);
				f[i+1][j+1][now]+=f[i][j][k]*p[i+1];
			}
	for(register int i=l;i<=n;++i)
		for(register int j=200;j<=400;++j)
			ans+=f[n][i][j];
	printf("%.6lf",ans);
	return 0;
}
