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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 501, kD[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m, h = 1, t, _t, d[kN][kN];
char a[kN][kN];
Pii q[kN * kN];

bool I(int x, int n) { return x >= 1 && x <= n; }
void R(int x, int y, int _d) {
  if (I(x, n) && I(y, m) && a[x][y] == '.' && d[x][y] > _d) {
    d[x][y] = _d, q[++t] = {x, y};
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      d[i][j] = INT32_MAX;
    }
  }
  for (R(1, 1, 0); h <= t; h = _t + 1) {
    for (int i = h; i <= t; ++i) {
      int x = q[i].first, y = q[i].second;
      for (int j = 0; j < 4; ++j) {
        R(x + kD[j][0], y + kD[j][1], d[x][y]);
      }
    }
    _t = t;
    for (int i = h; i <= _t; ++i) {
      int x = q[i].first, y = q[i].second;
      for (int j = -2; j <= 2; ++j) {
        for (int k = -2; k <= 2; ++k) {
          if (abs(j) + abs(k) <= 3 && I(x + j, n) && I(y + k, m)) {
            char _ = '.';
            swap(a[x + j][y + k], _);
            R(x + j, y + k, d[x][y] + 1);
            a[x + j][y + k] = _;
          }
        }
      }
    }
  }
  cout << d[n][m];
  return 0;
}