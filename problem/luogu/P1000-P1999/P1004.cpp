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

const int kN = 10;

int n, a[kN][kN], f[2 * kN][kN][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int x, y; (cin >> x >> y) && x && y; cin >> a[x][y]) {
  }
  f[0][0][0] = a[1][1];
  for (int i = 1; i < 2 * n - 1; ++i) {
    for (int j = max(0, i - n + 1); j <= i && j < n; ++j) {
      for (int k = max(0, i - n + 1); k <= i && j < n; ++k) {
        f[i][j][k] = max({j < i && k < i ? f[i - 1][j][k] : -1, j && k < i ? f[i - 1][j - 1][k] : -1, j < i && k ? f[i - 1][j][k - 1] : -1, j && k ? f[i - 1][j - 1][k - 1] : -1}) + a[j + 1][i - j + 1] + (j == k ? 0 : a[k + 1][i - k + 1]);
      }
    }
  }
  cout << f[2 * n - 2][n - 1][n - 1];
  return 0;
}