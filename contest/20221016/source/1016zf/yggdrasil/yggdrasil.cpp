#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 7e5 + 5, inf = 1e18;

struct L{
	ll t, l;
	bool operator<(const L &_l) const { return l > _l.l; } 
};

struct E{
	vector<L> e;
	ll d = inf, size;
} e[N];
priority_queue<L> q;

ll ans = inf, res, ansi = 1, n, a[N], b, c, d;

void Dijkstra() { // (n + m) log n
	for (q.push({1, 0}); !q.empty(); ) {
		L p = q.top();
		q.pop();
		if (p.l < e[p.t].d) {
			e[p.t].d = p.l;
			for (L i : e[p.t].e) {
				q.push({i.t, i.l + p.l - a[p.t]});
			}
		}
	}
  for (int i = 1; i <= n; i++) {
    res += e[i].d;
  }
}

void dfs(int id, int fa) { // O(n)
  e[id].size = 1;
  for (L i : e[id].e) {
    if (i.t != fa) {
      dfs(i.t, id);
      e[id].size += e[i.t].size;
    }
  }
}

void Walk(int id, int fa, ll v) { // O(n)
  if (v < ans || (v == ans && id < ansi)) {
    ans = v, ansi = id;
  }
  for (L i : e[id].e) {
    if (i.t != fa) {
      Walk(i.t, id, v - (i.l - a[id]) * e[i.t].size + (n - e[i.t].size) * (i.l - a[i.t]));
    }
  }
}

int main() {
	freopen("yggdrasil.in", "r", stdin);
	freopen("yggdrasil.out", "w", stdout);
  ios :: sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> b >> c >> d;
		e[b].e.push_back({c, d});
		e[c].e.push_back({b, d});
	}
  Dijkstra();
  dfs(1, 0);
  Walk(1, 0, res);
  cout << ansi << '\n' << ans << '\n';
	// cout << "Time uses:" << (double) clock() / CLOCKS_PER_SEC;
  return 0;
} 
