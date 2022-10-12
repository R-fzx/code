#include<bits/stdc++.h>
#define int long long 
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
struct node
{	int id,w;
}dis[1005];
struct bb
{	int nextt,to,w;
}op[1000005];
int n,m,head[1005],cnt,f[1005],ID[1005];
bool bj[1005];
priority_queue<node> q; 
bool operator <(node a,node b){return a.w>b.w;} 
inline void add(int x,int y,int z)
{	op[++cnt].nextt=head[x];
	op[cnt].to=y;
	op[cnt].w=z;
	head[x]=cnt;
}
void dij()
{	for(register int i=1;i<=n;++i)dis[i].id=i,dis[i].w=1147483647000000;
	dis[1].w=0;
	node tmp;
	tmp.id=1,tmp.w=0;
	q.push(tmp);
	while(!q.empty())
	{	int x=q.top().id;
		q.pop();
		if(bj[x])continue;
		bj[x]=1;
		for(register int i=head[x];i;i=op[i].nextt)
		{	int y=op[i].to;
			if(dis[y].w>dis[x].w+op[i].w)
			{	dis[y].w=dis[x].w+op[i].w;
				if(!bj[y])
				{	tmp.id=y,tmp.w=dis[y].w;
					q.push(tmp);
				}
			}
		}
	}
	return ;
}
signed main()
{	freopen("Castle.in","r",stdin);
	freopen("Castle.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=m;++i)
	{	int x=read(),y=read(),z=read();
		add(x,y,z),add(y,x,z);
	}
//	cerr<<"!!!";
	dij();
//	for(register int i=1;i<=n;++i)cerr<<dis[i].w<<' ';
//	cerr<<endl;
//	sort(dis+1,dis+n+1);
//	for(register int i=1;i<=n;++i)ID[dis[i].id]=i;
	f[1]=1;
	for(register int l=n;l>=1;--l)
	{	int x=dis[l].id;
		for(register int i=head[x];i;i=op[i].nextt)
		{	int y=op[i].to;
//			cerr<<x<<' '<<y<<endl;
			if(dis[y].w+op[i].w==dis[x].w)f[x]++;
		}
	}
	int ans=1;
	for(register int i=1;i<=n;++i)ans=ans*f[i]%2147483647;//,cerr<<f[i]<<' ';
	printf("%lld",ans);
	return 0;
}
