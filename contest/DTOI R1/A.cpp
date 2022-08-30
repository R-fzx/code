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

int t;
LL x, y, k;

LL G(LL x, LL y) { return y ? G(y, x % y) : x; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> x >> y >> k;
    if (k == 1) {
      cout << x << '\n';
    } else if (k == 2) {
      cout << y << '\n';
    } else {
      debug("%lld %lld", x, y);
      for (LL i = 3; i <= k && x != y; ++i) {
        LL g = G(x, y), _x = x, _y = y;
        if (x % 2 == y % 2) {
          x = _y, y = g;
        } else {
          x = _y, y = _y / g * _x;
        }
        debug(" %lld", y);
      }
      debug("\n");
      cout << y << '\n';
    }
  }
  return 0;
}