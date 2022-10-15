#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

const int N = 5e4 + 1, S = 5001;

struct zt {
  int l, r, to;
  bool operator>(const zt &a) const {
    return l / 200 == a.l / 200 ? r / 200 > a.r / 200 : l / 200 < a.l / 200;
  }
};

struct E {
  int f;
  zt d;
  vector<pii> e;
} v[N];

int n, m, x, y, z, s, t, a[S];

void H_D() {
  for (int i = 1; i <= n; ++i) {
    v[i].d.l = 0, v[i].d.r = 1e9;
  }
  priority_queue<zt, vector<zt>, greater<zt>> h;
  zt d;
  d.l = 1e9, d.r = 0, d.to = s;
  for (h.push({d}); !h.empty();) {
    zt p = h.top();
    h.pop();
    if (v[p.to].d > p) {
      v[p.to].d = p;
      for (pii i : v[p.to].e) {
        int zk;
        if (v[i.first].f == v[p.to].f) {
          zk = a[v[p.to].f] * 2;
        } else {
          zk = (a[v[i.first].f] + a[v[p.to].f]);
        }
        d.l = min(v[p.to].d.l, i.second * zk), d.r = max(v[p.to].d.r, i.second * zk), d.to = i.first;
        h.push(d);
      }
    }
  }
}

int main() {
  freopen("trip.in", "r", stdin);
  freopen("trip.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> x >> y >> z;
    v[x].e.push_back({y, z}), v[y].e.push_back({x, z});
  }
  for (int i = 1; i <= n; ++i) {
    cin >> t;
    for (int j = 1; j <= t; ++j) {
      cin >> x;
      v[x].f = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  n = x;
  cin >> s >> t;
  H_D();
  cout << v[t].d.l / 200 << ' ' << (v[t].d.r % 200 ? v[t].d.r / 200 + 1 : v[t].d.r / 200);
  return 0;
}