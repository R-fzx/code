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

const int kN = 502, kM = 2001, kD[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int n, m;
LL a[kN][kN], d[kN][kN], b[kN][kN];

int E(int x, int y) { return (x - 1) * n + y; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      d[i][j] = a[i][j] - a[i][j - 1] - a[i - 1][j] + a[i + 1][j - 1];
    }
  }
  for (int i = 1, x1, y1, x2, y2, k; i <= m; ++i) {
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    ++x2, ++y2, d[x1][y1] += k, d[x2][y2] += k, d[x1][y2] -= k, d[x2][y1] -= k;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      d[i][j] += d[i - 1][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      d[i][j] += d[i][j - 1];
    }
  }
  fill(&b[1][1], &b[n][n] + 1, 1e18);
  for (int i = n; i >= 1; --i) {
    for (int j = n; j >= 1; --j) {
      if (i == n && j == n) {
        b[i][j] = 0;
      } else {
        for (int k = 0; k < 4; ++k) {
          int x = i + kD[k][0], y = j + kD[k][1];
          if (min(x, y) >= 1 && max(x, y) <= n) {
            b[i][j] = min(b[i][j], b[x][y] + 1);
          }
        }
        b[i][j] = max(a[i][j], b[i][j]);
      }
    }
  }
  LL ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      debug("%lld ", b[i][j]);
      ans += min(d[i][j], b[i][j]) - a[i][j];
    }
    debug("\n");
  }
  cout << ans;
  return 0;
}
/*
y+1
4 9
5 3
===========
3 4
2 0
*/