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

const int kN = 7;

struct E {
  long double d, p;
  bool operator<(const E &o) const { return d < o.d; }
} e[kN];
long double d1, c, d2, ans = 1e9;
int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> d1 >> c >> d2 >> e[0].p >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> e[i].d >> e[i].p;
  }
  sort(e, e + n + 1);
  for (int i = 0; i < (1 << n); ++i) {
    bool f = 1;
    long double s = 0;
    int p = 0;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        if (e[j + 1].d - e[p].d > c * d2) {
          f = 0;
          break;
        }
        s += (e[j + 1].d - e[p].d) / d2 * e[p].p, p = j + 1;
      }
    }
    if (!f || d1 - e[p].d > c * d2) {
      continue;
    }
    ans = min(ans, s + (d1 - e[p].d) / d2 * e[p].p);
  }
  if (ans == 1e9) {
    cout << "No Solution";
  } else {
    cout << fixed << setprecision(2) << ans;
  }
  return 0;
}
/*
475.6 11.9 27.4 14.98 6
102.0 9.99
220.0 13.29
256.3 14.79
275.0 10.29
277.6 11.29
381.8 10.09

192.15
*/