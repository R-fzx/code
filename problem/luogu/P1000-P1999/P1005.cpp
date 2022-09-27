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
using i128 = __int128_t;

const int kN = 81;

int n, m, a[kN];
i128 s, p[kN], f[kN][kN];

void W(i128 x) {
  if (x) {
    W(x / 10), putchar(x % 10 + '0');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m, p[0] = 1;
  for (int i = 1; i <= m; ++i) {
    p[i] = p[i - 1] * 2;
  }
  for (int _ = 1; _ <= n; ++_) {
    for (int i = 1; i <= m; ++i) {
      cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j <= i; ++j) {
        f[i][j] = max(j ? f[i - 1][j - 1] + a[j] * p[i] : -1, j < i ? f[i - 1][j] + a[m - i + j + 1] * p[i] : -1);
      }
    }
    i128 _s = -1;
    for (int i = 0; i <= m; ++i) {
      _s = max(_s, f[m][i]);
    }
    s += _s;
  }
  if (s) {
    W(s);
  } else {
    putchar('0');
  }
  return 0;
}