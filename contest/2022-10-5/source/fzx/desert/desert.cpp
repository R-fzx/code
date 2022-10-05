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

int n, m, a[kN][kN], sx, sy, d[kN][kN], h = 1, t;
vector<int> p[kN][kN];
bool v[kN][kN][8];
Pii q[kN * kN];

int E(int i, int j) { return (i - 1) * m + j; }
void R(int x, int y, int _d, int _p) {
  if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 1) {
    if (d[x][y] > _d) {
      d[x][y] = _d, fill(v[x][y], v[x][y + 1], 0);
    }
    if (d[x][y] == _d) {
      if (~_p) {
        v[x][y][_p] = 1;
      }
      q[++t] = {x, y};
    }
  }
}
int S(int x, int y) {
  if (a[x][y] == 2) {
    return 0;
  }
  if (!p[x][y].size()) {
    return -1;
  }
  int s = 1e9, s2 = 1e9, s3 = 1e9;
  for (int k : p[x][y]) {
    int v = S(x - kD[k][0], y - kD[k][1]);
    s3 = min(s3, v + 3);
    if (v + 1 < s) {
      s2 = s, s = v + 1;
    } else if (v + 1 < s2) {
      s2 = v + 1;
    }
  }
  return min(s3, s2);
}

int main() {
  RF("desert");
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  // cerr << "114514\n";
  for (int i = 1; i <= n; ++i) {
    // cerr << i << '\n';
    char c;
    for (c = getchar(); c != '-' && c != '*' && c != '@' && c != 'X'; c = getchar()) {
    }
    for (m = 1; c != '\n' && c != '\r' && c != EOF; ++m) {
      // cerr << m << ' ';
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
    // cerr << i << '\n';
  }
  --m;
  // cerr << "114514\n";
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     cout << a[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << sx << ' ' << sy << '\n';
  fill(d[1], d[n + 1], 1e9);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 2) {
        R(i, j, 0, -1);
      }
    }
  }
  for (; h <= t; ++h) {
    int x = q[h].first, y = q[h].second;
    for (int k = 0; k < 8; ++k) {
      R(x + kD[k][0], y + kD[k][1], d[x][y] + 1, k);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = 0; k < 8; ++k) {
        if (v[i][j][k]) {
          p[i][j].push_back(k);
        }
      }
    }
  }
  // cerr << "114514\n";
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     cout << d[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     cout << '(';
  //     for (int k : p[i][j]) {
  //       cout << k << ',';
  //     }
  //     cout << ") ";
  //   }
  //   cout << '\n';
  // }
  cout << S(sx, sy);
  return 0;
}