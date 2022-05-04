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

const int kN = 21;

struct MF {
  static const int kN = 803, kM = 20401;

  struct V {
    int h, _h, d;
  } a[kN];
  struct E {
    int y, w, n;
  } e[kM << 1];
  int n, s, t, c = 1, q[kN], _h, _t, mf;

  void _A(int x, int y, int w) { e[++c] = {y, w, a[x].h}, a[x].h = c; }
  void A(int x, int y, int w) { _A(x, y, w), _A(y, x, 0); }
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
    for (; B(); mf += D(s, INT32_MAX)) {
    }
  }
} s;
int r, c, d;
char ch;

int E(int x, int y) { return (x - 1) * c + y; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> r >> c >> d;
  s.n = s.t = (s.s = r * c * 2 + 1) + 1;
  debug("%d\n", E(r, c));
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      cin >> ch;
      s.A(E(i, j), E(i, j) + r * c, ch - '0');
      debug("%d %d:\n", i, j);
      bool f = 0;
      for (int k = max(0, i - d); k <= min(r + 1, i + d); ++k) {
        for (int l = max(0, j - d); l <= min(c + 1, j + d); ++l) {
          if ((k - i) * (k - i) + (l - j) * (l - j) <= d * d) {
          debug("  %d %d\n", k, l);
            if (!k || k == r + 1 || !l || l == c + 1) {
              !f && (s.A(E(i, j) + r * c, s.t, 1e5), 0), f = 1;
            } else {
              s.A(E(i, j) + r * c, E(k, l), 1e5);
            }
          }
        }
      }
    }
  }
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      cin >> ch;
      if (ch == 'L') {
        --s.mf, s.A(s.s, E(i, j), 1);
      }
    }
  }
  s.S();
  cout << -s.mf;
  return 0;
}