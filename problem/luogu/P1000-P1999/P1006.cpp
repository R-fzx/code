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

const int kN = 51, kL = 101, kI = -1e5;

int n, m, a[kN][kN], f[kL][kL][kL];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  fill(f[0][0], f[n + m - 2][n], kI), f[0][0][0] = 0;
  for (int i = 1; i < n + m - 1; ++i) {                           // 走了多少步
    for (int j = max(0, i - m + 1); j <= min(i, n - 1); ++j) {    // A 向下走了多少步
      for (int k = max(0, i - m + 1); k <= min(i, n - 1); ++k) {  // B 向下走了多少步
        if (j != k || i == n + m - 2) {
          f[i][j][k] = max({f[i - 1][j][k], j ? f[i - 1][j - 1][k] : kI, k ? f[i - 1][j][k - 1] : kI, j && k ? f[i - 1][j - 1][k - 1] : kI}) + a[j + 1][i - j + 1] + a[k + 1][i - k + 1];
        }
      }
    }
  }
  // for (int i = 1; i < n + m - 1; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     for (int k = 0; k < n; ++k) {
  //       cout << f[i][j][k] << ' ';
  //     }
  //     cout << '\n';
  //   }
  //   cout << '\n';
  // }
  cout << f[n + m - 2][n - 1][n - 1];
  return 0;
}