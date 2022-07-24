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

template <typename F, typename C, int kN, int kM>
struct MCMF {
  struct E {
    int y, n;
    F w;
    C c;
  } e[kM << 1];
  struct V {
    int h, _h;
    C d;
    bool v;
  } a[kN];
  int n, s, t, _c = 1, q[kN], _h, _t;
  F mf;
  C mc;

  void _A(int x, int y, F w, C c) { e[++_c] = {y, a[x].h, w, c}, a[x].h = _c; }
  void A(int x, int y, F w, C c) { _A(x, y, w, c), _A(y, x, 0, -c); }
  void R(int x, C d) {
    if (a[x].d > d) {
      a[x].d = d;
      if (!a[x].v) {
        a[x].v = 1, q[_t = (_t + 1) % kN] = x;
      }
    }
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = numeric_limits<C>::max();
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
    return a[t].d < numeric_limits<C>::max();
  }
  F D(int x, F f) {
    if (x == t) {
      return f;
    }
    if (a[x].v) {
      return 0;
    }
    a[x].v = 1;
    F s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + e[i].c && (r = D(e[i].y, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r, mc += r * e[i].c;
      }
    }
    a[x].v = 0;
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, numeric_limits<F>::max())) {
    }
  }
};
const int kN = 1e3 + 1, kM = 1e4 + 1;
MCMF<LL, LL, 2006, 4005> s;
int n, m, k, c[kN], a[kM], b[kM];
LL ans, d[kN], v[kN], t[kM], _d[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  s.n = s.t = (s.s = n * 2 + 2) + 1;
  int _s = s.s - 1;
  s.A(s.s, _s, k, 0);
  for (int i = 1; i < n; ++i) {
    cin >> _d[i];
    s.A(_s, i, _d[i], 0);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> t[i] >> a[i] >> b[i];
    v[a[i]] = max(v[a[i]], t[i]), ++c[b[i]];
  }
  for (int i = 1; i <= n; ++i) {
    d[i] = max(d[i - 1], v[i - 1]) + _d[i - 1];
  }
  for (int i = 1; i <= m; ++i) {
    ans += d[b[i]] - t[i];
  }
  for (int i = 1; i <= n; ++i) {
    s.A(i + n, i, max(d[i] - v[i], 0LL), 0);
    if (i < n) {
      s.A(i, i + 1 + n, 1e9, -c[i + 1]);
    }
    s.A(i + n, s.t, 1e9, 0);
  }
  s.S();
  cout << ans + s.mc;
  return 0;
}