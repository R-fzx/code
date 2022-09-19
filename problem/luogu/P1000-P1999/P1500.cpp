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

const int kN = 31;
const double kE = 1e-8;

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

MCMF<int, int, kN * 2 + 2, kN * kN * 2 + kN * 2> s;
int k, n, m;
Pll a[kN];
map<string, int> f;

double D(int x, int y) { return hypot(a[x].first - a[y].first, a[x].second - a[y].second); }
bool C(int x, int y) {
  for (int i = 1; i <= m; ++i) {
    if (x != i && y != i && fabs(D(x, i) + D(i, y) - D(x, y)) <= kE) {
      return 0;
    }
  }
  return 1;
}
string L(string x) {
  for (char &k : x) {
    if ('A' <= k && k <= 'Z') {
      k += 'a' - 'A';
    }
  }
  return x;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> k >> n, m = 2 * n;
  s.n = s.t = (s.s = n * 2 + 1) + 1;
  for (int i = 1; i <= n; ++i) {
    string x;
    cin >> a[i].first >> a[i].second >> x;
    f[L(x)] = i, s.A(s.s, i, 1, 0);
  }
  for (int i = n + 1; i <= m; ++i) {
    string x;
    cin >> a[i].first >> a[i].second >> x;
    f[L(x)] = i, s.A(i, s.t, 1, 0);
  }
  for (int x = 1; x <= n; ++x) {
    for (int y = n + 1; y <= m; ++y) {
      if (D(x, y) <= k && C(x, y)) {
        s.A(x, y, 1, -1);
      }
    }
  }
  for (string sx, sy; (cin >> sx) && (cin >> sy);) {
    int v, x, y;
    cin >> v;
    x = f[L(sx)], y = f[L(sy)];
    if (x > y) {
      swap(x, y);
    }
    // cout << sx << ' ' << sy << ' ' << v << ' ' << x << ' ' << y << ' ' << D(a[x].first - a[y].first, a[x].second - a[y].second) << ' ' << C(x, y) << '\n';
    if (x <= n && y > n && D(x, y) <= k && C(x, y)) {
      s.A(x, y, 1, -v);
    }
  }
  s.S();
  cout << -s.mc;
  return 0;
}