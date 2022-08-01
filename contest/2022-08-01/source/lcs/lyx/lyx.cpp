#include<bits/stdc++.h>
using namespace std;
int n,m,sum[100005],ans;
int head[100005],tot;
struct Edge{int nxt,to;}edge[200005];
int rd[100005],cd[100005];
queue<int>q;
void add(int x,int y){edge[++tot].nxt=head[x];edge[tot].to=y;head[x]=tot;}
void tp()
{
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=edge[i].nxt)
		{
			--rd[edge[i].to];
			sum[edge[i].to]+=sum[x];
			if(!rd[edge[i].to])q.push(edge[i].to);
		}
	}
	return;
}
int main()
{
	freopen("lyx.in","r",stdin);
	freopen("lyx.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);++cd[x];++rd[y];
	}
	for(int i=1;i<=n;++i)if(!rd[i])q.push(i),++sum[i];
	tp();
	for(int i=1;i<=n;++i)if(!cd[i])ans+=sum[i];
	printf("%d",ans);
	return 0;
}
