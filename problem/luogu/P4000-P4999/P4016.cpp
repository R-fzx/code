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
#include <random>
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

struct MCMF {
  static const int kN = 103, kM = 301;

  struct E {
    int y, n;
    LL w, c;
  } e[kM << 1];
  struct V {
    int h, _h;
    LL d;
    bool v;
  } a[kN];
  int n, s, t, _c = 1, q[kN], _h, _t;
  LL mc, mf;

  void _A(int x, int y, LL w, LL c) { e[++_c] = {y, a[x].h, w, c}, a[x].h = _c; }
  void A(int x, int y, LL w, LL c) { _A(x, y, w, c), _A(y, x, 0, -c); }
  void R(int x, LL d) {
    if (d < a[x].d) {
      a[x].d = d;
      if (!a[x].v) {
        a[x].v = 1, q[_t = (_t + 1) % kN] = x;
      }
    }
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = 1e10;
    }
    for (R(s, 0); _h != _t;) {
      int x = q[_h = (_h + 1) % kN];
      a[x].v = 0;
      for (int i = a[x].h; i; i = e[i].n) {
        if (e[i].w) {
          R(e[i].y, a[x].d + e[i].c);
        }
      }
    }
    return a[t].d != 1e10;
  }
  LL D(int x, LL f) {
    if (x == t) {
      return f;
    }
    a[x].v = 1;
    LL s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && !a[e[i].y].v && a[e[i].y].d == a[x].d + e[i].c && (r = D(e[i].y, min(s, e[i].w)))) {
        e[i].w -= r, e[i ^ 1].w += r, s -= r, mc += r * e[i].c;
      }
    }
    a[x].v = 0;
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, 1e10)) {
    }
  }
} sl;

const int kN = 101;

int n, a[kN];
LL s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for_each_n(a + 1, n, [](int &x) { cin >> x, s += x; }), s /= n;
  debug("%lld\n", s);
  sl.n = sl.t = (sl.s = n + 1) + 1;
  for (int i = 1; i <= n; ++i) {
    sl.A(i, i % n + 1, 1e10, 1), sl.A(i, (i - 2 + n) % n + 1, 1e10, 1);
    if (a[i] > s) {
      sl.A(sl.s, i, a[i] - s, 0);
    } else {
      sl.A(i, sl.t, s - a[i], 0);
    }
  }
  sl.S();
  cout << sl.mc;
  return 0;
}