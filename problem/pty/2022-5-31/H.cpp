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

const int kN = 1e5 + 1;

struct Q {
  int x, f;
  LL d;

  bool operator<(const Q &o) const { return d > o.d; }
};
int n, m, k, l, a[kN];
vector<Pii> e[kN];
LL d[kN][2];
bool v[kN];
priority_queue<Q> q;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> l;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], d[i][0] = d[i][1] = 1e18;
  }
  for (int i = 1, x; i <= l; ++i) {
    cin >> x;
    q.push({x, x, 0});
  }
  for (int i = 1, x, y, w; i <= m; ++i) {
    cin >> x >> y >> w;
    e[x].emplace_back(y, w), e[y].emplace_back(x, w);
  }
  for (Q x; !q.empty();) {
    x = q.top(), q.pop();
    if (d[x.x][a[x.x] == a[x.f]] > x.d) {
      d[x.x][a[x.x] == a[x.f]] = x.d;
    } else {
      continue;
    }
    debug("%d %d %lld\n", x.x, x.f, x.d);
    for (auto [y, w] : e[x.x]) {
      q.push({y, x.f, x.d + w});
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << (d[i][0] == 1e18 ? -1 : d[i][0]) << ' ';
  }
  return 0;
}