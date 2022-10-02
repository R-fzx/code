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

const int kN = 16, kV = 6e6 + 1;

int n, k, f[kV], a[kN], ans, b[kN];

void D(int x) {
  if (x == k + 1) {
    for (int i = 1; i <= a[k] * n; ++i) {
      f[i] = n + 1;
      for (int j = 1; j <= k; ++j) {
        for (int x = 1; i >= x * a[j]; ++x) {
          f[i] = min(f[i], f[i - a[j] * x] + x);
        }
      }
      if (f[i] == n + 1) {
        for (int j = 1; j <= k; ++j) {
          debug("%d ", a[j]);
        }
        debug("\n%d\n", i - 1);
        if (i - 1 > ans) {
          copy_n(a + 1, k, b + 1), ans = i - 1;
        }
        break;
      }
    }
    return;
  }
  for (a[x] = a[x - 1] + 1; a[x] <= a[x - 1] * n + 1; ++a[x]) {
    D(x + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  D(1);
  for (int i = 1; i <= k; ++i) {
    cout << b[i] << ' ';
  }
  cout << "\nMAX=" << ans;
  return 0;
}