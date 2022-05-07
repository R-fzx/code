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
  static const int kN = 1001, kM = 250501;

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
} sl1, sl2;

const int kN = 501;

int n, a[kN], f[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  int s = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    f[i] = 1;
    for (int j = 1; j < i; ++j) {
      if (a[i] >= a[j]) {
        f[i] = max(f[i], f[j] + 1);
      }
    }
    s = max(s, f[i]);
    debug("%d ", f[i]);
  }
  debug("\n");
  cout << s << endl;
  if (s == 1) {
    cout << n << endl;
    cout << n;
    return 0;
  }
  sl1.n = sl1.t = (sl1.s = n * 2 + 1) + 1;
  for (int i = 1; i <= n; ++i) {
    if (f[i] == 1) {
      sl1.A(sl1.s, i, 1e7);
    }
    if (f[i] == s) {
      sl1.A(i + n, sl1.t, 1e7);
    }
    for (int j = i + 1; j <= n; ++j) {
      if (a[j] >= a[i] && f[j] == f[i] + 1) {
        sl1.A(i + n, j, 1);
      }
    }
  }
  sl2 = sl1;
  for (int i = 1; i <= n; ++i) {
    sl1.A(i, i + n, 1);
    sl2.A(i, i + n, i == 1 || i == n ? 1e7 : 1);
  }
  sl1.S();
  sl2.S();
  cout << sl1.mf << endl;
  cout << sl2.mf;
  return 0;
}