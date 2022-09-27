#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using mL = modint998244353;

const int kN = 2e5 + 1;

struct E {
  int x, y;
  LL w;
  bool operator<(const E &o) const { return w < o.w; }
} e[kN * 3];
int n, m, mx = 1, my = 1, f[kN];
LL x[kN], y[kN], s;

int F(int x) { return f[x] == x ? x : (f[x] = F(f[x])); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    if (x[mx] > x[i]) {
      mx = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    e[i] = {mx, i, x[i] + x[mx]};
  }
  for (int i = 1; i <= n; ++i) {
    cin >> y[i];
    if (y[my] > y[i]) {
      my = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    e[n + i] = {my, i, y[i] + y[my]};
  }
  for (int i = 1; i <= m; ++i) {
    cin >> e[2 * n + i].x >> e[2 * n + i].y >> e[2 * n + i].w;
    e[2 * n + i].w = min({e[2 * n + i].w, x[e[2 * n + i].x] + x[e[2 * n + i].y], y[e[2 * n + i].x] + y[e[2 * n + i].y]});
  }
  sort(e + 1, e + n + n + m + 1), iota(f + 1, f + n + 1, 1);
  for (int i = 1; i <= n + n + m; ++i) {
    debug("%d %d %lld\n", e[i].x, e[i].y, e[i].w);
    if (F(e[i].x) != F(e[i].y)) {
      s += e[i].w, f[F(e[i].x)] = F(e[i].y);
    }
  }
  cout << s;
  return 0;
}