#include<bits/stdc++.h>
#define int long long
#define mod 1000000009
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int n,m,fa[200005],ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
signed main()
{	freopen("magician.in","r",stdin);
	freopen("magician.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=n;++i)fa[i]=i;
	for(register int i=1;i<=m;++i)
	{	int x=read(),y=read();
		int fx=find(x),fy=find(y);
		if(fx==fy)ans=ans*2+1;
		else fa[fy]=fx;
		ans%=mod;
		printf("%lld\n",ans);
	}
	return 0;
} 
