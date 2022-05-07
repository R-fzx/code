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
  static const int kN = 3e4 + 3, kM = 6e4 + 1;

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

int n1, n2, n3, m;

int main() {
  freopen("P1231_2.in", "r", stdin);
  freopen("P1231.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n1 >> n2 >> n3;
  sl.n = sl.t = (sl.s = n1 + n2 + n3 + 1) + 1;
  cin >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    sl.A(y + n1, x, 1);
  }
  cin >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    sl.A(x, y + n1 + n2, 1);
  }
  for (int i = 1; i <= n2; ++i) {
    sl.A(sl.s, i + n1, 1);
  }
  for (int i = 1; i <= n3; ++i) {
    sl.A(i + n1 + n2, sl.t, 1);
  }
  sl.S();
  cout << sl.mf;
  return 0;
}