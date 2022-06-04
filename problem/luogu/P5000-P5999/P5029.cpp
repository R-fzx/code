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
  static const int kN = 520003, kM = 6.2e6;

  struct V {
    int h, _h, d;
  } a[kN];
  struct E {
    int y, n;
    LL w;
  } e[kM << 1];
  int n, s, t, c = 1, q[kN], _h, _t;
  LL mf;

  void _A(int x, int y, LL w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, LL w) { _A(x, y, w), _A(y, x, 0); }
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
  LL D(int x, LL f) {
    if (x == t) {
      return f;
    }
    LL s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + 1 && (r = D(e[i].y, min(s, e[i].w)))) {
        e[i].w -= r, e[i ^ 1].w += r, s -= r;
      }
    }
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, INT32_MAX)) {
    }
  }
} sl;
int n, m, k;
struct S {
  int t;

  void B(int x, int l, int r) {
    if (t) {
      // Edge (x, x / 2, INT32_MAX)
      sl.A(2 * k + x, 2 * k + x / 2, INT32_MAX);
    } else {
      // Edge (x / 2, x, INT32_MAX)
      sl.A(x / 2, x, INT32_MAX);
    }
    if (l == r) {
      if (t) {
        // Edge (l, l2, INT32_MAX)
        sl.A(4 * k + l, 2 * k + x, INT32_MAX);
      } else {
        // Edge (l1, l, INT32_MAX)
        sl.A(x, 4 * k + l, INT32_MAX);
      }
      return;
    }
    int m = l + r >> 1;
    B(x * 2, l, m), B(x * 2 + 1, m + 1, r);
  }
  void C(int x, int l, int r, int tl, int tr, int w) {
    if (l == tl && r == tr) {
      if (t) {
        sl.A(2 * k + x, sl.n, w);
      } else {
        sl.A(sl.n, x, w);
      }
      return;
    }
    int m = l + r >> 1;
    if (tl <= m) {
      C(x * 2, l, m, tl, min(m, tr), w);
    }
    if (m < tr) {
      C(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, w);
    }
  }
} t[2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  sl.n = sl.t = (sl.s = 5 * k + 1) + 1;
  sl.A(sl.s, 4 * k + 1, n), sl.A(5 * k, sl.t, INT32_MAX);
  t[1].t = 1, t[0].B(1, 1, k), t[1].B(1, 1, k);
  for (int i = 1, o, l, l1, r1, l2, r2; i <= m; ++i) {
    cin >> o >> l;
    if (o == 1) {
      cin >> l1 >> l2;
      r1 = l1, r2 = l2;
    } else if (o == 2) {
      cin >> l1 >> r1 >> l2;
      r2 = l2;
    } else if (o == 3) {
      cin >> l1 >> l2 >> r2;
      r1 = l1;
    } else {
      cin >> l1 >> r1 >> l2 >> r2;
    }
    ++sl.n, t[0].C(1, 1, k, l2, r2, l), t[1].C(1, 1, k, l1, r1, l);
  }
  sl.S();
  cout << sl.mf;
  return 0;
}