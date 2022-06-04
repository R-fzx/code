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
#define _DEBUG
#ifdef _DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

struct MCMF {
  static const int kN = 4003, kM = 12001;

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
  LL mf, mc;

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
      a[i].d = 1e18, a[i]._h = a[i].h;
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
    return a[t].d != 1e18;
  }
  LL D(int x, LL f) {
    if (x == t) {
      return f;
    }
    LL s = f, r;
    a[x].v = 1;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && !a[e[i].y].v && a[e[i].y].d == a[x].d + e[i].c && (r = D(e[i].y, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r, mc += r * e[i].c;
      }
    }
    a[x].v = 0;
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, 1e18)) {
    }
  }
} sl;
int n, x, y;

int main() {
  // freopen("P1251_2.in", "r", stdin);
  // freopen("P1251.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  sl.n = n * 2 + 2, sl.s = n * 2 + 1, sl.t = n * 2 + 2;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    sl.A(sl.s, i + n, x, 0), sl.A(i, sl.t, x, 0);
    if (i < n) {
      sl.A(i + n, i + 1 + n, INT32_MAX, 0);
    }
  }
  cin >> x;
  for (int i = 1; i <= n; ++i) {
    sl.A(sl.s, i, INT32_MAX, x);
  }
  cin >> x >> y;
  for (int i = 1; i + x <= n; ++i) {
    sl.A(i + n, i + x, INT32_MAX, y);
  }
  cin >> x >> y;
  for (int i = 1; i + x <= n; ++i) {
    sl.A(i + n, i + x, INT32_MAX, y);
  }
  sl.S();
  cout << sl.mc;
  return 0;
}