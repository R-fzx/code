#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
	return f ? -x : x;
}
const int maxn = 1e5 + 5;
int n, m;
struct node {
	int v, nex;
}edge[maxn << 1];
int head[maxn], len, Ru[maxn], Chu[maxn], f[maxn];
inline void make_map(int u, int v) {
	len++;
	edge[len].nex = head[u];
	edge[len].v = v;
	head[u] = len;
}
inline void Tuopu() {
	queue <int> Q;
	for(register int i = 1; i <= n; ++i)
		if(!Ru[i]) Q.push(i), f[i] = 1;
	while(!Q.empty()) {
		int x = Q.front(); Q.pop();
		for(register int i = head[x]; i; i = edge[i].nex) {
			int y = edge[i].v;
			f[y] += f[x], Ru[y]--;
			if(!Ru[y]) Q.push(y);
		}
	}
}
int main() {
	freopen("lyx.in", "r", stdin);
	freopen("lyx.out", "w", stdout);
	n = read(), m = read();
	for(register int i = 1; i <= m; ++i) {
		int u = read(), v = read();
		make_map(u, v), Ru[v]++, Chu[u]++;
	}
	Tuopu();
	int Answer = 0;
	for(register int i = 1; i <= n; ++i)
		if(!Chu[i]) Answer += f[i];
	printf("%d\n", Answer);
	return 0;
}