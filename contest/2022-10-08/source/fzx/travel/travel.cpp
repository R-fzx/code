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
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 201;

template <typename T, int kN, int kM>
struct MF {
  struct E {
    int y, n;
    T w;
  } e[kM << 1];
  struct V {
    int h, _h, d;
  } a[kN];
  int n, s, t, c = 1, q[kN], _h, _t;
  T mf;

  void _A(int x, int y, T w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, T w) { _A(x, y, w), _A(y, x, 0); }
  bool R(int x, int d) {
    if (!a[x].d) {
      a[x].d = d, q[++_t] = x;
    }
    return x == t;
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = 0;
    }
    for (_h = 1, _t = 0, R(s, 1); _h <= _t; ++_h) {
      int x = q[_h];
      for (int i = a[x].h; i; i = e[i].n) {
        if (e[i].w && R(e[i].y, a[x].d + 1)) {
          return 1;
        }
      }
    }
    return 0;
  }
  T D(int x, T f) {
    if (x == t) {
      return f;
    }
    T s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + 1 && (r = D(e[i].y, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r;
      }
    }
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, numeric_limits<T>::max())) {
    }
  }
};
MF<int, kN * 2 + 2, kN * (kN + 2)> s;
int n, m, p[kN];
bool l[kN][kN], v[2][kN];

void D(int x) {
  if (v[1][x]) {
    return;
  }
  v[1][x] = 1;
  for (int i = s.a[x + n].h; i; i = s.e[i].n) {
    if (!s.e[i].w && s.e[i].y != s.t) {
      int y = s.e[i].y;
      if (!v[0][y]) {
        v[0][y] = 1, p[y] && (D(p[y]), 0);
      }
    }
  }
}

int main() {
  RF("travel");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y, l[x][y] = 1;
  }
  // for (int i = 1; i <= n; ++i) {
  //   l[i][i] = 1;
  // }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        l[i][j] |= l[i][k] && l[k][j];
      }
    }
  }
  s.n = s.t = (s.s = n * 2 + 1) + 1;
  for (int i = 1; i <= n; ++i) {
    s.A(s.s, i, 1), s.A(i + n, s.t, 1);
    for (int j = 1; j <= n; ++j) {
      if (l[i][j]) {
        s.A(i, j + n, 1);
      }
    }
  }
  s.S();
  cout << n - s.mf << '\n';
  for (int i = 1; i <= n; ++i) {
    for (int j = s.a[i].h; j; j = s.e[j].n) {
      if (!s.e[j].w && s.e[j].y != s.s) {
        p[i] = s.e[j].y - n;
        break;
      }
    }
  }
  for (int i = s.a[s.t].h; i; i = s.e[i].n) {
    if (!s.e[i].w) {
      D(s.e[i].y - n);
    }
  }
  for (int i = 1; i <= n; ++i) {
    // cout << v[0][i] << ' ' << v[1][i] << '\n';
    if (!v[0][i] && v[1][i]) {
      cout << i << ' ';
    }
  }
  return 0;
}
/*

*/