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

const int kN = 1e5 + 1;

int n, m, c[kN], mx, s, cm, p;

int main() {
  RF("vote");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m, p = n - m;
  for (int i = 1, x; i <= m; ++i) {
    cin >> x;
    ++c[x];
  }
  for (int i = 1; i <= n; ++i) {
    mx = max(mx, c[i]);
  }
  for (int i = 1; i <= n; ++i) {
    s += mx - 1 - c[i], cm += mx == c[i];
  }
  // cerr << s << ' ' << cm << '\n';
  if (s < p) {
    cout << "1145141919810wssb";
  } else {
    double ans = 1;
    for (p = n - cm; n - p != 1 && p % (n - p); p = n - p % (n - p)) {
      ans *= 1.0 * (p % (n - p)) / (n - p);
    }
    cout << fixed << setprecision(4) << (n - p == 1 ? ans : 0);
  }
  return 0;
}