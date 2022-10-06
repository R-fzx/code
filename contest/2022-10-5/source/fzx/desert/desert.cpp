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

const int kN = 51, kD[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const int kI = 1e9;

int n, m, a[kN][kN], sx, sy, d[kN][kN][kN * kN];

int S(int x, int y, int t) {
  if (x < 1 || x > n || y < 1 || y > m || a[x][y] == 1 || t > n * m) {
    return kI;
  }
  if (d[x][y][t] || a[x][y] == 2) {
    return d[x][y][t];
  }
  int b[2] = {kI, kI};
  for (int k = 0; k < 8; ++k) {
    int v = S(x + kD[k][0], y + kD[k][1], t + 1);
    if (v < b[0]) {
      b[1] = b[0], b[0] = v;
    } else if (v < b[1]) {
      b[1] = v;
    }
  }
  return d[x][y][t] = min(b[0] + 3, b[1] + 1);
}

int main() {
  RF("desert");
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    char c;
    for (c = getchar(); c != '-' && c != '*' && c != '@' && c != 'X'; c = getchar()) {
    }
    for (m = 1; c != '\n' && c != '\r' && c != EOF; ++m) {
      if (c == '*') {
        a[i][m] = 2;
      } else if (c == '@') {
        sx = i, sy = m;
      } else if (c == 'X') {
        a[i][m] = 1;
      }
      for (c = getchar(); c == ' '; c = getchar()) {
      }
    }
  }
  --m;
  int v = S(sx, sy, 0);
  cout << (v == kI ? -1 : v);
  return 0;
}