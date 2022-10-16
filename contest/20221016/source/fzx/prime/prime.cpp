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
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int t, n;

bool P(LL x) {
  for (LL i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return 0;
    }
  }
  return x > 1;
}
LL G(LL x, LL y) { return y ? G(y, x % y) : x; }

int main() {
  RF("prime");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--; ) {
    cin >> n;
    LL pl = n, pr = n + 1;
    for (; !P(pl); --pl) {
    }
    for (; !P(pr); ++pr) {
    }
    LL x = pl * pr + 2 * (n + 1 - pl - pr), y = 2 * pl * pr, g = G(x, y);
    cout << x / g << '/' << y / g << '\n';
  }
  return 0;
}