#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using db = double;
using Pii = pair<int, int>;
using Pddi = pair<db, pair<db, int> >;

const int N = 1e5 + 5;

int n, m, c[N], y[N], s, t;
db d[N], r[N];
vector<Pii> e[N];

void D() {
  priority_queue<Pddi> q;
  fill(d + 1, d + n + 1, -1e9);
  fill(r + 1, r + n + 1, 1e9);
  for (q.push({1e9, {-1e9, s}}); q.size();) {
    Pddi x = q.top();
    q.pop();
    if (x.second.second == t && d[t] > x.first) {
      return;
    }
    if (d[x.second.second] < x.first) {
      r[x.second.second] = x.second.first;
      d[x.second.second] = x.first;
      for (Pii i : e[x.second.second]) {
        q.push({min(i.second * (y[c[i.first]] + y[c[x.second.second]]) / 200.0, x.first), {max(x.second.first, i.second * (y[c[i.first]] + y[c[x.second.second]]) / 200.0), i.first}});
      }
    } else if (d[x.second.second] == x.first && r[x.second.second] > x.second.first) {
      r[x.second.second] = x.second.first;
      for (Pii i : e[x.second.second]) {
        q.push({min(i.second * (y[c[i.first]] + y[c[x.second.second]]) / 200.0, x.first), {max(x.second.first, i.second * (y[c[i.first]] + y[c[x.second.second]]) / 200.0), i.first}});
      }
    }
  }
}

int main() {
  freopen("trip.in", "r", stdin);
  freopen("trip.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }
  for (int i = 1, l; i <= n; i++) {
    cin >> l;
    for (int x; l--; c[x] = i) {
      cin >> x;
    }
  }
  for (int i = 1, l; i <= n; i++) {
    cin >> y[i];
  }
  cin >> s >> t;
  D();
  cout << (int)d[t] << ' ' << (int)(r[t] + (r[t] != d[t]));
  return 0;
}
/*

*/