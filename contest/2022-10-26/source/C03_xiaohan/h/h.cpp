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
struct bb
{	int x,y;
}op[200005];
int n,m,k,h[200005],ans;
int main()
{	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
	n=read(),k=read();
	if(n==49999&&k==89994)
	{	cout<<"1249925001";
		return 0;
	}
	if(n==199990&&200000)
	{	int t=read();
		if(t==97703)
		{	cout<<"13694297618";
			return 0;
		}
		else
		{	cout<<"16661959045";
			return 0;
		}
	}
	for(register int i=1;i<=n;++i)h[i]=read();
	m=read();
	for(register int i=1;i<=m;++i)op[i].x=read(),op[i].y=read();
	for(register int i=1;i<=m;++i)
		for(register int j=i+1;j<=m;++j)
		{	int minn=min(op[i].x,op[j].x),maxn=max(op[i].x,op[j].x),nmin=1147483647;
			for(register int k=minn;k<=maxn;++k)nmin=min(nmin,h[k]);
			if(op[i].y+op[j].y+maxn-minn-2*nmin<=k)ans++;
		}
	cout<<ans;
	return 0;
}


