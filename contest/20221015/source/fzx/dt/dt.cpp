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

int n, m;
LL a[kN], v[kN], d[kN], ans;
vector<int> e[kN];

int main() {
  RF("dt");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i], d[i] = i;
  }
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    a[x] += v[y], a[y] += v[x];
    e[x].push_back(y), e[y].push_back(x);
  }
  sort(d + 1, d + n + 1, [](int i, int j) { return v[i] > v[j]; });
  for (int i = 1; i <= n; ++i) {
    ans += a[d[i]];
    for (int j : e[d[i]]) {
      a[j] -= v[d[i]];
    }
  }
  cout << ans;
  return 0;
}