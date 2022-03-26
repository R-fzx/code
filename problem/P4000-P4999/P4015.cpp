#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
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
// #define TIME

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
    int h, c;
    LL d;
    bool v;
  } a[kN];
  int n, s, t, v, _h, _t, q[kN], _c = 1;

  void _A(int x, int y, LL w, LL c) { e[++_c] = {y, a[x].h, w, c}, a[x].h = _c; }
  void A(int x, int y, LL w, LL c) { _A(x, y, w, c), _A(y, x, 0, -c); }
  void R(int x, LL d) {
    if (d * v < a[x].d * v) {
      a[x].d = d;
      if (!a[x].v) {
        a[x].v = 1, q[_t = (_t + 1) % kN] = x;
      }
    }
  }
  bool B() {
    // fprintf(stderr, "  B() Start.\n");
    for (int i = 1; i <= n; ++i) {
      a[i].c = a[i].h, a[i].d = INT32_MAX * v;
    }
    for (_h = _t = 0, R(s, 0); _h != _t;) {
      int x = q[_h = (_h + 1) % kM];
      a[x].v = 0;
      for (int i = a[x].h; i; i = e[i].n) {
        if (e[i].w) {
          R(e[i].y, a[x].d + e[i].c);
        }
      }
    }
    // fprintf(stderr, "  B() End.\n");
    // for (int i = 1; i <= n; ++i) {
    //   fprintf(stderr, "%d ", a[i].d);
    // }
    // fprintf(stderr, "\n");
    return a[t].d != INT32_MAX * v;
  }
  using A_t = complex<LL>;
  LL D(int x, LL b, int _t = 1) {
    // for (int i = 0; i < _t; ++i) {
    //   fprintf(stderr, "  ");
    // }
    // fprintf(stderr, "D(%d, %lld) Start.\n", x, b);
    if (x == t) {
    // for (int i = 0; i < _t; ++i) {
    //   fprintf(stderr, "  ");
    // }
    // fprintf(stderr, "D(%d, %lld) End.\n", x, b);
      return b;
    }
    if (a[x].v) {
      return 0;
    }
    a[x].v = 1;
    LL s = b, f;
    for (int &i = a[x].c; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + e[i].c && (f = D(e[i].y, min(s, e[i].w), _t + 1))) {
        s -= f, e[i].w -= f, e[i ^ 1].w += f;
      }
    }
    a[x].v = 0;
    // for (int i = 0; i < _t; ++i) {
    //   fprintf(stderr, "  ");
    // }
    // fprintf(stderr, "D(%d, %lld) End.\n", x, b);
    return b - s;
  }
  Pll S() {
    // fprintf(stderr, "test\n");
    Pll ans = {0, 0};
    for (int v; B(); v = D(s, INT32_MAX, 0), ans.first += v, ans.second += v * a[t].d) {
    }
    return ans;
  }
} mi, mx;
int n, m, a[MCMF::kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  mi.v = 1, mi.n = n + m + 2, mi.s = n + m + 1, mi.t = n + m + 2;
  // cerr << "d1" << endl;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    mi.A(mi.s, i, x, 0);
  }
  // cerr << "d2" << endl;
  for (int i = 1, x; i <= m; ++i) {
    cin >> a[i];
    mi.A(i + n, mi.t, a[i], 0);
  }
  // cerr << "d3" << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, x; j <= m; ++j) {
      cin >> x;
      mi.A(i, j + n, a[j], x);
    }
  }
  mx = mi, mx.v = -1;
  // cerr << "d4" << endl;
  cout << mi.S().second << endl
       << mx.S().second;
  // cerr << "d5" << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*

*/