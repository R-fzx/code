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

const int kN = 21;

int t, n;
LL c, f[kN][kN][2];
bool v[kN];

int main() {
  RF("wave");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  f[0][0][0] = f[0][0][1] = 1;
  for (int i = 1; i < kN; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 1; k <= i; ++k) {
        f[i][j][k <= j] += f[i - 1][k - 1][k > j];
      }
    }
  }
  for (cin >> t; t--;) {
    cin >> n >> c;
    int d, p;
    fill_n(v + 1, n, 1);
    for (int i = 1; i <= n; ++i) {
      if (c <= f[n - 1][i - 1][0] + f[n - 1][i - 1][1]) {
        cout << i << ' ', p = i;
        v[i] = 0;
        if (c <= f[n - 1][i - 1][1]) {
          d = 0;
        } else {
          c -= f[n - 1][i - 1][1], d = 1;
        }
        break;
      }
      c -= f[n - 1][i - 1][0] + f[n - 1][i - 1][1];
    }
    for (int i = n - 2; i >= 0; --i, d ^= 1) {
      if (d) {
        for (int j = p + 1, k = count(v + 1, v + p + 1, 1); j <= n; ++j) {
          if (v[j]) {
            if (c <= f[i][k][d]) {
              cout << j << ' ', p = j, v[j] = 0;
              break;
            }
            c -= f[i][k][d], ++k;
          }
        }
      } else {
        for (int j = 1, k = 0; j < p; ++j) {
          if (v[j]) {
            if (c <= f[i][k][d]) {
              cout << j << ' ', p = j, v[j] = 0;
              break;
            }
            c -= f[i][k][d], ++k;
          }
        }
      }
    }
    cout << '\n';
  }
  return 0;
}