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

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kS = 5e5;

int t, n, m, k, s, a[8][8], p5[9];
LL f[9][kS], p[9][8];

void C(LL &x, LL v) { x = min(x, v); }
int G(int x, int i) { return x / p5[i] % 5; }
int S(int x, int i, int j) { return x + p5[i] * ((j == 1) + 1); }

int main() {
  // freopen("tile3.in", "r", stdin), freopen("tile.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  p5[0] = 1;
  for (int i = 1; i < 9; ++i) {
    p5[i] = p5[i - 1] * 5;
  }
  for (cin >> t; t--;) {
    cin >> n >> m >> k, s = p5[m];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    fill(p[0], p[10], 1e15);
    // debug("input1 over\n");
    for (int o, c, x, y, z; k--;) {
      cin >> o >> c >> x;
      if (o == 1) {
        C(p[0][x], c);
      } else if (o == 2) {
        cin >> y;
        int v1 = x * 2 + y, v2 = y * 2 + x;
        C(p[1][v1], c), C(p[1][v2], c), C(p[2][v1], c), C(p[2][v2], c);
      } else if (o == 3) {
        cin >> y >> z;
        int v1 = x * 4 + y * 2 + z, v2 = z * 4 + y * 2 + x;
        C(p[3][v1], c), C(p[3][v2], c), C(p[4][v1], c), C(p[4][v2], c);
      } else {
        cin >> y >> z;
        int v = x * 4 + y * 2 + z;
        C(p[5][v], c), C(p[6][v], c), C(p[7][v], c), C(p[8][v], c);
      }
    }
    // debug("input2 over\n");
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 8; ++j) {
        debug("%lld ", p[i][j] == 1e15 ? -1 : p[i][j]);
      }
      debug("\n");
    }
    fill(f[0], f[9], 1e15), f[0][0] = 0;
    // debug("start solve.\n");
    for (int i = 0; i < n; ++i) {
      debug("%d:\n", i);
      for (int j = 0; j < s; ++j) {
        if (f[i][j] != 1e15) {
          for (int k = 0; k < m; ++k) {
            debug("%d", G(j, k));
          }
          debug(",%lld ", f[i][j]);
          int f1 = 0;
          for (int v; f1 < m && (v = G(j, f1), v && v != 2); ++f1) {
          }
          if (f1 < m) {
            if (a[i][f1] != 2) {
              int v;
              C(f[i][S(j, f1, 0)], f[i][j] + p[0][a[i][f1]]);
              if (f1 + 1 < m && a[i][f1 + 1] != 2 && (v = G(j, f1 + 1), !v || v == 2)) {
                C(f[i][S(S(j, f1, 0), f1 + 1, 0)], f[i][j] + p[1][a[i][f1] * 2 + a[i][f1 + 1]]);
                if (f1 + 2 < m && a[i][f1 + 2] != 2 && (v = G(j, f1 + 2), !v || v == 2)) {
                  C(f[i][S(S(S(j, f1, 0), f1 + 1, 0), f1 + 2, 0)], f[i][j] + p[3][a[i][f1] * 4 + a[i][f1 + 1] * 2 + a[i][f1 + 2]]);
                }
              }
              if (i + 1 < n && !G(j, f1) && a[i + 1][f1] != 2) {
                C(f[i][S(S(j, f1, 0), f1, 1)], f[i][j] + p[2][a[i][f1] * 2 + a[i + 1][f1]]);
                if (i + 2 < n && a[i + 2][f1] != 2) {
                  C(f[i][S(S(S(j, f1, 0), f1, 1), f1, 2)], f[i][j] + p[4][a[i][f1] * 4 + a[i + 1][f1] * 2 + a[i + 2][f1]]);
                }
              }
              if (i + 1 < n) {
                if (f1 + 1 < m) {
                  /*
                  ----
                   x
                  x42
                    1
                  */
                  if (a[i][f1 + 1] != 2 && a[i + 1][f1 + 1] != 2 && !G(j, f1 + 1)) {
                    C(f[i][S(S(S(j, f1, 0), f1 + 1, 0), f1 + 1, 1)], f[i][j] + p[5][a[i][f1] * 4 + a[i][f1 + 1] * 2 + a[i + 1][f1 + 1]]);
                  }
                  /*
                  ----
                   x
                  x21
                   4
                  */
                  if (a[i][f1 + 1] != 2 && a[i + 1][f1] != 2 && !G(j, f1) && (v = G(j, f1 + 1), !v || v == 2)) {
                    C(f[i][S(S(S(j, f1, 0), f1, 1), f1 + 1, 0)], f[i][j] + p[6][a[i + 1][f1] * 4 + a[i][f1] * 2 + a[i][f1 + 1]]);
                  }
                  /*
                  ----
                   x
                  x1
                   24
                  */
                  if (a[i + 1][f1 + 1] != 2 && a[i + 1][f1] != 2 && !G(j, f1) && G(j, f1 + 1) < 2) {
                    C(f[i][S(S(S(j, f1, 0), f1, 1), f1 + 1, 1)], f[i][j] + p[7][a[i + 1][f1 + 1] * 4 + a[i + 1][f1] * 2 + a[i][f1]]);
                  }
                /*
                ----
                 x
                x4
                12
                */
                } else if (f1 && a[i + 1][f1] != 2 && a[i + 1][f1 - 1] != 2 && !G(j, f1) && G(j, f1 - 1) < 2) {
                  C(f[i][S(S(S(j, f1, 0), f1, 1), f1 - 1, 1)], f[i][j] + p[8][a[i][f1] * 4 + a[i + 1][f1] * 2 + a[i + 1][f1 - 1]]);
                }
              }
            } else {
              C(f[i][S(j, f1, 0)], f[i][j]);
            }
          } else {
            int v = 0;
            for (int k = 0, x; k < m; ++k) {
              x = G(j, k);
              if (x > 1) {
                v += p5[k] * (x == 4 ? 3 : 1);
              }
            }
            C(f[i + 1][v], f[i][j]);
          }
        }
      }
      debug("\n");
    }
    // debug("solve over\n");
    cout << (f[n][0] == 1e15 ? -1 : f[n][0]) << '\n';
  }
  return 0;
}
/*
01234
oxoxx
ooxxx
oooox
00113
------------------------
 x
x1
----
 x
x21
----
 x
x2
 1
----
 x
x421
----
 x
x4
 2
 1
----
 x
x42
  1
----
 x
x21
 4
----
 x
x1
 24
----
 x
x4
12
*/