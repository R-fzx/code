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

const int kN = 15001;

int t, n, f[kN];
pair<int, Pii> e[kN];
LL ans, s[kN];

int F(int x) { return x == f[x] ? x : (f[x] = F(f[x])); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n, ans = 0;
    for (int i = 1; i < n; ++i) {
      cin >> e[i].second.first >> e[i].second.second >> e[i].first;
    }
    sort(e + 1, e + n), fill_n(s + 1, n, 1), iota(f + 1, f + n + 1, 1);
    for (int i = 1; i < n; ++i) {
      int x = e[i].second.first, y = e[i].second.second, w = e[i].first, rx = F(x), ry = F(y);
      ans += (s[rx] * s[ry] - 1) * (w + 1) + w, s[rx] += s[ry], f[ry] = rx;
    }
    cout << ans << '\n';
  }
  return 0;
}