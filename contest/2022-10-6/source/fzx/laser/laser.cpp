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

const int kN = 1e4 + 1;

int n, k;
LL c, b[10];
Pll a[kN];

bool I(LL x) {
  auto p = lower_bound(a + 1, a + n + 1, Pll{x + 1, 0});
  return (p - 1)->second >= x;
}
bool C(int x, int y) {
  for (int i = 1; i <= n; ++i) {
    for (LL j = a[i].first; j <= a[i].second; ++j) {
      LL p = 1;
      for (int k = 0; k < ::k; ++k, p *= 10) {
        if (j / p % 10 == x && !I(j + p * (y - x))) {
          return 0;
        }
      }
    }
  }
  return 1;
}

int main() {
  RF("laser");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  // if (k == 1) {
  //   for (int i = 1; i <= n; ++i) {
  //     for (int j = a[i].first % 10; j <= 9; ++j) {
  //       b[j] += c + 1;
  //     }
  //     for (int j = 1; j <= a[i].second % 10; ++j) {
  //       b[j] += c + 2;
  //     }
  //     for (int j = 1; j <= 9; ++j) {
  //       c = max(c, b[j]);
  //     }
  //   }
  //   b[0] = b[1];
  //   for (int i = 1; i <= 9; ++i) {
  //     if (b[i] != b[i - 1]) {
  //       cout << '\n';
  //     }
  //     cout << i;
  //   }
  //   return 0;
  // }
  if (n == 1) {
    LL l = a[1].first, r = a[1].second, x = 0, y = 0, lx, rx, p = 1;
    for (int i = 0; i < k; ++i, x += lx * p, y += rx * p, p *= 10) {
      lx = l / p % 10, rx = r / p % 10;
      if (x) {
        b[lx] += c + 1;
        for (int j = lx + 1; j <= 9; ++j) {
          b[j] += c + 2;
        }
      } else {
        for (int j = lx; j <= 9; ++j) {
          b[j] += c + 1;
        }
      }
      if (y) {
        b[rx] += c + 3;
        for (int j = 0; j < rx; ++j) {
          b[j] += c + 4;
        }
      } else {
        for (int j = 0; j <= rx; ++j) {
          b[j] += c + 3;
        }
      }
      for (int j = 1; j <= 9; ++j) {
        c = max(c, b[j]);
      }
    }
    cout << 1;
    for (int i = 2; i <= 9; ++i) {
      if (b[i] != b[i - 1]) {
        cout << '\n';
      }
      cout << i;
    }
    return 0;
  }
  for (int i = 1; i <= 9; ++i) {
    if (!b[i]) {
      b[i] = ++c;
      for (int j = i + 1; j <= 9; ++j) {
        if (!b[j] && C(i, j) && C(j, i)) {
          b[j] = c;
        }
      }
    }
  }
  for (int i = 1; i <= c; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (b[j] == i) {
        cout << j;
      }
    }
    cout << '\n';
  }
  return 0;
}