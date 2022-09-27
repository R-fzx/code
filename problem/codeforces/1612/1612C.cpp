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
LL x, k;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> k >> x;
    LL l = 1, r = 2 * k - 1;
    while (l < r) {
      LL m = l + r >> 1, s;
      if (m <= k) {
        s = (m + 1) * m / 2;
      } else {
        s = (k + 1) * k / 2 + (k - 1 + k - m + k) * (m - k) / 2;
      }
      if (s < x) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    cout << l << '\n';
  }
  return 0;
}