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

const int kN = 12, kI = 1e9;

struct E {
  int x, y, z, d;
  bool operator<(const E &o) const { return d > o.d; }
};
int n, m, d[kN][kN], f[1 << kN][kN][kN], ans = kI;
priority_queue<E> q;

void R(int x, int y, int z, int _d) {
  if (f[x][y][z] > _d) {
    f[x][y][z] = _d, q.push({x, y, z, _d});
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      d[i][j] = kI;
    }
  }
  for (int i = 1, x, y, v; i <= m; ++i) {
    cin >> x >> y >> v, --x, --y;
    d[x][y] = d[y][x] = min(d[x][y], v);
  }
  for (int i = 0; i < n; ++i) {
    fill(f[0][0], f[(1 << n) - 1][n], kI);
    for (R(1 << i, i, 1, 0); !q.empty(); ) {
      E x = q.top();
      q.pop();
      for (int j = 0; j < n; ++j) {
        if (!(x.x >> j & 1) && d[x.y][j] < kI) {
          R(x.x | 1 << j, j, x.z + 1, x.d + d[x.y][j] * x.z);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans = min(ans, f[(1 << n) - 1][i][j]);
      }
    }
  }
  cout << ans;
  return 0;
}