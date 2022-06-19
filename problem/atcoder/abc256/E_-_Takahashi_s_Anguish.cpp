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

int n, e[kN];
LL c[kN], ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  scc_graph g(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> e[i];
    g.add_edge(i, e[i]);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  auto l = g.scc();
  for (auto &i : l) {
    if (i.size() > 1) {
      LL m = 1e9;
      for (auto &j : i) {
        debug("%d ", j);
        m = min(m, c[j]);
      }
      debug("\n");
      ans += m;
    }
  }
  cout << ans;
  return 0;
}