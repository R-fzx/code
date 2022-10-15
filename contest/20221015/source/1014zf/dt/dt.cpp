#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

struct E{
	vector<ll> e;
	ll v, sum;
} e[N];

ll n, m, ans = 1e18, u, v, l[N], CoPy[N][2];

int main() {
  freopen("dt.in", "r", stdin);
  freopen("dt.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> e[i].v;
	}
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		e[u].e.push_back(v), e[v].e.push_back(u);
		e[u].sum += e[v].v, e[v].sum += e[u].v;
	}
  for (int i = 1; i <= n; i++) {
    CoPy[i][0] = e[i].v, CoPy[i][1] = e[i].sum;
  }
  iota(l + 1, l + n + 1, 1);
  do {
    ll ret = 0;
    for (int i = 1; i <= n; i++) {
      ret += e[l[i]].sum;
      for (int j : e[l[i]].e) {
        e[j].sum -= e[l[i]].v;
      }
    }
    for (int i = 1; i <= n; i++) {
      e[i].v = CoPy[i][0], e[i].sum = CoPy[i][1];
    }
    ans = min(ans, ret);
  } while (next_permutation(l + 1, l + n + 1));
  cout << ans;
	return 0;
}
