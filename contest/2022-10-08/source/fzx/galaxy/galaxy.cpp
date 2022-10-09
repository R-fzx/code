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
#include <unordered_set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
#define y0 sbcmath

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 9, kP = 11;

int k, n, m, x0, y0;
LL p[kN], s, t;
unordered_set<LL> v;

LL P(int x, int y) { return p[(x + 3) % 3 * 3 + (y + 3) % 3]; }
bool C(int x1, int y1, int x2, int y2) {
  if (x1 < 1 || x2 < 1) {
    x1 += 3, x2 += 3;
  }
  if (x1 > n || x2 > n) {
    x1 -= 3, x2 -= 3;
  }
  if (y1 < 1 || y2 < 1) {
    y1 += 3, y2 += 3;
  }
  if (y1 > m || y2 > m) {
    y1 -= 3, y2 -= 3;
  }
  return min(x1, x2) >= 1 && max(x2, x2) <= n && min(y1, y2) >= 1 && max(y1, y2) <= m;
}
bool S(LL x) {
  if (x == t) {
    return 1;
  }
  if (v.find(x) != v.end()) {
    return 0;
  }
  v.insert(x);
  int c[3][3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      int _c = x / P(i, j) % kP;
      if (_c > (n / 3 + (n % 3 && n % 3 >= i)) * (m / 3 + (m % 3 && m % 3 >= j))) {
        return 0;
      } else {
        c[i][j] = _c;
      }
    }
  }
  // for (int i = 0; i < 3; ++i) {
  //   for (int j = 0; j < 3; ++j) {
  //     cout << c[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << '\n';
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (c[i][j]) {
        for (int dx = -1; dx <= 1; ++dx) {
          for (int dy = -1; dy <= 1; ++dy) {
            int i1 = (i + dx + 3) % 3, j1 = (j + dy + 3) % 3;
            if ((dx || dy) && C(i, j, i + 2 * dx, j + 2 * dy) && c[i1][j1] && S(x - P(i, j) - P(i1, j1) + P((i + 2 * dx + 3) % 3, (j + 2 * dy + 3) % 3))) {
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

int main() {
  RF("galaxy");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = p[0] = 1; i < kN; p[i] = p[i - 1] * kP, ++i) {
  }
  for (; cin >> k >> n >> m >> x0 >> y0;) {
    t = P(x0, y0), s = 0, v.clear();
    for (int i = 1, x, y; i <= k; ++i) {
      cin >> x >> y, s += P(x, y);
    }
    cout << (S(s) ? "Yes" : "No") << '\n';
  }
  return 0;
}
/*
5 5 5 1 3
5 5
1 5
2 1
4 2
2 5

0 0 0
0 0 2
0 1 2

0 0 0
0 0 2
1 0 1

0 0 1
0 0 1
1 0 0

0 0 0
0 1 1
0 0 0

0 0 0
1 0 0
0 0 0
*/