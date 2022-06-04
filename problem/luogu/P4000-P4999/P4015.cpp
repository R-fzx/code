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
#include <set>
#include <string>
#include <vector>
// #define _DEBUG
#ifdef _DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

struct MCMF {  // Min Cost Max Flow
  static const int kN = 203, kM = 10201;

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
  LL mc, mf;

  void _A(int x, int y, LL w, LL c) { e[++_c] = {y, a[x].h, w, c}, a[x].h = _c; }
  void A(int x, int y, LL w, LL c) { _A(x, y, w, c), _A(y, x, 0, -c); }
  void R(int x, LL d) {
    if (d < a[x].d) {
      a[x].d = d;
      if (!a[x].v) {
        a[x].v = 1, q[_t = (_t + 1) % kN] = x;
      }
    }
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = INT64_MAX;
    }
    for (R(s, 0); _h != _t; ) {
      int x = q[_h = (_h + 1) % kN];
      debug("  %d\n", x);
      a[x].v = 0;
      for (int i = a[x].h; i; i = e[i].n) {
        debug("    %d %lld %lld\n", e[i].y, e[i].w, e[i].c);
        if (e[i].w) {
          R(e[i].y, a[x].d + e[i].c);
        }
      }
    }
    return a[t].d != INT64_MAX;
  }
  LL D(int x, LL f) {
    if (x == t) {
      return f;
    }
    a[x].v = 1;
    LL s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && !a[e[i].y].v && a[e[i].y].d == a[x].d + e[i].c && (r = D(e[i].y, min(s, e[i].w)))) {
        e[i].w -= r, e[i ^ 1].w += r, s -= r, mc += r * e[i].c;
      }
    }
    a[x].v = 0;
    return f - s;
  }
  void S() {
    debug("Solving...\n");
    for (; B(); mf += D(s, INT64_MAX)) {
      debug("Running...\n");
    }
  }
} mi, mx;
const int kN = 101;

int n, m;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  debug("Input Start...\n");
  mi.n = n + m + 2, mi.s = n + m + 1, mi.t = n + m + 2;
  mx.n = n + m + 2, mx.s = n + m + 1, mx.t = n + m + 2;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    mi.A(mi.s, i, x, 0), mx.A(mx.s, i, x, 0);
  }
  debug("1\n");
  for (int i = 1, x; i <= m; ++i) {
    cin >> x;
    mi.A(i + n, mi.t, x, 0), mx.A(i + n, mx.t, x, 0);
  }
  debug("2\n");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, x; j <= m; ++j) {
      cin >> x;
      mi.A(i, j + n, INT32_MAX, x), mx.A(i, j + n, INT32_MAX, -x);
  debug("%d %d ok\n", i, j);
    }
  }
  debug("3\n");
  debug("Input\n");
  mi.S(), mx.S();
  cout << mi.mc << endl << -mx.mc;
  return 0;
}