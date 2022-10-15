#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int, int>;
const int kMaxN = 5e4 + 1, kMaxM = 5e3 + 1, kMaxL = 12;
int n, m, x[kMaxM], ss, tt, ml = -1, mr = 1e9;
int g[kMaxN];
struct node {
  vector<Pii> e;
  bool f;
} s[kMaxN];
struct node1 {
  int l, v[kMaxL];
} t[kMaxM];
void F(int sx, int ex, int l, int r, double tot) {
  if (s[sx].f) {
    return;
  }
  s[sx].f = 1;
  if (sx == ex) {
    if (ml < l || (ml == l && mr > r)) {
      ml = l, mr = r;
    }
    return;
  }
  for (Pii i : s[sx].e) {
    if (g[sx] == g[i.first]) {
      double p = tot + 1.0 * i.second * x[g[i.first]] / (100 * 1.0);
      F(i.first, ex, min(l, (int)p), max(r, (int)p + 1), p);
    } else {
      double p = tot + 1.0 * i.second * 1.0 * (x[g[i.first]] + x[g[sx]]) / (100 * 1.0) / (2 * 1.0);
      F(i.first, ex, min(l, (int)p), max(r, (int)p + 1), p);
    }
  }
  s[sx].f = 0;
}
int main() {
  freopen("trip.in", "r", stdin);
  freopen("trip.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1, a, b, c; i <= m; i++) {
    cin >> a >> b >> c;
    s[a].e.push_back({b, c});
    s[b].e.push_back({a, c});
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i].l;
    for (int j = 1; j <= t[i].l; j++) {
      cin >> t[i].v[j];
      g[t[i].v[j]] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  cin >> ss >> tt;
  // F(ss, tt, 1e9, -1, 0);
  // cout << ml << " " << mr;
  cout << 0 << " " << 0;
  return 0;
}