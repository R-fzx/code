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

const int kN = 1e7 + 2;

int n, m, l, r;
LL s, e, d, a[kN], b[kN], xr, mx, s1, s2;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> l >> r >> s >> e;
    b[l] += s, b[r + 1] -= e, d = (e - s) / (r - l), a[l + 1] += d, a[r + 1] -= d;
  }
  for (int i = 1; i <= n; ++i) {
    s1 += a[i], s2 += b[i] + s1, xr ^= s2, mx = max(mx, s2);
  }
  cout << xr << " " << mx;
  return 0;
}
/*
2 4 6 8 10 12
d[i]=a[i]-a[i-1]
0 0 0 0 2 4 6 0 0
*/