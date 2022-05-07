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
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

struct MF {
  static const int kN = 403, kM = 40401;

  struct V {
    int h, _h, d;
  } a[kN];
  struct E {
    int y, n;
    LL w;
  } e[kM << 1];
  int n, s, t, c = 1, q[kN], _h, _t;
  LL mf;

  void _A(int x, int y, LL w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, LL w) { _A(x, y, w), _A(y, x, 0); }
  void R(int x, int d) {
    if (!a[x].d) {
      a[x].d = d, q[++_t] = x;
    }
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = 0;
    }
    for (_h = 1, _t = 0, R(s, 1); _h <= _t; ++_h) {
      int x = q[_h];
      for (int i = a[x].h; i; i = e[i].n) {
        if (e[i].w) {
          R(e[i].y, a[x].d + 1);
        }
      }
    }
    return a[t].d;
  }
  LL D(int x, LL f) {
    if (x == t) {
      return f;
    }
    LL s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + 1 && (r = D(e[i].y, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r;
      }
    }
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, 1e9)) {
    }
  }
} b;

const int kN = 201;

int n, m, f[kN];
LL d[kN][kN], s[kN][2], a[kN][2], t;

int F(int x) { return x == f[x] ? x : f[x] = F(f[x]); }
bool C() {
  for (int i = 1; i <= n; ++i) {
    if (s[i][0] > s[i][1]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  b.n = b.t = (b.s = n * 2 + 1) + 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i][0] >> a[i][1];
    t += a[i][0];
    b.A(b.s, i, a[i][0]), b.A(i + n, b.t, a[i][1]);
    fill_n(&d[i][1], n, 3e18), d[i][i] = 0;
  }
  iota(f + 1, f + n + 1, 1);
  for (int i = 1, x, y; i <= m; ++i) {
    LL v;
    cin >> x >> y >> v;
    d[y][x] = d[x][y] = min(d[x][y], v), f[F(x)] = F(y);
  }
  for (int i = 1; i <= n; ++i) {
    s[F(i)][0] += a[i][0], s[F(i)][1] += a[i][1];
  }
  if (C()) {
    cout << -1;
  } else {
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        debug("%lld ", d[i][j]);
      }
      debug("\n");
    }
    LL l = 0, r = 3e18;
    while (l < r) {
      LL m = l + r >> 1;
      MF sl = b;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (d[i][j] <= m) {
            sl.A(i, j + n, 1e18);
          }
        }
      }
      sl.S();
      debug("%lld %lld %lld %lld\n", l, r, m, sl.mf);
      if (sl.mf == t) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    cout << l;
  }
  return 0;
}