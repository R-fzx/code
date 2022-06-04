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
  static const int kN = 203, kM = 5001;

  struct V {
    int h, _h, d = 1;
  } a[kN];
  struct E {
    int y, n;
    LL w;
  } e[kM << 1];
  int n, s, t, c = 1, g[kN];
  LL mf;

  void _A(int x, int y, LL w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, LL w) { _A(x, y, w), _A(y, x, 0); }
  LL D(int x, LL f) {
    if (x == t) {
      return f;
    }
    LL _s = f, r;
    for (int &i = a[x]._h; _s && i; _s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d + 1 == a[x].d && (r = D(e[i].y, min(_s, e[i].w)))) {
        _s -= r, e[i].w -= r, e[i ^ 1].w += r;
      }
    }
    if (_s) {
      if (!--g[a[x].d]) {
        a[s].d = n + 1;
      }
      ++g[++a[x].d];
    }
    return f - _s;
  }
  void S() {
    g[1] = n;
    do {
      for (int i = 1; i <= n; ++i) {
        a[i]._h = a[i].h;
      }
      mf += D(s, 1e18);
    } while (a[s].d <= n);
  }
} sl;

int m;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> sl.n >> m >> sl.s >> sl.t;
  for (int i = 1; i <= sl.n; ++i) {
    sl.A(i, i + sl.n, i == sl.s || i == sl.t ? 1e9 : 1);
  }
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    sl.A(x + sl.n, y, 1e9), sl.A(y + sl.n, x, 1e9);
  }
  sl.t += sl.n, sl.n *= 2, sl.S();
  cout << sl.mf;
  return 0;
}