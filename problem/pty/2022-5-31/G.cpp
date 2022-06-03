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

int n, m, q[kN], h = 1, t, c;
bool v[kN];
vector<int> e[kN];

void R(int x) {
  if (!v[x]) {
    v[x] = 1, ++c, q[++t] = x;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  scc_graph g(n + 1);
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    g.add_edge(x, y), e[y].push_back(x);
  }
  auto l = g.scc();
  for (auto &x : l) {
    if (x.size() > 1) {
      R(x[0]);
    }
    for (auto &i : x) {
      debug("%d ", i);
    }
    debug("\n");
  }
  for (; h <= t; ++h) {
    for (int i : e[q[h]]) {
      R(i);
    }
  }
  cout << c;
  return 0;
}