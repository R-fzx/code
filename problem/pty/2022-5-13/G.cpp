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

const int kN = 101;

int h, w;
LL c, a[kN][kN];

int E(int x, int y) { return (x - 1) * w + y; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> h >> w >> c;
  mf_graph<LL> g(h * w + 3);
  LL s = 0;
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      cin >> a[i][j];
      s += a[i][j];
      g.add_edge(h * w + 1, E(i, j), a[i][j]);
      g.add_edge(E(i, j), i > 1 && j > 1 ? E(i - 1, j - 1) : h * w + 2, c);
      g.add_edge(E(i, j), i > 1 && j < w ? E(i - 1, j + 1) : h * w + 2, c);
    }
  }
  cout << s - g.flow(h * w + 1, h * w + 2);
  return 0;
}