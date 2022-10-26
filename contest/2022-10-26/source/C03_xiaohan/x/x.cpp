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
struct node
{	int x,y;
}op[100005];
int n,f[100005],T[200005<<2],lazy[200005<<2],dl[200005],cnt,ans;
map<int,int> mapp;
inline bool cmp(node a,node b){return a.x==b.x?a.y<b.y:a.x<b.x;}
inline void push_up(int x)
{	T[x]=max(T[x<<1],T[x<<1|1]);
	return ;
}
inline void lazy_down(int x,int fa)
{	lazy[x]=max(lazy[fa],lazy[x]);
	T[x]=max(T[x],lazy[fa]);
	return ;
}
inline void push_down(int x,int l,int r)
{	int mid=(l+r)>>1;
	lazy_down(x<<1,x);
	lazy_down(x<<1|1,x);
	lazy[x]=0;
}
void maxn(int x,int nowl,int nowr,int l,int r,int k)
{	if(nowl>=l&&nowr<=r)
	{	T[x]=max(T[x],k);
		lazy[x]=max(lazy[x],k);
		return ;
	}
	push_down(x,nowl,nowr);
	int mid=(nowl+nowr)>>1;
	if(mid>=l)maxn(x<<1,nowl,mid,l,r,k);
	if(mid<r)maxn(x<<1|1,mid+1,nowr,l,r,k);
	push_up(x);
	return ;
}
int query(int x,int nowl,int nowr,int l,int r)
{	if(l>r)return 0;
	if(nowl>=l&&nowr<=r)return T[x];
	push_down(x,nowl,nowr);
	int mid=(nowl+nowr)>>1,nmax=0;
	if(mid>=l)nmax=max(nmax,query(x<<1,nowl,mid,l,r));
	if(mid<r)nmax=max(nmax,query(x<<1|1,mid+1,nowr,l,r));
	push_up(x);
	return nmax;
}
int main()
{	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i)op[i].x=read(),op[i].y=read(),dl[++cnt]=op[i].x+op[i].y,dl[++cnt]=op[i].x-op[i].y;
	sort(dl+1,dl+cnt+1);
	sort(op+1,op+n+1,cmp);
	int tot=unique(dl+1,dl+cnt+1)-dl-1;
	for(register int i=1;i<=tot;++i)mapp[dl[i]]=i;
	for(register int i=1;i<=n;++i)
	{	//cerr<<i;
		f[i]=query(1,1,tot,1,mapp[op[i].x-op[i].y]-1)+1;
//		cerr<<i;
		maxn(1,1,tot,mapp[op[i].x+op[i].y],tot,f[i]);
//		cerr<<op[i].x<<' '<<op[i].y<<' '<<f[i]<<endl;
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}

