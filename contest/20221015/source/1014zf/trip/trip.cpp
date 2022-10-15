#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 5005, C = 5e4 + 5, M = 1e5 + 5;

struct L{
  ll t, l;
  ld nw;
};

struct LI{
  ll b, e;
  ld c;
} a[M];

vector<L> e[C];
ll n, m, s, t, ci, bin, ed, v, cnt, p, l, li, r;
ll x[N], fnd[C], fa[C];

int R(int x) {
  return fa[x] == x ? x : fa[x] = R(fa[x]);
}

int main() {
  freopen("trip.in", "r", stdin);
  freopen("trip.out", "w", stdout);
  ios :: sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) { // O(m)
    cin >> bin >> ed >> v;
    e[bin].push_back({ed, v});
    cnt = max(bin, cnt), cnt = max(ed, cnt);
  }
  for (int i = 1; i <= n; i++) { // O(C)
    cin >> t;
    for (int j = 1; j <= t; j++) {
      cin >> ci;
      fnd[ci] = i;
    }
  }
  for (int i = 1; i <= n; i++) { // O(n)
    cin >> x[i];
  }
  cin >> s >> t;
  for (int i = 1; i <= cnt; i++) { // O(m)
    for (int j = 0; j < e[i].size(); j++) {
      e[i][j].nw = (ld) e[i][j].l * (ld)(x[fnd[i]] + x[fnd[e[i][j].t]]) / 200;
      a[++p] = {i, e[i][j].t, e[i][j].nw};
    }
  }
  sort(a + 1, a + p + 1, [] (LI x, LI y) { return x.c < y.c; }); // O(m log m)
  iota(fa + 1, fa + cnt + 1, 1);
  for (int i = p; i >= 1; i--) {
    int g1 = R(a[i].b), g2 = R(a[i].e);
    if (g1 != g2) {
      fa[g1] = g2;
    }
    if (R(s) == R(t)) {
      l = a[i].c, li = i;
      break;
    }
  }
  iota(fa + 1, fa + cnt + 1, 1);
  for (int i = li; i <= p; i++) {
    int g1 = R(a[i].b), g2 = R(a[i].e);
    if (g1 != g2) {
      fa[g1] = g2;
    }
    if (R(s) == R(t)) {
      r = ceil(a[i].c);
      break;
    }
  }
  cout << l << ' ' << r;
  return 0;
}