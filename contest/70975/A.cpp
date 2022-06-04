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

const int kN = 1e6 + 1;

int n, m, a[kN], b[kN], ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1, j = 0, s = 0, v = 0; i <= n; s -= a[i], v -= b[i], ++i) {
    for (; j <= n && s <= m; ++j, s += a[j], v += b[j]) {
    }
    s -= a[j], v -= b[j], --j;
    debug("%d %d\n", i, j);
    ans = max(ans, v);
  }
  cout << ans;
  return 0;
}