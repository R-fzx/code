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
  static const int kN = 103, kM = 2601;

  struct V {
    int h, _h, d;
  } a[kN];
  struct E {
    int y, n, w;
  } e[kM << 1];
  int n, s, t, c = 1, q[kN], _h, _t, mf;

  void _A(int x, int y, int w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, int w) {
    debug("%d %d %d\n", x, y, w);
    _A(x, y, w), _A(y, x, 0);
  }
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
};

const int kN = 51;

int t, n, c, da[kN], db[kN];
bool a[kN], b[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    MF sl;
    cin >> n;
    c = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if (a[i]) {
        da[i] = ++c;
        debug("%d ", i);
      }
    }
    debug("\n");
    int _c = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> b[i];
      if (!a[i] || !b[i]) {
        db[i] = ++c, ++_c;
        debug("%d ", i);
      }
    }
    debug("\n");
    sl.n = sl.t = (sl.s = c + 1) + 1;
    debug("%d %d %d %d %d\n", _c, c, sl.n, sl.s, sl.t);
    for (int i = 1; i <= n; ++i) {
      if (da[i]) {
        sl.A(da[i], sl.t, 1);
      }
      if (db[i]) {
        sl.A(sl.s, db[i], 1);
      }
      for (int j = 1, x; j <= n; ++j) {
        cin >> x;
        if (x || i == j) {
          if (db[i] && da[j]) {
            sl.A(db[i], da[j], 1);
          }
        }
      }
    }
    sl.S();
    debug("%d\n", sl.mf);
    cout << (sl.mf == _c ? "^_^" : "T_T") << endl;
  }
  return 0;
}