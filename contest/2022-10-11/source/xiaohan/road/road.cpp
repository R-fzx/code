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
{	int ps,qs;
};
struct bb
{	int x,y,a,b;
}op[50005];
int n,m,p,q,fa[205];
priority_queue<node> Q;
bool operator <(node a,node b)
{	return a.ps*p+a.qs*q>b.ps*p+b.qs*q;
}
int find(int x){return fa[x]==x?fa[x]:fa[x]==find(fa[x]);}
signed main()
{	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),p=read(),q=read();
	for(register int i=1;i<=n;++i)fa[i]=i; 
	for(register int i=1;i<=m;++i)
	{	op[i].x=read(),op[i].y=read(),op[i].a=read(),op[i].b=read();
		int fx=find(op[i].x),fy=find(op[i].y);
		if(fx!=fy)fa[fy]=fx;
	}
	bool flag=1;
	for(register int i=2;i<=n;++i)
		if(find(i)!=find(i-1))flag=0;
	if(!flag)
	{	cout<<-1;
		return 0;
	}
	node tmp;
	tmp.ps=tmp.qs=0;
	Q.push(tmp);
	while(!Q.empty())
	{	node ls=Q.top();
		Q.pop();
		for(register int i=1;i<=n;++i)fa[i]=i; 
		for(register int i=1;i<=m;++i)
			if(op[i].a<=ls.ps&&op[i].b<=ls.qs)
			{	int fx=find(op[i].x),fy=find(op[i].y);
				if(fx!=fy)fa[fy]=fx;
			}
		bool flag=1;
		for(register int i=2;i<=n;++i)
			if(find(i)!=find(i-1))flag=0;
		if(flag)
		{	cout<<ls.ps*p+ls.qs*q;
			return 0;
		}
		ls.ps++;
		Q.push(ls);
		ls.ps--,ls.qs++;
		Q.push(ls);
	}
	cout<<-1;
	return 0;
}

