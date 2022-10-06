#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) x = (x * 10) + (c ^ 48),c  = getchar();
	return f ? -x : x;
}
const int maxn = 2 * 1e5 + 5, mod = 1e9 + 7; 
int n, m;
int Father[maxn], Answer = 0;
inline int Find(int x) {
	if(Father[x] != x) return Father[x] = Find(Father[x]);
	return Father[x];
}
inline void Unnion(int u, int v) {
	int f1 = Find(u), f2 = Find(v);
	if(f1 != f2) Father[f2] = f1;
}
signed main() {
	freopen("magician.in", "r", stdin);
	freopen("magician.out", "w", stdout);
	n = read(), m = read();
	for(register int i = 1; i <= n; ++i) Father[i] = i;
	for(register int i = 1; i <= m; ++i) {
		int u = read(), v = read();
		if(Find(u) != Find(v)) printf("%lld\n", Answer);
		else Answer = (Answer << 1ll | 1ll) % mod, printf("%lld\n", Answer);
		Unnion(u, v);
	}
	return 0;
}
