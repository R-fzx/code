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

struct MF {
  static const int kN = 1e6 + 3, kM = 2996002;

  struct E {
    int y, n, w;
  } e[kM << 1];
  struct V {
    int h, _h, d;
  } a[kN];
  int n, s, t, c = 1, q[kN], _h, _t;
  LL mf;

  void _A(int x, int y, int w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, int w) { _A(x, y, w), _A(y, x, w); }
  bool R(int x, int d) {
    if (!a[x].d) {
      a[x].d = d, q[++_t] = x;
    }
    return x == t;
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = 0;
    }
    for (_h = 1, _t = 0, R(s, 1); _h <= _t; ++_h) {
      int x = q[_h];
      for (int i = a[x].h; i; i = e[i].n) {
        if (e[i].w && R(e[i].y, a[x].d + 1)) {
          return 1;
        }
      }
    }
    return 0;
  }
  int D(int x, int f) {
    if (x == t) {
      return f;
    }
    int s = f, r;
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
} s;

int n, m;

int E(int i, int j) { return (i - 1) * m + j; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  s.s = E(1, 1), s.n = s.t = E(n, m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, x; j < m; ++j) {
      cin >> x;
      s.A(E(i, j), E(i, j + 1), x);
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1, x; j <= m; ++j) {
      cin >> x;
      s.A(E(i, j), E(i + 1, j), x);
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1, x; j < m; ++j) {
      cin >> x;
      s.A(E(i, j), E(i + 1, j + 1), x);
    }
  }
  s.S();
  cout << s.mf;
  return 0;
}