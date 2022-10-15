#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct node
{
	int v,b,wh;
};
vector <node> tree[201];
int maxe,maxa,maxb;
int dfs(int i,int end,int fa)
{
	if(i==end)
		return 1;
	int tr=0;
	for(vector <node> :: iterator j=tree[i].begin();j!=tree[i].end();++j)
		if(j->v!=fa)
		{
			int ret=dfs(j->v,end,i);
			if(ret)
			{
				tr=1;
				if(j->b>maxe)
				{
					maxe=j->b;
					maxa=i;
					maxb=j->v;
				}
			}
		}
	return tr;
}
struct fe
{
	int u,v,a,b;
	friend bool operator < (fe a,fe b)
	{
		if(a.a==b.a)
			return a.b<b.b;
		return a.a<b.a;
	}
}edge[50011];

int bcj[211];
int getfa(int a)
{
	if(bcj[a]==a)
		return a;
	return bcj[a]=getfa(bcj[a]);
}

int use[50011];
priority_queue < pair<int,int> > bb;
int main()
{
	int n,m,i,j,k,p,q;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(i=0;i<m;++i)
		scanf("%d%d%d%d",&edge[i].u,&edge[i].v,&edge[i].a,&edge[i].b);
	sort(edge,edge+m);
	for(i=1;i<=n;++i)
		bcj[i]=i;
	int cnt=n;
	long long ans=1000000000000000000ll;
	for(i=0;i<m;++i)
	{
		if(getfa(edge[i].u)!=getfa(edge[i].v))
		{
			bcj[getfa(edge[i].u)]=getfa(edge[i].v);
			tree[edge[i].u].push_back((node){edge[i].v,edge[i].b,i});
			tree[edge[i].v].push_back((node){edge[i].u,edge[i].b,i});
			use[i]=1;
			bb.push(make_pair(edge[i].b,i));
			cnt--;
			if(cnt==1)
			{
				while(!use[bb.top().second])
					bb.pop();
				if((long long)bb.top().first*(long long)q+(long long)edge[i].a*(long long)p<ans)
					ans=(long long)bb.top().first*(long long)q+(long long)edge[i].a*(long long)p;
			}
		}
		else
		{
			maxe=-1;
			dfs(edge[i].u,edge[i].v,0);
			if(maxe>edge[i].b)
			{
				vector <node> :: iterator j;
				for(j=tree[maxa].begin();j!=tree[maxa].end();++j)
					if(j->v==maxb)
					{
						use[j->wh]=0;
						tree[maxa].erase(j);
						break;
					}
				for(j=tree[maxb].begin();j!=tree[maxb].end();++j)
					if(j->v==maxa)
					{
						tree[maxb].erase(j);
						break;
					}
				tree[edge[i].u].push_back((node){edge[i].v,edge[i].b,i});
				tree[edge[i].v].push_back((node){edge[i].u,edge[i].b,i});
				use[i]=1;
				bb.push(make_pair(edge[i].b,i));
				if(cnt==1)
				{
					while(!use[bb.top().second])
						bb.pop();
					long long aa=bb.top().first;
					if((long long)bb.top().first*(long long)q+(long long)edge[i].a*(long long)p<ans)
						ans=(long long)bb.top().first*(long long)q+(long long)edge[i].a*(long long)p;
				}
			}
		}
	}
	if(ans==1000000000000000000ll)
		printf("-1\n");
	else
		printf("%I64d\n",ans);
	return 0;
}
