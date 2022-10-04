#pragma GCC optimize(3)
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

const int kN = 101;

struct Q {
  short x, y, d, r;
};
queue<Q> q;
int _, n, m, sx, sy, tx, ty;
short b[kN][kN][kN * kN];
double L;
bool a[kN][kN];

void R(short x, short y, short d, short r) {
  if (x >= 1 && x <= n && y >= 1 && y <= m && d <= n * m && !a[x][y] && !~b[x][y][d]) {
    b[x][y][d] = r, q.push({x, y, d, r});
  }
}

int main() {
  RF("maze");
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (scanf("%d", &_); _--;) {
    // cin >> L >> n >> m;
    scanf("%lf%d%d", &L, &n, &m);
    // cout << L << ' ' << n << ' ' << m;
    fill(a[1], a[n + 1], 0);
    for (int i = 1; i <= n; ++i) {
      char c;
      for (c = getchar(); c == '\n' || c == '\r'; c = getchar()) {
      }
      for (int j = 1; j <= m; ++j) {
        // cout << int(c);
        if (c == '#') {
          a[i][j] = 1;
        } else if (c == 'S') {
          sx = i, sy = j;
        } else if (c == 'E') {
          tx = i, ty = j;
        }
        c = getchar();
      }
      // cout << '\n';
    }
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 1; j <= m; ++j) {
    //     cout << a[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }
    // cout << sx << ' ' << sy << ' ' << tx << ' ' << ty << '\n';
    fill(b[1][1], b[n][m + 1], -1);
    for (R(sx, sy, 0, 0); !q.empty();) {
      Q x = q.front();
      // cout << x.x << ' ' << x.y << ' ' << x.d << ' ' << x.r << '\n';
      q.pop();
      R(x.x + 1, x.y, x.d + 1, x.r), R(x.x - 1, x.y, x.d + 1, x.r);
      R(x.x, x.y + 1, x.d, x.r + 1), R(x.x, x.y - 1, x.d, x.r + 1);
    }
    vector<pair<short, short>> l;
    for (int i = 0, p = -1; i <= n * m; ++i) {
      if (b[tx][ty][i] > p) {
        // cout << '(' << i << ',' << b[tx][ty][i] << ") ";
        p = b[tx][ty][i], l.emplace_back(i, b[tx][ty][i]);
      }
    }
    bool _f = 0;
    for (int i = 0; i < l.size(); ++i) {
      double v = (L - l[i].second) / l[i].first;
      if (v >= 0) {
        bool f = 1;
        for (int j = 0; j < l.size(); ++j) {
          if (v * l[i].first + l[i].second < L) {
            f = 0;
            break;
          }
        }
        if (f) {
          printf("%.5lf\n", v), _f = 1;
          break;
        }
      }
    }
    if (!_f) {
      printf("1145141919810\n");
    }
  }
  // cout << clock();
  return 0;
}
/*
############
#S## |---#E#
#|## |# |#|#
#|--#|# |#|#
###|#|# |#|#
# -|#|# |#|#
# |##|# |#|#
##|-#|# |#|#
###|#|# |#|#
##-|#|# |#|#
# |##|# |--#
# |---#    #
############
38v+13=21
*/