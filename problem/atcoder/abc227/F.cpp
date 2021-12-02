#include <iostream>
#include <queue>

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;

const int kN = 31;

int h, w, k;
Pll a[kN][kN];
LL f[kN][kN][kN << 1], ans = INT64_MAX;

LL S(int x, int y) {
  fill(&f[0][0][0], &f[h][w][k] + 1, 1LL << 50), f[0][1][0] = 0;
  for (int i = 1; i <= h; ++i)
    for (int j = 1; j <= w; ++j)
      for (int t = a[i][j] >= a[x][y], u = t; u <= k; ++u) f[i][j][u] = min(f[i - 1][j][u - t], f[i][j - 1][u - t]) + a[i][j].first * t;
  return f[h][w][k];
}

int main() {
  cin >> h >> w >> k;
  for (int i = 1, c = 0; i <= h; ++i)
    for (int j = 1; j <= w; ++j) cin >> a[i][j].first, a[i][j].second = ++c;
  for (int i = 1; i <= h; ++i)
    for (int j = 1; j <= w; ++j) ans = min(ans, S(i, j));
  cout << ans;
  return 0;
}