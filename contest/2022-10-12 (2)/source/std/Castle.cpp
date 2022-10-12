#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector <pair <int,int> > g[1011];
int hash1[1011][1011];
long long dist[1011];
priority_queue <pair <long long,int> > mindist;

int deg[1011];
int main()
{
	int n,m,i,j;
	freopen("Castle.in","r",stdin);
	freopen("Castle.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			hash1[i][j]=2000000000;
	for(i=0;i<m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(c<hash1[a][b])
		{
			g[a].push_back(make_pair(b,c));
			g[b].push_back(make_pair(a,c));
			hash1[a][b]=c;
		}
	}
	
	fill(dist+1,dist+n+1,1000000000000000000ll);
	dist[1]=0;
	mindist.push(make_pair(0,1));
	while(!mindist.empty())
	{
		pair <long long,int> now=mindist.top();
		mindist.pop();
		now.first=-now.first;
		if(now.first!=dist[now.second])
			continue;
		for(vector <pair <int,int> > :: iterator j=g[now.second].begin();j!=g[now.second].end();++j)
			if(now.first+j->second<dist[j->first])
			{
				dist[j->first]=now.first+j->second;
				mindist.push(make_pair(-dist[j->first],j->first));
			}
	}
	
	for(i=1;i<=n;++i)
		for(vector <pair <int,int> > :: iterator j=g[i].begin();j!=g[i].end();++j)
			if(dist[i]+j->second==dist[j->first])
				deg[j->first]++;
	long long ans=1;
	for(i=2;i<=n;++i)
		ans=ans*(long long)deg[i]%2147483647;
	printf("%I64d\n",ans);
	return 0;
}
