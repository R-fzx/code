#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
	return f ? -x : x;	
}
const int maxn = 1e6 + 5, INF = 1e16 + 7, mod = (1ll << 31) - 1;
int n, m;
struct node {
	int v, nex;
	int w;
}edge[maxn];
int head[maxn], len, Answer = 1;
int Dist[maxn], Vst[maxn], f[maxn];
inline void make_map(int u, int v, int w) {
	len++;
	edge[len].nex = head[u];
	edge[len].v = v;
	edge[len].w = w;
	head[u] = len;
}
inline void Dijstra(int op) {
	fill(Vst + 1, Vst + n + 1, 0);
	if(!op) for(register int i = 1; i <= n; ++i) Dist[i] = INF; 
	priority_queue < pair<int, int> > Q;
	Q.push(make_pair(0, 1)), Dist[1] = 0, f[1] = 1;
	while(!Q.empty()) {
		int x = Q.top().second; Q.pop();
		if(Vst[x]) continue;
		Vst[x] = 1;
		for(register int i = head[x]; i; i = edge[i].nex) {
			int y = edge[i].v, z = edge[i].w;
			if(Dist[y] >= Dist[x] + z) {
				Dist[y] = Dist[x] + z;
				if(op) f[y]++;
				Q.push(make_pair(-Dist[y], y));
			}
		}
	}
}
signed main() {
	freopen("Castle.in", "r", stdin);
	freopen("Castle.out", "w", stdout);
	n = read(), m = read();
	for(register int i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		make_map(u, v, w), make_map(v, u, w);
	}
	Dijstra(0), Dijstra(1);
	for(register int i = 1; i <= n; ++i) Answer = (Answer * f[i]) % mod;
	printf("%lld\n", Answer);
	return 0;
}
