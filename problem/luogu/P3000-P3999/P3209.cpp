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

const int kN = 1e5 + 1;

int t, n, m, p[kN], f[kN];
Pii a[kN];
bool v[kN];

int F(int x) { return f[x] == x ? x : (f[x] = F(f[x])); }
bool C(int i, int j) {
  return a[i].first < a[j].first && a[j].first < a[i].second && a[i].second < a[j].second || a[j].first < a[i].first && a[i].first < a[j].second && a[j].second < a[i].second;
}
bool S() {
  for (int i = 1; i <= m; ++i) {
    if (!v[i]) {
      for (int j = 1; j <= m; ++j) {
        if (!v[j] && C(i, j)) {
          if (F(i) == F(j)) {
            return 1;
          }
          f[F(i)] = F(j + m), f[F(j)] = F(i + m);
        }
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
      cin >> a[i].first >> a[i].second;
    }
    for (int i = 1, x; i <= n; ++i) {
      cin >> x;
      p[x] = i;
    }
    if (m <= 5 * n) {
      iota(f + 1, f + m + m + 1, 1);
      for (int i = 1; i <= m; ++i) {
        a[i].first = p[a[i].first], a[i].second = p[a[i].second];
        if (a[i].first > a[i].second) {
          swap(a[i].first, a[i].second);
        }
        v[i] = a[i].first + 1 == a[i].second || a[i].first == 1 && a[i].second == n;
      }
      cout << (S() ? "NO" : "YES") << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}