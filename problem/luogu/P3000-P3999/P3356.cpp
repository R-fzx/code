#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

struct MCMF {
  static const int kN = 2453, kM = 4903;

  struct E {
    int y, n, w, c;
  } e[kM << 1];
  struct V {
    int h, _h, d;
    bool v;
  } a[kN];
  int n, s, t, _c = 1, q[kN], _h, _t, mc, mf;

  void _A(int x, int y, int w, int c) { e[++_c] = {y, a[x].h, w, c}, a[x].h = _c; }
  void A(int x, int y, int w, int c) { _A(x, y, w, c), _A(y, x, 0, -c); }
  void R(int x, int d) {
    if (d < a[x].d) {
      a[x].d = d;
      if (!a[x].v) {
        a[x].v = 1, q[_t = (_t + 1) % kN] = x;
      }
    }
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = INT32_MAX;
    }
    for (R(s, 0); _h != _t; ) {
      int x = q[_h = (_h + 1) % kN];
      a[x].v = 0;
      for (int i = a[x].h; i; i = e[i].n) {
        if (e[i].w) {
          R(e[i].y, a[x].d + e[i].c);
        }
      }
    }
    return a[t].d != INT32_MAX;
  }
  int D(int x, int f) {
    if (x == t) {
      return f;
    }
    int s = f, r;
    a[x].v = 1;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && !a[e[i].y].v && a[e[i].y].d == a[x].d + e[i].c && (r = D(e[i].y, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r, mc += r * e[i].c;
      }
    }
    a[x].v = 0;
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, INT32_MAX)) {
    }
  }
} sl;
const int kN = 36, kD[2][2] = {{1, 0}, {0, 1}};
int c, p, q, x, e[kN][kN][2];

int Ec(int x, int y) { return (x - 1) * q + y; }
void P(int d, int x, int y) {
  if (x == p && y == q) {
    return;
  }
  if (e[x][y][0]) {
    cout << d << " 0\n";
    --e[x][y][0], P(d, x + 1, y);
  } else if (e[x][y][1]) {
    cout << d << " 1\n";
    --e[x][y][1], P(d, x, y + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> c >> q >> p;
  sl.n = p * q * 2 + 2, sl.s = sl.n - 1, sl.t = sl.n;
  sl.A(sl.s, Ec(1, 1), c, 0), sl.A(Ec(p, q) + p * q, sl.t, c, 0);
  for (int i = 1; i <= p; ++i) {
    for (int j = 1; j <= q; ++j) {
      cin >> x;
      if (x == 0) {
        sl.A(Ec(i, j), Ec(i, j) + p * q, c, 0);
      } else if (x == 1) {
        sl.A(Ec(i, j), Ec(i, j) + p * q, 0, 0);
      } else {
        sl.A(Ec(i, j), Ec(i, j) + p * q, c, 0);
        sl.A(Ec(i, j), Ec(i, j) + p * q, 1, -1);
      }
      if (i < p) {
        sl.A(Ec(i, j) + p * q, Ec(i + 1, j), c, 0);
        e[i][j][0] = sl._c;
      }
      if (j < q) {
        sl.A(Ec(i, j) + p * q, Ec(i, j + 1), c, 0);
        e[i][j][1] = sl._c;
      }
    }
  }
  sl.S();
  debug("%d %d\n", sl.mf, -sl.mc);
  for (int i = 1; i <= p; ++i) {
    for (int j = 1; j <= q; ++j) {
      e[i][j][0] = sl.e[e[i][j][0]].w;
      e[i][j][1] = sl.e[e[i][j][1]].w;
      debug("(%d,%d) ", e[i][j][0], e[i][j][1]);
    }
    debug("\n");
  }
  for (int i = 1; i <= sl.mf; ++i) {
    P(i, 1, 1);
  }
  return 0;
}