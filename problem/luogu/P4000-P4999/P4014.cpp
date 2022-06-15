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
  static const int kN = 203, kM = 10201;

  struct E {
    int y, n, w, c;
  } e[kM << 1];
  struct V {
    int h, _h, d;
    bool v;
  } a[kN];
  int n, s, t, _c = 1, q[kN], _h, _t, mf, mc;
  bool f;

  void _A(int x, int y, int w, int c) { e[++_c] = {y, a[x].h, w, c}, a[x].h = _c; }
  void A(int x, int y, int w, int c) { _A(x, y, w, c), _A(y, x, 0, -c); }
  void R(int x, int d) {
    if (f ? a[x].d < d : a[x].d > d) {
      a[x].d = d;
      if (!a[x].v) {
        q[_t = (_t + 1) % kN] = x, a[x].v = 1;
      }
    }
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = 1e9 * (f ? -1 : 1);
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
    return a[t].d != 1e9 * (f ? -1 : 1);
  }
  int D(int x, int f) {
    if (x == t) {
      return f;
    }
    if (a[x].v) {
      return 0;
    }
    a[x].v = 1;
    int s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + e[i].c && (r = D(e[i].y, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r, mc += r * e[i].c;
      }
    }
    a[x].v = 0;
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, 1e9)) {
    }
  }
} s1, s2;

int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  s1.n = s1.t = (s1.s = n + n + 1) + 1;
  for (int i = 1; i <= n; ++i) {
    s1.A(s1.s, i, 1, 0);
  }
  for (int i = n + 1; i <= n + n; ++i) {
    s1.A(i, s1.t, 1, 0);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = n + 1, x; j <= n + n; ++j) {
      cin >> x;
      s1.A(i, j, 1, x);
    }
  }
  s2 = s1, s2.f = 1, s1.S(), s2.S();
  cout << s1.mc << '\n'
       << s2.mc;
  return 0;
}