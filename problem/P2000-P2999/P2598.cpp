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

struct MF {
  static const int kN = 10003, kM = 50001;

  struct V {
    int h, _h, d;
  } a[kN];
  struct E {
    int y, n, w;
  } e[kM << 1];
  int n, s, t, c = 1, q[kN], _h, _t;
  int mf;

  void _A(int x, int y, int w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
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
} sl;
const int kD[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;

int E(int x, int y) { return (x - 1) * m + y; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  sl.n = sl.t = (sl.s = n * m + 1) + 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, x; j <= m; ++j) {
      cin >> x;
      if (x == 1) {
        sl.A(sl.s, E(i, j), 1e7);
      } else if (x == 2) {
        sl.A(E(i, j), sl.t, 1e7);
      }
      for (int k = 0; k < 4; ++k) {
        int ni = i + kD[k][0], nj = j + kD[k][1];
        if (ni > 0 && ni <= n && nj > 0 && nj <= m) {
          sl.A(E(i, j), E(ni, nj), 1);
        }
      }
    }
  }
  sl.S();
  cout << sl.mf;
  return 0;
}