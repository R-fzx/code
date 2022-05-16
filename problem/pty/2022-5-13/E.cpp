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

const int kN = 1e5 + 1;

struct E {
  int x, y;
  bool operator==(const E& b) { return x == b.x && y == b.y; }
  bool operator<(const E& b) const { return x < b.x || x == b.x && y < b.y; }
};

int h, w, n, _h = 1, _t;
E s, g;
pair<E, int> q[kN << 2];
set<E> r, c;
map<E, bool> v;

void R(E x, int d) {
  if (!v[x]) {
    debug("  %d %d %d\n", x.x, x.y, d);
    v[x] = 1, q[++_t] = {x, d};
  }
}
LL S() {
  for (R(s, 0); _h <= _t; ++_h) {
    auto x = q[_h];
    auto i = x.first;
    debug("%d %d %d\n", i.x, i.y, x.second);
    if (i == g) {
      return x.second;
    }
    auto p = r.lower_bound(i);
    debug(" %d %d\n", p->x, p->y);
    if (p->x == i.x && p->y - 1 != i.y) {
      R({p->x, p->y - 1}, x.second + 1);
    }
    --p;
    debug(" %d %d\n", p->x, p->y);
    if (p->x == i.x && p->y + 1 != i.y) {
      R({p->x, p->y + 1}, x.second + 1);
    }
    p = c.lower_bound({i.y, i.x});
    debug(" %d %d\n", p->y, p->x);
    if (p->x == i.y && p->y - 1 != i.x) {
      R({p->y - 1, p->x}, x.second + 1);
    }
    --p;
    debug(" %d %d\n", p->y, p->x);
    if (p->x == i.y && p->y + 1 != i.x) {
      R({p->y + 1, p->x}, x.second + 1);
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> h >> w >> n >> s.x >> s.y >> g.x >> g.y;
  r.insert({0, 0}), c.insert({0, 0});
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    r.insert({x, y}), c.insert({y, x});
  }
  cout << S();
  return 0;
}
/*
1 1
2 1
2 3
*/