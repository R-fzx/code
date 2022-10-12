#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std ;

const int max_n= 1005;
const int MOD= 10007;

int C[max_n + max_n][max_n + max_n];
int g[max_n][max_n];
int child[max_n][2], size[max_n];
int N;

void make_graph(int u)
{
	if(!g[u][0])
	{
		size[u]= 1;
		return ;
	}
	child[u][0]= g[u][1];
	make_graph(g[u][1]);
	for(int i(2); i<= g[u][0]; ++ i)
	{
		int pre= g[u][i - 1], v= g[u][i];
		child[pre][1]= v;
		make_graph(v);
	}
}

int get_size(int u)
{
	if(!u)
		return 0;
	return size[u]= get_size(child[u][0]) + get_size(child[u][1]) + 1;
}

int get_ans(int u)
{
	if(!u)
		return 1;
	return (get_ans(child[u][0]) * get_ans(child[u][1]) % MOD) * C[size[child[u][0]] + size[child[u][1]]][size[child[u][0]]] % MOD;
}

void init()
{
	for(int i(0); i< max_n + max_n; ++ i)
		C[i][0]= 1;
	for(int i(1); i< max_n + max_n; ++ i)
		for(int j(1); j<= i; ++ j)
		{
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			C[i][j] %= MOD;
		}
	
	freopen("t1.in", "r", stdin);
	freopen("t1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T --)
	{
		memset(child, 0, sizeof(child));
		memset(size, 0, sizeof(size));
		scanf("%d", &N);
		for(int i(1); i<= N; ++ i)
		{
			scanf("%d", &g[i][0]);
			for(int j(1); j<= g[i][0]; ++ j)
				scanf("%d", &g[i][j]);
		}
		make_graph(1);
		get_size(1);
		printf("%d\n", get_ans(1));
	}
}

int main()
{
	init();
	return 0 ;
}
