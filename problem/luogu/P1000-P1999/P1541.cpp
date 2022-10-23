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

const int kN = 351, kC = 41;

int n, m, c[5], a[kN], f[kC][kC][kC][kC];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1, x; i <= m; ++i) {
    cin >> x;
    ++c[x];
  }
  for (int i = 0; i <= c[1]; ++i) {
    for (int j = 0; j <= c[2]; ++j) {
      for (int k = 0; k <= c[3]; ++k) {
        for (int u = 0; u <= c[4]; ++u) {
          int v = i + j * 2 + k * 3 + u * 4 + 1;
          if (i) {
            f[i][j][k][u] = max(f[i][j][k][u], f[i - 1][j][k][u]);
          }
          if (j) {
            f[i][j][k][u] = max(f[i][j][k][u], f[i][j - 1][k][u]);
          }
          if (k) {
            f[i][j][k][u] = max(f[i][j][k][u], f[i][j][k - 1][u]);
          }
          if (u) {
            f[i][j][k][u] = max(f[i][j][k][u], f[i][j][k][u - 1]);
          }
          f[i][j][k][u] += a[v];
        }
      }
    }
  }
  cout << f[c[1]][c[2]][c[3]][c[4]];
  return 0;
}