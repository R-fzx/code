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
#define _DEBUG
#ifdef _DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

struct BMF {
  static const int kN = 205, kM = 10206;

  struct E {
    int y, n;
    LL w;
  } e[kM << 1];
  struct V {
    int h, _h, d;
    LL _d;
  } a[kN];
  int n, s, t, s_, t_, c = 1, q[kN], _h, _t;
  LL mf;

  void _A(int x, int y, LL w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A_(int x, int y, LL w) { _A(x, y, w), _A(y, x, 0); }
  void A(int x, int y, LL l, LL r) { a[x]._d += l, a[y]._d -= l, A_(x, y, r - l); }
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
    int _c = c;
    A_(t_ = t, s_ = s, INT32_MAX);
    s = ++n, t = ++n;
    LL _s = 0;
    for (int i = 1; i <= n - 2; ++i) {
      if (a[i]._d > 0) {
        _s += a[i]._d, A_(i, t, a[i]._d);
      } else if (a[i]._d < 0) {
        A_(s, i, -a[i]._d);
      }
    }
    for (; B(); mf += D(s, INT32_MAX)) {
    }
    if (mf != _s) {
      mf = -1;
      return;
    }
    for (int i = c; i > _c; --i) {
      e[i].w = 0;
    }
    for (s = s_, t = t_; B(); mf += D(s, INT32_MAX)) {
    }
  }
} sl;
int m;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> sl.n >> m >> sl.s >> sl.t;
  for (int i = 1, x, y, l, r; i <= m; ++i) {
    cin >> x >> y >> l >> r;
    sl.A(x, y, l, r);
  }
  sl.S();
  if (~sl.mf) {
    cout << sl.mf;
  } else {
    cout << "please go home to sleep";
  }
  return 0;
}