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
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1;
const string kT[4] = {"impossible", "row", "column", "both"};

template <typename F, typename C, int kN, int kM>
struct MCMF {
  struct E {
    int y, n;
    F w;
    C c;
  } e[kM << 1];
  struct V {
    int h, _h;
    C d;
    bool v;
  } a[kN];
  int n, s, t, _c = 1, q[kN], _h, _t;
  F mf;
  C mc;

  void _A(int x, int y, F w, C c) { e[++_c] = {y, a[x].h, w, c}, a[x].h = _c; }
  void A(int x, int y, F w, C c) { _A(x, y, w, c), _A(y, x, 0, -c); }
  void R(int x, C d) {
    if (a[x].d > d) {
      a[x].d = d;
      if (!a[x].v) {
        a[x].v = 1, q[_t = (_t + 1) % kN] = x;
      }
    }
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = numeric_limits<C>::max();
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
    return a[t].d < numeric_limits<C>::max();
  }
  F D(int x, F f) {
    if (x == t) {
      return f;
    }
    if (a[x].v) {
      return 0;
    }
    a[x].v = 1;
    F s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + e[i].c && (r = D(e[i].y, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r, mc += r * e[i].c;
      }
    }
    a[x].v = 0;
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, numeric_limits<F>::max())) {
    }
  }
};
MCMF<LL, LL, kN + 2, kN * 3> s1, s2;
int n, m, t, a[kN], b[kN], at;
LL s;

int main() {
  RF("tanabata");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> t;
  for (int i = 1, x, y; i <= t; ++i) {
    cin >> x >> y;
    ++a[x], ++b[y];
  }
  if (t % n == 0) {
    at |= 1;
    int p = t / n;
    // for (int i = 1; i <= n; ++i) {
    //   if (a[i] < p) {
    //     for (int j = 1; a[i] < p; ++j) {
    //       if (a[(i - j - 1 + n) % n + 1] > p) {
    //         int x = min(p - a[i], a[(i - j - 1 + n) % n + 1] - p);
    //         a[i] += x, a[(i - j - 1 + n) % n + 1] -= x;
    //       }
    //       if (a[(i + j - 1) % n + 1] > p) {
    //         int x = min(p - a[i], a[(i + j - 1) % n + 1] - p);
    //         a[i] += x, a[(i + j - 1) % n + 1] -= x;
    //       }
    //     }
    //   }
    // }
    s1.n = s1.t = (s1.s = n + 1) + 1;
    for (int i = 1; i <= n; ++i) {
      if (a[i] > p) {
        s1.A(s1.s, i, a[i] - p, 0);
      } else {
        s1.A(i, s1.t, p - a[i], 0);
      }
      s1.A(i, i % n + 1, 1e10, 1), s1.A(i, (i - 2 + n) % n + 1, 1e10, 1);
    }
    s1.S();
    s += s1.mc;
  }
  if (t % m == 0) {
    at |= 2;
    int p = t / m;
    s2.n = s2.t = (s2.s = m + 1) + 1;
    for (int i = 1; i <= m; ++i) {
      if (b[i] > p) {
        s2.A(s2.s, i, b[i] - p, 0);
      } else {
        s2.A(i, s2.t, p - b[i], 0);
      }
      s2.A(i, i % m + 1, 1e10, 1), s2.A(i, (i - 2 + m) % m + 1, 1e10, 1);
    }
    s2.S();
    s += s2.mc;
  }
  cout << kT[at];
  if (at) {
    cout << ' ' << s;
  }
  return 0;
}