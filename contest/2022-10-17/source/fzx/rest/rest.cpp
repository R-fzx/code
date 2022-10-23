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

const int kN = 2e6 + 1, kV = 1e6 + 1;

int n, a[kN], v, ans;
bool b[kV];

int main() {
  RF("rest");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], v = max(v, a[i]), b[a[i]] = 1;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= v; ++i) {
    if (b[i]) {
      for (int j = i * 2; j <= v + i; j += i) {
        ans = max(ans, *(lower_bound(a + 1, a + n + 1, j) - 1) % i);
      }
    }
  }
  cout << ans;
  return 0;
}