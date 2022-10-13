#include<stdio.h>
#include<algorithm>
using namespace std;
int Next[10010],vet[10010],head[10010],l[10010],r[10010],ll[10010],rr[10010],b[20010],num,vis[2010],q[10010],u[10010],v[10010];
int n,ans;
void add(int u,int v,int ll,int rr)
{
	Next[++num]=head[u];
	head[u]=num;
	vet[num]=v;
	l[num]=ll;
	r[num]=rr;
}
int check(int L,int R)
{
	if (b[R]-b[L]+1<=ans) return 1;
	for (int i=1;i<=n;i++) vis[i]=0;
	int he=1,ta=1;
	q[ta]=1;
	vis[1]=1;
	while (he<=ta)
	{
		int u=q[he++];
		for (int i=head[u];i;i=Next[i])
		{
			int v=vet[i];
			if (l[i]<=L&&r[i]>=R)
			{
				if (!vis[v])
				{
					vis[v]=1;
					q[++ta]=v;
					if (v==n) return 1;
				}
			}
		}
	}
	return vis[n];
}
int bs(int L,int l,int r)
{
	if (l==r) return l;
	int mid=(l+r+1)>>1;
	if (check(L,mid)) return bs(L,mid,r); 
	return bs(L,l,mid-1);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int m,cnt=0,maxr=0;
	ans=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&u[i],&v[i],&ll[i],&rr[i]);
		b[++cnt]=ll[i];
		b[++cnt]=rr[i];
		maxr=max(maxr,max(ll[i],rr[i]));
	}
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=m;i++)
		ll[i]=lower_bound(b+1,b+1+cnt,ll[i])-b,rr[i]=lower_bound(b+1,b+1+cnt,rr[i])-b;
	for (int i=1;i<=m;i++)
	{
		add(u[i],v[i],ll[i],rr[i]);
		add(v[i],u[i],ll[i],rr[i]);
	}
	int L,R;
	for (int i=1;i<=cnt;i++)
	{
		int xx=bs(i,i,cnt);
		if (check(i,xx))
		{
			if (b[xx]-b[i]+1>ans)
			{
				ans=b[xx]-b[i]+1;
				L=b[i],R=b[xx];
			}
		}
	}
	printf("%d\n",ans);
	for (int i=L;i<R;i++) printf("%d ",i);
	if (ans) printf("%d\n",R);
	return 0;
} 
