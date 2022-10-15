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

const int kN = 8;

int n, k, a, _b[kN];
Pii b[kN];
double ans;

void D(int x, int k) {
  if (x == n) {
    double s = 0;
    for (int i = 0; i < (1 << n); ++i) {
      double _s = 1;
      int c = 0, _b = 0;
      for (int j = 0; j < n; ++j) {
        if (i >> j & 1) {
          ++c, _s *= b[j].second / 10.0;
        } else {
          _b += b[j].first, _s *= 1 - b[j].second / 10.0;
        }
      }
      if (c <= n / 2) {
        _s *= 1.0 * a / (a + _b);
      }
      s += _s;
    }
    ans = max(ans, s);
    return;
  }

  for (b[x].second = _b[x]; k >= 0 && b[x].second <= 10; D(x + 1, k), ++b[x].second, --k) {
  }
}

int main() {
  // RF("assembly");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> a;
  for (int i = 0; i < n; ++i) {
    cin >> b[i].first >> b[i].second;
    _b[i] = b[i].second /= 10;
  }
  D(0, k);
  cout << fixed << setprecision(6) << ans;
  return 0;
}