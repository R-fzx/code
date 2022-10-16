#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int kMaxN = 7e5 + 3;

struct Edge {
	int v, w;
};

int n, a[kMaxN];
vector<Edge> e[kMaxN];

int d[kMaxN], f[kMaxN];
void Dfs(int u, ll s) {
	if (!f[u]) {
		d[u] = s, f[u] = 1;
	}
	//cout << "Dfs running, u = " << u << ", s = " << s << ", d[u] = " << d[u] << endl;
	for (Edge it : e[u]) {
		int nxt = it.v;
		if (!f[nxt]) {
			ll _s = s + max(0, it.w - a[u]);
			Dfs(nxt, _s);
		}
	}
}

int p;
ll ans = 1e9;

signed main() {
	freopen("yggdrasil.in","r",stdin);
	freopen("yggdrasil.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1, _u, _v, _w; i < n; i++) {
		scanf("%d%d%d", &_u, &_v, &_w);
		e[_u].push_back((Edge) {_v, _w});
		e[_v].push_back((Edge) {_u, _w});
	}
	for (int i = 1; i <= n; i++) {
		memset(f, 0, sizeof(f));
		Dfs(i, 0);
		ll sum = 0;
		//cout << i << ": ";
		for (int j = 1; j <= n; j++) {
			sum += d[j];
			//cout << d[j] << ' ';
		}
		//cout << endl;
		if (sum < ans) {
			ans = sum, p = i;
		}
	}
	cout << p << endl << ans;
	return 0;
}
