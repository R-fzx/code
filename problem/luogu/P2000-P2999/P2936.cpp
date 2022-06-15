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
  static const int kN = 259, kM = 701;

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
      if (e[i].w && a[e[i].y].d + 1 == a[x].d && (r = D(e[i].y, min(e[i].w, _s)))) {
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

int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  s.n = 256, s.s = 'A', s.t = 'Z';
  cin >> n;
  for (int i = 1, w; i <= n; ++i) {
    char x, y;
    cin >> x >> y >> w;
    s.A(x, y, w);
  }
  s.S();
  cout << s.mf;
  return 0;
}