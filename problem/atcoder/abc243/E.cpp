#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 301;

int n, m, ans;
LL d[kN][kN], l[kN][kN];

bool C(int x, int y) {
  if (d[x][y] < l[x][y]) {
    return 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (i != x && i != y && d[x][i] + d[i][y] <= l[x][y]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i ^ j) {
        d[i][j] = 1e18;
      }
    }
  }
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y >> l[x][y];
    d[x][y] = d[y][x] = l[y][x] = l[x][y];
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ans += C(i, j);
    }
  }
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}