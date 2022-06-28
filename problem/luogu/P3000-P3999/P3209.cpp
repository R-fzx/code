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

const int kN = 601;

int t, n, m, p[kN];
Pii a[kN];
vector<int> e[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--; ) {
    cin >> n >> m;
    if (m > 3 * n - 6) {
      cout << "NO\n";
    } else {
      for (int i = 1; i <= m; ++i) {
        cin >> a[i].first >> a[i].second;
      }
      for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        p[x] = i;
      }
      for (int i = 1; i <= m; ++i) {
        a[i].first = p[a[i].first], a[i].second = p[a[i].second];
      }
    }
  }
  return 0;
}