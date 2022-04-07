#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define _DEBUG
#ifdef _DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1;

int n, l, r, m;
Pii a[kN];

bool C() {
  for (int i = 1, mx = -1e9, mi = 1e9, j = 1; i <= n; ++i) {
    for (; j <= n && a[i].first - a[j].first > m; ++j) {
      mx = max(mx, a[j].second), mi = min(mi, a[j].second);
    }
    if (mx - a[i].second > m || a[i].second - mi > m) {
      return 0;
    }
  }
  for (int i = n, mx = -1e9, mi = 1e9, j = n; i >= 1; --i) {
    for (; j >= 1 && a[j].first - a[i].first > m; --j) {
      mx = max(mx, a[j].second), mi = min(mi, a[j].second);
    }
    if (mx - a[i].second > m || a[i].second - mi > m) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1);
  for (l = 0, r = 1e9; l < r; ) {
    m = l + r >> 1;
    debug("%d %d %d\n", l, r, m);
    if (C()) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l;
  return 0;
}