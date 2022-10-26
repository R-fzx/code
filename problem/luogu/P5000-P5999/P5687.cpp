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

const int kN = 3e5 + 1;

int n, m;
LL ans, a[kN], b[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
  for (int i = 1, j = 1; i <= n || j <= m; ) {
    if (i <= n && (j > m || a[i] < b[j])) {
      if (i == 1 || j == 1) {
        ans += a[i] * (m - 1);
      } else {
        ans += a[i] * (m - j + 1);
      }
      ++i;
    } else {
      if (i == 1 || j == 1) {
        ans += b[j] * (n - 1);
      } else {
        ans += b[j] * (n - i + 1);
      }
      ++j;
    }
  }
  cout << ans;
  return 0;
}