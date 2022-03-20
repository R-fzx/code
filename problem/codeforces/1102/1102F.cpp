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

const int kN = 16, kM = 10001;

int n, m, a[kN][kM], f[1 << kN][kN], b[kN][kN], ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      b[i][j] = INT32_MAX;
      if (i ^ j) {
        for (int k = 1; k <= m; ++k) {
          b[i][j] = min(b[i][j], abs(a[i][k] - a[j][k]));
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    fill(&f[0][0], &f[(1 << n) - 1][n] + 1, 0), f[1 << i][i] = INT32_MAX;
    for (int j = 0; j < (1 << n); ++j) {
      for (int k = 0; k < n; ++k) {
        if (j >> k & 1) {
          for (int u = 0; u < n; ++u) {
            if (j >> u & 1 ^ 1) {
              f[j | 1 << u][u] = max(f[j | 1 << u][u], min(f[j][k], b[k][u]));
            }
          }
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      int x = f[(1 << n) - 1][j];
      for (int k = 1; k < m; ++k) {
        x = min(x, abs(a[i][k + 1] - a[j][k]));
      }
      ans = max(ans, x);
    }
  }
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}