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
LL d[kN];
bool v[kN];
priority_queue<Q> q;

void R(int x, int f, LL _d) {
  if (a[x] == a[f]) {
    if (v[x]) {
      return;
    }
    v[x] = 1, q.push({x, f, _d});
  } else {
    if (_d < d[x]) {
      d[x] = _d, q.push({x, f, _d});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> l;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], d[i] = 1e18;
  }
  for (int i = 1, x; i <= l; ++i) {
    cin >> x;
    R(x, x, 0);
  }
  for (int i = 1, x, y, w; i <= m; ++i) {
    cin >> x >> y >> w;
    e[x].emplace_back(y, w), e[y].emplace_back(x, w);
  }
  for (Q x; !q.empty(); ) {
    x = q.top(), q.pop();
    debug("%d %d %lld\n", x.x, x.f, x.d);
    for (auto [y, w] : e[x.x]) {
      R(y, x.f, x.d + w);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << (d[i] == 1e18 ? -1 : d[i]) << ' ';
  }
  return 0;
}