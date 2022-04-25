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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#include <atcoder/all>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using mL = atcoder::modint998244353;

const int kN = 1001, kM = 11;

int n, m;
mL f[kN][kM][kM][kM];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int x1 = 1; x1 <= m; ++x1) {
    f[1][x1][0][0] = 1;
  }
  for (int i = 2; i <= n; ++i) {
    for (int x1 = 1; x1 <= m; ++x1) {
      for (int x2 = 0; x2 <= m; ++x2) {
        for (int x3 = 0; x3 <= m; ++x3) {
          for (int y = 1; y <= m; ++y) {
            if (x1 && x2 && x3 && y > x3 || !x2 && x3 || x2 && x1 >= x2 || x3 && x2 >= x3) {
              continue;
            }
            if (!x2) {       // |LIS| = 1
              if (x1 < y) {  // x1 < y
                f[i][x1][y][0] += f[i - 1][x1][0][0];
              } else {  // y <= x1
                f[i][y][0][0] += f[i - 1][x1][0][0];
              }
            } else if (!x3) {  // |LIS| = 2
              if (x2 < y) { // x1 < x2 < y
                f[i][x1][x2][y] += f[i - 1][x1][x2][0];
              } else if (x1 < y) { // x1 < y <= x2
                f[i][x1][y][0] += f[i - 1][x1][x2][0];
              } else { // y <= x1 < x2
                f[i][y][x2][0] += f[i - 1][x1][x2][0];
              }
            } else {  // |LIS| = 3
              if (x2 < y) { // x1 < x2 < y <= x3
                f[i][x1][x2][y] += f[i - 1][x1][x2][x3];
              } else if (x1 < y) { // x1 < y <= x2 < x3
                f[i][x1][y][x3] += f[i - 1][x1][x2][x3];
              } else {
                f[i][y][x2][x3] += f[i - 1][x1][x2][x3];
              }
            }
          }
        }
      }
    }
  }
  mL ans = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = 1; k <= m; ++k) {
        ans += f[n][i][j][k];
      }
    }
  }
  cout << ans.val();
  return 0;
}