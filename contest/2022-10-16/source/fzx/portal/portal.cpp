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
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 501, kM = 501, kD[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Q {
  int x, y, d;
} q[kN * kM];
int n, m, tx, ty, d[kN][kM], h = 1, t;
char a[kN][kM];

void R(int x, int y, int _d) {
  if (a[x][y] != '#' && !d[x][y]) {
    d[x][y] = _d, q[++t] = {x, y, _d};
  }
}

int main() {
  RF("portal");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] + 1;
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 'C') {
        R(i, j, 1);
      } else if (a[i][j] == 'F') {
        tx = i, ty = j;
      }
    }
  }
  for (; h <= t; ++h) {
    Q x = q[h];
    bool f = 0;
    for (int i = 0; i < 4; ++i) {
      int nx = x.x + kD[i][0], ny = x.y + kD[i][1];
      R(nx, ny, x.d + 1), f |= a[nx][ny] == '#';
    }
    if (f) {
      for (int i = 0; i < 4; ++i) {
        int nx = x.x, ny = x.y;
        for (; a[nx + kD[i][0]][ny + kD[i][1]] != '#'; nx += kD[i][0], ny += kD[i][1]) {
        }
        R(nx, ny, x.d + 1);
      }
    }
  }
  if (d[tx][ty]) {
    cout << d[tx][ty] - 1;
  } else {
    cout << "nemoguce";
  }
  return 0;
}