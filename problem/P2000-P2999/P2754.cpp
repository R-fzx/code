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

struct MF {
  static const int kN = 16001, kM = 36001;
  struct E {
    int y, n, w;
  } e[kM << 1];
  struct V {
    int h, _h, d;
  } a[kN];
  int n, s, t, c = 1, q[kN], _h, _t, mf;

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
    _h = 1, _t = 0;
    for (R(s, 1); _h <= _t; ++_h) {
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
const int kM = 21, kN = 16;
struct E {
  int h;
  vector<int> l;
} e[kM];
int n, m, k, f[kN];

int F(int x) { return x == f[x] ? x : (f[x] = F(f[x])); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  n += 2;
  iota(f + 1, f + n + 1, 1);
  for (int i = 1, r; i <= m; ++i) {
    cin >> e[i].h >> r;
    for (int j = 1, x, p = 0; j <= r; ++j) {
      cin >> x;
      x += 2, e[i].l.push_back(x);
      if (p) {
        f[F(x)] = F(p);
      } else {
        p = x;
      }
    }
  }
  debug("input done\n");
  if (F(1) != F(2)) {
    cout << 0;
  } else {
    sl.s = 1, sl.t = 2, sl.n = n;
    sl.A(1, 4, k);
    int t = 1;
    for (;; ++t) {
      debug("try %d...\n", t);
      sl.n += n;
      for (int i = 1; i <= n; ++i) {
        sl.A(i + (t - 1) * n + 2, i + t * n + 2, INT16_MAX);
        debug("Connect %d and %d, weight %d\n", i + (t - 1) * n + 2, i + t * n + 2, INT16_MAX);
      }
      for (int i = 1; i <= m; ++i) {
        sl.A(e[i].l[(t - 1) % e[i].l.size()] + (t - 1) * n + 2, e[i].l[t % e[i].l.size()] + t * n + 2, e[i].h);
        debug("Connect %d and %d, weight %d\n", e[i].l[(t - 1) % e[i].l.size()] + (t - 1) * n + 2, e[i].l[t % e[i].l.size()] + t * n + 2, e[i].h);
      }
      sl.A(t * n + 3, 2, INT16_MAX);
      sl.S();
      if (sl.mf == k) {
        break;
      }
      sl.e[sl.c - 1].w = 0;
    }
    cout << t;
  }
  return 0;
}