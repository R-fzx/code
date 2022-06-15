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
#include <random>
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
  static const int kN = 405, kM = 20301;

  struct E {
    int y, n, w;
  } e[kM << 1];
  struct V {
    int h, _h, d = 1;
  } a[kN];
  int n, s, t, c = 1, g[kN];
  int mf;

  void _A(int x, int y, int w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, int w) { _A(x, y, w), _A(y, x, 0); }
  int D(int x, int f) {
    if (x == t) {
      return f;
    }
    int _s = f, r;
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
      mf += D(s, 1e9);
    } while (a[s].d <= n);
  }
} s;
int n, p, q;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> p >> q;
  s.n = s.t = (s.s = p + n + n + q + 1) + 1;
  for (int i = 1; i <= p; ++i) {
    s.A(s.s, i, 1);
  }
  for (int i = 1; i <= n; ++i) {
    s.A(p + i, p + n + i, 1);
  }
  for (int i = 1; i <= q; ++i) {
    s.A(p + n + n + i, s.t, 1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, x; j <= p; ++j) {
      cin >> x;
      if (x) {
        s.A(j, p + i, 1);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, x; j <= q; ++j) {
      cin >> x;
      if (x) {
        s.A(p + n + i, p + n + n + j, 1);
      }
    }
  }
  s.S();
  cout << s.mf;
  return 0;
}