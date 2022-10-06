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

int n, l, k, a[kN];
double p[kN], f[kN][kN][kN * 2], ans;

int main() {
  RF("guard");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> l >> k;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x, p[i] = x / 100.0;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  f[0][0][k + n] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= 2 * n; ++k) {
        f[i + 1][j][k] += f[i][j][k] * (1 - p[i + 1]);
        f[i + 1][j + 1][min(2 * n, k + a[i + 1])] += f[i][j][k] * p[i + 1];
      }
    }
  }
  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j <= i; ++j) {
  //     for (int k = 0; k <= 2 * n; ++k) {
  //       cout << f[i][j][k] << ' ';
  //     }
  //     cout << '\n';
  //   }
  //   cout << '\n';
  // }
  for (int i = l; i <= n; ++i) {
    for (int j = n; j <= 2 * n; ++j) {
      ans += f[n][i][j];
    }
  }
  cout << fixed << setprecision(6) << ans;
  return 0;
}
/*
f[i+1][j][k]+=f[i][j][k]*(1-p[i+1])
f[i+1][j+1][min(2n,k+a[i+1])]+=f[i][j][k]*p[i+1]

0 0 1 0 0
0 0 0 0 0
0 0 0 0 0

0 0 0.9 0 0
0 0.1 0 0 0
0 0 0 0 0

0 0 0.72 0 0
0 0.26 0 0 0
0.02 0 0 0 0

0 0 0.504 0 0
0 0.182 0 0 0.216
0.014 0 0 0.078 0
0 0 0.006 0 0
*/