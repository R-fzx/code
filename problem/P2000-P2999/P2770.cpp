#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

struct MCMF {
  static const int kN = 203, kM = 5053;
  
  struct E {
    int y, n, w, c;
  } e[kM << 1];
  struct V {
    int h, _h, d;
    bool v;
  } a[kN];
  int n, s, t, _c = 1, q[kN], _h, _t;
  LL mc, mf;

  void _A(int x, int y, int w, int c) { e[++_c] = {y, a[x].h, w, c}, a[x].h = _c; }
  void A(int x, int y, int w, int c) { _A(x, y, w, c), _A(y, x, 0, -c); }
  void R(int x, int d) {
    if (a[x].d > d) {
      a[x].d = d;
      if (!a[x].v) {
        a[x].v = 1, q[_t = (_t + 1) % kN] = x;
      }
    }
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = INT32_MAX;
    }
    for (R(s, 0); _h != _t; ) {
      int x = q[_h = (_h + 1) % kN];
      a[x].v = 0;
      for (int i = a[x].h; i; i = e[i].n) {
        if (e[i].w) {
          R(e[i].y, a[x].d + e[i].c);
        }
      }
    }
    return a[t].d != INT32_MAX;
  }
  int D(int x, int f) {
    if (x == t) {
      return f;
    }
    int s = f, r;
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
    for (; B(); mf += D(s, INT32_MAX)) {
    }
  }
  void _P(int x, bool p = 1) {

  }
} sl;
const int kN = 101;
int n, m, d[kN];
string a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sl.n = n * 2 + 2, sl.s = n * 2 + 1, sl.t = n * 2 + 2;
  sl.A(1, n + 1, 2, 1), sl.A(sl.s, 1, 2, 0);
  sl.A(n, n + n, 2, 1), sl.A(n + n, sl.t, 2, 0);
  for (int i = 2; i < n; ++i) {
    sl.A(i, i + n, 1, 1);
  }
  for (int i = 1; i <= m; ++i) {
    string _x, _y;
    cin >> _x >> _y;
    int x = find(a + 1, a + n + 1, _x) - a, y = find(a + 1, a + n + 1, _y) - a;
    if (x > y) {
      swap(x, y);
    }
    sl.A(x + n, y, 1, 0);
  }
  sl.S();
  debug("%d %d\n", sl.mf, sl.mc);
  if (sl.mc <= 2) {
    cout << "No Solution!";
  } else {
    cout << sl.mc - 2 << endl;
    sl._P(1), sl._P(n, 0);
  }
  return 0;
}