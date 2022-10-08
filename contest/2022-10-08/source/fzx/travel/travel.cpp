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

int n, m, p[kN], s, c[kN];
bool l[kN][kN];

bool D(int x) {
  int y;
  for (y = c[x]++; c[x] <= n; ++c[x]) {
    if (x != c[x] && l[x][c[x]] && (!p[c[x]] || D(p[c[x]]))) {
      p[c[x]] = x;
      return 1;
    }
  }
  c[x] = y;
  return 0;
}

int main() {
  RF("travel");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y, l[x][y] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    l[i][i] = 1;
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        l[i][j] |= l[i][k] && l[k][j];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!c[i]) {
      s += D(i);
    }
  }
  cout << n - s << '\n';
  for (int i = 1; i <= n; ++i) {
    // cout << c[i] << ' ' << p[i] << '\n';
    if (!p[i]) {
      cout << i << ' ';
    }
  }
  return 0;
}
/*

*/