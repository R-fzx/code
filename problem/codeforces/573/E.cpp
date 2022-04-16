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

const int kN = 1e3 + 1;

int n, a[kN];
LL f[kN][kN], ans = -1e18;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    // for (int j = i; j >= 1; --j) {
    //   f[j] = max(f[j], f[j - 1] + j * a[i]);
    // }
    for (int j = 1; j <= i; ++j) {
      f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + 1LL * j * a[i]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, f[n][i]);
  }
  cout << ans;
  return 0;
}