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
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

struct Dinic {
  static const int kN = 1501, kM = 30001;

  struct E {
    int y, n, w;
  } e[kM << 1];
  struct V {
    int h, d, c;
  } a[kN];
  int n, s, t, q[kN], _h, _t, c = 1;

  void C() {
    c = 1;
    for (int i = 1; i <= n; ++i) {
      a[i].h = 0;
    }
  }
  void _A(int x, int y, int w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, int w) { _A(x, y, w), _A(y, x, 0); }
  bool R(int x, int d) {
    if (!a[x].d) {
      a[x].d = d, q[++_t] = x;
    }
    return x == t;
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i].d = 0, a[i].c = a[i].h;
    }
    for (_h = 1, _t = 0, R(s, 1); _h <= _t; ++_h) {
      for (int i = a[q[_h]].h; i; i = e[i].n) {
        if (e[i].w && R(e[i].y, a[q[_h]].d + 1)) {
          return 1;
        }
      }
    }
    return 0;
  }
  int D(int x, int b) {
    if (x == t) {
      return b;
    }
    int s = b, f;
    for (int &i = a[x].c; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + 1 && (f = D(e[i].y, min(s, e[i].w)))) {
        e[i].w -= f, e[i ^ 1].w += f, s -= f;
      }
    }
    return b - s;
  }
  int S() {
    int ans = 0;
    for (; B(); ans += D(s, INT32_MAX)) {
    }
    return ans;
  }
} sl;

const int kN = 1001, kB = 21;

int n, b, a[kN][kB], c[kB];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> b;
  sl.n = n + b + 2, sl.s = 1, sl.t = 2;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= b; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= b; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < b; ++i) {
    for (int j = 1, k; (k = j + i) <= b; ++j) {
      // cout << i << " " << j << " " << k << endl;
      sl.C();
      for (int x = 1; x <= n; ++x) {
        sl.A(sl.s, x + 2, 1);
        for (int y = j; y <= k; ++y) {
          sl.A(x + 2, a[x][y] + n + 2, INT32_MAX);
        }
      }
      for (int x = 1; x <= b; ++x) {
        sl.A(x + n + 2, sl.t, c[x]);
      }
      if (sl.S() == n) {
        cout << i + 1;
        return 0;
      }
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}