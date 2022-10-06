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
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1, kM = 3e5 + 1;
const LL kMod = 1000000009;

int n, m, d[kN], f[kN];
Pii e[kM];
LL c;

int F(int x) { return x == f[x] ? x : (f[x] = F(f[x])); }

int main() {
  RF("magician");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  if (m <= 30 && (1LL << m) * n * m <= 50000000) {
    for (int i = 1; i <= m; ++i) {
      cin >> e[i].first >> e[i].second;
      c = 0;
      for (LL j = 1; j < (1LL << i); ++j) {
        fill(d + 1, d + n + 1, 0);
        for (int k = 0; k < i; ++k) {
          if (j >> k & 1) {
            ++d[e[k + 1].first], ++d[e[k + 1].second];
          }
        }
        bool f = 1;
        for (int k = 1; k <= n; ++k) {
          f &= !(d[k] & 1);
        }
        c = (c + f) % kMod;
      }
      cout << c << '\n';
    }
    return 0;
  }
  iota(f + 1, f + n + 1, 1);
  LL s = 1;
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].first >> e[i].second;
    if (F(e[i].first) == F(e[i].second)) {
      s = s * 2 % kMod;
    } else {
      f[F(e[i].first)] = F(e[i].second);
    }
    cout << (s - 1 + kMod) % kMod << '\n';
  }
  return 0;
}