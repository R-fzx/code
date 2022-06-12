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

struct BMF {
  static const int kN = 203, kM = 3e4 + 1;

  struct E {
    int y, n, w, c;
  } e[kM << 1];
  struct V {
    int h, _h, d;
    int _d;
  } a[kN];
  int n, s, t, s_, t_, _c = 1, q[kN], _h, _t, mf, mc;

  void _A(int x, int y, int w, int c) { e[++_c] = {y, a[x].h, w, c}, a[x].h = _c; }
  void A_(int x, int y, int w, int c) { _A(x, y, w, c), _A(y, x, 0, -c); }
  void A(int x, int y, int l, int r, int c) { a[x]._d -= l, a[y]._d += l, A_(x, y, r - l, c); }
  void R(int x, int d) {
    if (!a[x].d) {
      a[x].d = d, q[++_t] = x;
    }
  }
  bool B(int s, int t) {
    for (int i = 1; i <= n + 2; ++i) {
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
    return a[t].d != 0;
  }
  int D(int x, int t, int f) {
    if (x == t) {
      return f;
    }
    int s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + 1 && (r = D(e[i].y, t, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r;
      }
    }
    return f - s;
  }
  int S(int s, int t) {
    int f = 0;
    for (; B(s, t); f += D(s, t, 1e9)) {
    }
    return f;
  }
  void S() {
    int _s = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i]._d > 0) {
        _s += a[i]._d, A_(n + 1, i, a[i]._d, 0);
      } else if (a[i]._d < 0) {
        A_(i, n + 2, -a[i]._d, 0);
      }
    }
    A_(t, s, INT32_MAX, 0);
    if (S(n + 1, n + 2) != _s) {
      mf = -1;
      return;
    }
    e[_c - 1].w = 0, mf = e[_c].w, e[_c].w = 0, mf += S(s, t);
  }
} sl;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  return 0;
}