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

struct MF {
  static const int kN = 4e4 + 3, kM = 4e5 + 1;

  struct E {
    int y, n, w;
  } e[kM << 1];
  struct V {
    int h, _h, d;
  } a[kN];
  int n, s, t, c = 1, q[kN], _h, _t, mf;

  void _A(int x, int y, int w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, int w) { _A(x, y, w), _A(y, x, 0); }
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

const int kN = 201, kD[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int n, m;
bool v[kN][kN];

int E(int i, int j) { return (i - 1) * n + j; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  s.n = s.t = (s.s = n * n + 1) + 1;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    v[x][y] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (!v[i][j]) {
        if (i + j & 1) {
          s.A(s.s, E(i, j), 1);
          for (int k = 0; k < 8; ++k) {
            int x = i + kD[k][0], y = j + kD[k][1];
            if (min(x, y) >= 1 && max(x, y) <= n && !v[x][y]) {
              s.A(E(i, j), E(x, y), 1e9);
            }
          }
        } else {
          s.A(E(i, j), s.t, 1);
        }
      }
    }
  }
  s.S();
  cout << n * n - m - s.mf;
  return 0;
}