#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 50001, kM = 1e5 + 1;

struct E {
  int x, y;
  LL w;
  bool operator<(const E &o) const { return w < o.w; }
} e[kM];
int n, _n, m, c[kN], s, t, x[kN], f[kN];
LL ans[2];

int F(int x) { return x == f[x] ? x : (f[x] = F(f[x])); }

int main() {
  RF("trip");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].x >> e[i].y >> e[i].w;
  }
  for (int i = 1, l; i <= n; ++i) {
    cin >> l, _n += l;
    for (int j = 1, x; j <= l; ++j) {
      cin >> x;
      c[x] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  cin >> s >> t;
  for (int i = 1; i <= m; ++i) {
    e[i].w *= x[c[e[i].x]] + x[c[e[i].y]];
  }
  sort(e + 1, e + m + 1);
  int l = 1, r = m;
  while (l < r) {
    int x = l + r + 1 >> 1;
    iota(f + 1, f + _n + 1, 1);
    int i = x;
    for (; i <= m; ++i) {
      f[F(e[i].x)] = F(e[i].y);
      if (F(s) == F(t)) {
        break;
      }
    }
    if (F(s) == F(t)) {
      l = x;
      if (e[x].w > ans[0]) {
        ans[0] = e[x].w, ans[1] = e[i].w;
      } else if (e[x].w == ans[0] && e[i].w < ans[1]) {
        ans[1] = e[i].w;
      }
    } else {
      r = x - 1;
    }
  }
  cout << ans[0] / 200 << ' ' << (ans[1] + 199) / 200;
  return 0;
}
/*
L<=x+r<=R
L<=floor(x)

*/