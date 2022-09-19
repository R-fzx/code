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

const int kN = 1e5 + 1;

int t, n, m, y, d[kN];
LL a[kN], b[kN];
double c[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n >> m >> y;
    LL s = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      b[i] = a[i] * m / y, d[i] = i, s += b[i];
      c[i] = abs(a[i] * 1.0 / y - (b[i] + 1.0) / m) - abs(a[i] * 1.0 / y - b[i] * 1.0 / m);
      // debug("%lf ", c[i]);
    }
    // debug("\n");
    sort(d + 1, d + n + 1, [](int i, int j) { return c[i] < c[j]; }), m -= s;
    for (int i = 1; i <= m; ++i) {
      ++b[d[i]];
    }
    for (int i = 1; i <= n; ++i) {
      cout << b[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}