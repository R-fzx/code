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

const int kN = 1e6 + 1;

int n, d[kN], f[kN];
LL ans, s[kN], a[kN];
vector<int> e[kN];
bool v[kN];

int F(int x) { return x == f[x] ? x : (f[x] = F(f[x])); }

int main() {
  RF("imbalance");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], d[i] = f[i] = i;
  }
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  sort(d + 1, d + n + 1, [](int i, int j) { return a[i] < a[j]; });
  for (int i = 1; i <= n; ++i) {
    v[d[i]] = s[d[i]] = 1;
    for (int j : e[d[i]]) {
      if (v[j]) {
        int rj = F(j);
        ans += a[d[i]] * s[rj] * s[d[i]];
        s[d[i]] += s[rj];
      }
    }
    for (int j : e[d[i]]) {
      if (v[j]) {
        f[F(j)] = d[i];
      }
    }
  }
  // cout << ans << '\n';
  iota(f + 1, f + n + 1, 1), fill_n(s + 1, n, 0), fill_n(v + 1, n, 0);
  sort(d + 1, d + n + 1, [](int i, int j) { return a[i] > a[j]; });
  for (int i = 1; i <= n; ++i) {
    v[d[i]] = s[d[i]] = 1;
    for (int j : e[d[i]]) {
      if (v[j]) {
        int rj = F(j);
        ans -= a[d[i]] * s[rj] * s[d[i]];
        s[d[i]] += s[rj];
      }
    }
    for (int j : e[d[i]]) {
      if (v[j]) {
        f[F(j)] = d[i];
      }
    }
  }
  cout << ans;
  return 0;
}