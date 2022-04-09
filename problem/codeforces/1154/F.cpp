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
#include <set>
#include <string>
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

const int kN = 2e5 + 1;

int n, m, k;
LL s[kN], f[kN], a[kN], b[kN];

LL S(int l, int r) { return s[r] - s[l - 1]; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + k + 1);
  for (int i = 1; i <= k; ++i) {
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    b[x] = max(b[x], (LL)y);
  }
  f[0] = 0;
  for (int i = 1; i <= k; ++i) {
    f[i] = INT32_MAX;
    for (int j = 1; j <= i; ++j) {
      f[i] = min(f[i], f[i - j] + S(i - j + 1, i) - S(i - b[j] + 1, i));
    }
  }
  cout << f[k];
  return 0;
}