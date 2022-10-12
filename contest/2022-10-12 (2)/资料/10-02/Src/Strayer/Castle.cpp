#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std ;

const int max_n= 1005, max_edge= max_n * max_n;
const int INF= 999999999;
const __int64 MOD= 2147483647;

int N, M;

int g[max_n][max_n];
int dist[max_n], pre[max_n];

struct edge
{
	int pre[max_edge], last[max_n], node[max_edge], val[max_edge];
	int tot ;
	void add_edge(int s, int t, int v)
	{
		tot ++ ;
		pre[tot]= last[s];
		last[s]= tot;
		node[tot]= t;
		val[tot]= v;
	}
}e;

void init()
{
	for(int i(1); i< max_n; ++ i)
		for(int j(1); j< max_n; ++ j)
			g[i][j]= INF;
	
	freopen("Castle.in", "r", stdin);
	freopen("Castle.out", "w", stdout);
	scanf("%d%d", &N, &M);
	for(int i(1); i<= M; ++ i)
	{
		int s, t, v;
		scanf("%d%d%d", &s, &t, &v);
		g[s][t] = g[t][s]= min(g[t][s], v);
	}
	for(int i(1); i<= N; ++ i)
		for(int j(1); j<= N; ++ j)
			if(i != j && g[i][j] < INF)
				e.add_edge(i, j, g[i][j]);
}

void solve()
{
	memset(dist, 127, sizeof(dist));
	dist[1]= 0;
	queue<int> q;
	q.push(1);

	while(!q.empty())
	{
		int u= q.front();
		q.pop();
		for(int pos(e.last[u]); pos; pos= e.pre[pos])
		{
			int v= e.node[pos];
			if(dist[u] + e.val[pos] < dist[v])
			{
				dist[v]= dist[u] + e.val[pos];
				q.push(v);
			}
		}
	}
	for(int u(1); u<= N; ++ u)
		for(int pos(e.last[u]); pos; pos= e.pre[pos])
		{
			int v= e.node[pos];
			if(dist[u] + e.val[pos] == dist[v])
				pre[v] ++ ;
		}
	__int64 ans= 1;
	for(int i(2); i<= N; ++ i)
	{
		ans *= pre[i];
		ans %= MOD;
	}
	printf("%I64d\n", ans);
}

int main()
{
	init();
	solve();
	return 0 ;
}
