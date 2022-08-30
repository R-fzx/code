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

const int kN = 501;

int n, m;
char a[kN][kN];
bool v[kN][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int x = 1, y = 1; ; ) {
    v[x][y] = 1;
    int nx = x, ny = y;
    if (a[x][y] == 'U') {
      --nx;
    } else if (a[x][y] == 'D') {
      ++nx;
    } else if (a[x][y] == 'L') {
      --ny;
    } else {
      ++ny;
    }
    if (nx < 1 || nx > n || ny < 1 || ny > m) {
      cout << x << ' ' << y;
      return 0;
    }
    if (v[nx][ny]) {
      cout << -1;
      return 0;
    }
    x = nx, y = ny;
  }
  return 0;
}