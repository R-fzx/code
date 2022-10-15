#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std ;

const int max_n = 205 ;
const int max_m = 50005;

struct edge
{
	int s, t, a, b;
};

int f[max_n];
edge e[max_m];
int N, M, P, Q;

void init()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d%d", &N, &M, &P, &Q);
	for(int i(1); i<= M; ++ i)
		scanf("%d%d%d%d", &e[i].s, &e[i].t, &e[i].a ,&e[i].b);
}

inline bool cmp1(edge a, edge b)
{
	return a.a < b.a || a.a == b.a && a.b < b.b;
}
inline bool cmp2(edge a, edge b)
{
	return a.b < b.b || a.b == b.b && a.a < b.a;
}

int find(int x)
{
	if(!f[x])
		return x;
	return f[x] = find(f[x]);
}

void solve()
{
	int ans;
	sort(e + 1, e + 1 + M, cmp1);
	
	int ra = 0, rb = 0;
	int tot = 1;
	for(int i(1); i<= M; ++ i)
	{
		int f1 = find(e[i].s), f2 = find(e[i].t);
		if(f1 != f2)
		{
			++tot;
			f[f1] = f2;
			ra = max(ra, e[i].a);
			rb = max(rb, e[i].b);
		}
	}
	ans = (tot == N && M >= N - 1) ? ra * P + rb * Q : -1;
	
	sort(e + 1, e + 1 + M, cmp2);
	
	memset(f, 0, sizeof(f));
	ra = 0, rb = 0;
	tot = 1;
	for(int i(1); i<= M; ++ i)
	{
		int f1 = find(e[i].s), f2 = find(e[i].t);
		if(f1 != f2)
		{
			f[f1] = f2;
			ra = max(ra, e[i].a);
			rb = max(rb, e[i].b);
		}
	}
	ans = min(ans , ra * P + rb * Q);
	printf("%d\n", ans);
}

int main()
{
	init();
	solve();
	return 0 ;
}
