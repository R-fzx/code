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

const LL kI = 1e14;

int h, w, n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> h >> w >> n;
  mcf_graph<int, LL> g(h + w + 3);
  g.add_edge(h + w + 1, h + w + 2, n, 2 * kI);
  for (int i = 1; i <= h; ++i) {
    g.add_edge(h + w + 1, i, 1, 0), g.add_edge(h + w + 1, i, n - 1, kI);
  }
  for (int i = 1; i <= w; ++i) {
    g.add_edge(h + i, h + w + 2, 1, 0), g.add_edge(h + i, h + w + 2, n - 1, kI);
  }
  for (int i = 1, a, b, x; i <= n; ++i) {
    cin >> a >> b >> x;
    g.add_edge(a, h + b, 1, x);
  }
  auto p = g.flow(h + w + 1, h + w + 2, n);
  debug("%d %lld\n", p.first, p.second);
  cout << p.second - (n * 2 - h - w) * kI;
  return 0;
}