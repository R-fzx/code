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
  static const int kN = 259, kM = 1035;

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
  LL mf, mc;

  void _A(int x, int y, LL w, LL c) { e[++_c] = {y, a[x].h, w, c}, a[x].h = _c; }
  void A(int x, int y, LL w, LL c) { _A(x, y, w, c), _A(y, x, 0, -c); }
  void R(int x, LL d) {
    if (a[x].d > d) {
      a[x].d = d;
      if (!a[x].v) {
        a[x].v = 1, q[_t = (_t + 1) % kN] = x;
      }
    }
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = 1e18;
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
    return a[t].d < 1e18;
  }
  LL D(int x, LL f) {
    if (x == t) {
      return f;
    }
    if (a[x].v) {
      return 0;
    }
    a[x].v = 1;
    LL s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + e[i].c && (r = D(e[i].y, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r, mc += r * e[i].c;
      }
    }
    a[x].v = 0;
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, 1e18)) {
    }
  }
} s;
int a, b, n, m;

int E(int i, int j) { return i * (m + 1) + j + 1; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b >> n >> m;
  s.n = s.t = (s.s = E(n, m) + 1) + 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0, x; j < m; ++j) {
      cin >> x;
      s.A(E(i, j), E(i, j + 1), 1, -x), s.A(E(i, j), E(i, j + 1), 1e9, 0);
    }
  }
  for (int j = 0; j <= m; ++j) {
    for (int i = 0, x; i < n; ++i) {
      cin >> x;
      s.A(E(i, j), E(i + 1, j), 1, -x), s.A(E(i, j), E(i + 1, j), 1e9, 0);
    }
  }
  for (int i = 1, k, x, y; i <= a; ++i) {
    cin >> k >> x >> y;
    s.A(s.s, E(x, y), k, 0);
  }
  for (int i = 1, k, x, y; i <= b; ++i) {
    cin >> k >> x >> y;
    s.A(E(x, y), s.t, k, 0);
  }
  s.S();
  cout << -s.mc;
  return 0;
}