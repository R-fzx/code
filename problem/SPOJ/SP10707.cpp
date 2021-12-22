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
using LD = long double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 40001, kL = 16, kM = 100001;

struct E {
  int v, f[kL], _f, _l, d;
  Vl n;
} e[kN];
int n, m, b, ans[kM], a[kN << 1], c;
struct Q {
  int i, l, r;
  bool operator<(const Q &o) const {
    return l / b != o.l / b ? l < o.l : r < o.r;
  }
} q[kM];

void D(int x, int f) {
  e[x].d = e[e[x].f[0] = f].d + 1, a[e[x]._f = ++c] = x;
  for (int i = 1; i < kL; ++i) {
    e[x].f[i] = e[e[x].f[i - 1]].f[i - 1];
  }
  for (int i : e[x].n) {
    if (i != f) {
      D(i, x);
    }
  }
  a[e[x]._l = ++c] = x;
}
int Lca(int x, int y) {
  if (e[x].d < e[y].d) {
    swap(x, y);
  }
  for (int i = 0; i < kL; ++i) {
    if (e[x].d - e[y].d >> i & 1) {
      x = e[x].f[i];
    }
  }
  for (int i = kL - 1; i >= 0; --i) {
    if (e[x].f[i] != e[y].f[i]) {
      x = e[x].f[i], y = e[y].f[i];
    }
  }
  return x == y ? x : e[x].f[0];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  b = sqrt(n);
  for (int i = 1; i <= n; ++i) {
    cin >> e[i].v;
  }
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].n.push_back(y), e[y].n.push_back(x);
  }
  D(1, 0);
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    int f = Lca(x, y);
    if (f == x) {
      swap(x, y);
    }
    if (f == y) {
      q[i] = {i, e[y]._f, e[x]._f};
    } else {
      if (e[y]._l > e[x]._f) {
        swap(x, y);
      }
      q[i] = {i, e[y]._l, e[x]._f};
    }
  }
  sort(q + 1, q + m + 1);
  for (int i = 1, l = 1, r = 0; i <= m; ++i) {

  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}