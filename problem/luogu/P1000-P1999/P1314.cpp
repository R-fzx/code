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

const int kN = 2e5 + 1;

int n, m, l[kN], r[kN];
LL s, w[kN], v[kN], sw[kN], sv[kN];

LL C(int x) {
  for (int i = 1; i <= n; ++i) {
    sw[i] = sw[i - 1] + (w[i] >= x);
    sv[i] = sv[i - 1] + (w[i] >= x) * v[i];
  }
  LL y = 0;
  for (int i = 1; i <= m; ++i) {
    y += (sw[r[i]] - sw[l[i] - 1]) * (sv[r[i]] - sv[l[i] - 1]);
  }
  return y;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> s;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> v[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> l[i] >> r[i];
  }
  int l = 0, r = 1e9;
  while (l < r) {
    int m = l + r >> 1;
    if (C(m) < s) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  debug("%lld %lld %lld %lld %lld %lld %d\n", C(0), C(3), C(4), C(5), C(6), C(7), l);
  cout << min(C(l - 1) - s, s - C(l));
  return 0;
}