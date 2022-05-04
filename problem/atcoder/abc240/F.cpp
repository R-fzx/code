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

int t, n, m;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    LL x = 0, y = 0, ans = -3e18;
    for (int i = 1, p, r, l = 0; i <= n; ++i, l = r) {
      cin >> p >> r;
      int _n = r;
      r += l++;
      auto f = [&](LL n) { return y + x * n + p * n * (n + 1) / 2; };
      if (p >= 0) {
        ans = max(ans, max(f(1), f(_n)));
      } else {
        LL a = -(2 * x + p) / p / 2;
        for (int i = max(1, (int)a - 500); i <= min(_n, (int)a + 500); ++i) {
          ans = max(ans, f(i));
        }
      }
      y = f(_n), x += p * _n;
    }
    cout << ans << endl;
  }
  return 0;
}