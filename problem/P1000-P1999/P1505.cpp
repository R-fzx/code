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
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1, kS[5] = {0, 0, 0, INT32_MAX, INT32_MIN};
const function<int(int, int)> kF[5] = {[](int x, int y) { return x; }, [](int x, int y) { return x; }, [](int x, int y) { return x + y; }, [](int x, int y) { return min(x, y); }, [](int x, int y) { return max(x, y); }};

struct V {
  int v, f, h, t, p, s, d;
  vector<Pii> n;
  vector<int> _;
} a[kN];
struct T {
  int s, m[2], n;
} e[kN << 2];
int n, q, c, x, y, m[kN];
string o;

void D(int x, int f) {
  a[x].f = f, a[x].s = 1, a[x].d = a[f].d + 1;
  for (int i = 0; i < a[x].n.size(); ++i) {
    int j = a[x].n[i].first;
    if (j ^ f) {
      a[j].v = a[x].n[i].second, m[a[x]._[i]] = j, D(j, x), a[x].s += a[j].s, a[j].s > a[a[x].h].s && (a[x].h = j);
    }
  }
}
void H(int x, int t) {
  if (x) {
    a[x].t = t, a[x].p = ++c, H(a[x].h, t);
    for (auto [i, _] : a[x].n) {
      if (i != a[x].f && i != a[x].h) {
        H(i, i);
      }
    }
  }
}
void Neg(int x) { e[x] = {-e[x].s, {-e[x].m[1], -e[x].m[0]}, e[x].n ^ 1}; }
int Do(int ty, int x, int l, int r, int tl, int tr, int v = 0) {
  if (l == tl && r == tr) {
    if (ty == 1) {
      e[x].s = e[x].m[0] = e[x].m[1] = v;
      return 0;
    } else if (ty == 2) {
      Neg(x);
      return 0;
    } else if (ty == 3) {
      return e[x].s;
    } else {
      return e[x].m[ty - 4];
    }
  }
  if (e[x].n) {
    Neg(x * 2), Neg(x * 2 + 1), e[x].n = 0;
  }
  int m = l + r >> 1, s = kS[ty - 1];
  if (tl <= m) {
    s = kF[ty - 1](s, Do(ty, x * 2, l, m, tl, min(m, tr)));
  }
  if (m < tr) {
    s = kF[ty - 1](s, Do(ty, x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
  }
  e[x] = {e[x * 2].s + e[x * 2 + 1].s, {min(e[x * 2].m[0], e[x * 2 + 1].m[0]), max(e[x * 2].m[1], e[x * 2 + 1].m[1])}, e[x].n};
  return s;
}
int S(int o, int x, int y) {
  int s = kS[o - 1];
  for (; a[x].t != a[y].t; ) {
    if (a[a[x].t].d < a[a[y].t].d) {
      swap(x, y);
    }
    s = kF[o - 1](s, Do(o, 1, 1, n, a[a[x].t].p, a[x].p)), x = a[a[x].t].f;
  }
  if (a[x].d > a[y].d) {
    swap(x, y);
  }
  return kF[o - 1](s, Do(o, 1, 1, n, a[x].p + 1, a[y].p));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x, y, v; i < n; ++i) {
    cin >> x >> y >> v;
    ++x, ++y;
    a[x].n.emplace_back(y, v), a[y].n.emplace_back(x, v), a[x]._.push_back(i), a[y]._.push_back(i);
  }
  D(1, 0), H(1, 1);
  for (int i = 1; i <= n; ++i) {
    Do(1, 1, 1, n, i, i, a[i].v);
  }
  cin >> q;
  while (q--) {
    cin >> o >> x >> y;
    if (o == "C") {
      Do(1, 1, 1, n, m[x], m[x], y);
    } else if (o == "N") {
      S(2, m[x], m[y]);
    } else if (o == "SUM") {
      cout << S(3, m[x], m[y]) << endl;
    } else if (o == "MIN") {
      cout << S(4, m[x], m[y]) << endl;
    } else {
      cout << S(5, m[x], m[y]) << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}