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

int n, a[kN], f[kN];
vector<int> e[kN];

void D(int x, int _f, int v) {
  debug("S %d %d %d\n", x, _f, v);
  for (int i : e[x]) {
    if (i ^ _f) {
      D(i, x, v), f[x] += f[i];
    }
  }
  f[x] = max(f[x] - 1, 0) + (a[x] >= v);
  debug("E %d %d %d %d\n", x, _f, v, f[x]);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for_each_n(a + 2, n - 1, [](int &x) { cin >> x; });
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    debug("%d ", a[i]);
  }
  debug("\n");
  int l = 0, r = 1e9;
  for (int m; l != r;) {
    m = l + r + 1 >> 1;
    debug("%d %d %d\n", l, m, r);
    fill_n(f + 1, n, 0), D(1, 0, m);
    for (int i = 1; i <= n; ++i) {
      debug("%d ", f[i]);
    }
    debug("\n");
    if (f[1]) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l;
  return 0;
}