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

const int kN = 101;

int t, n, m, a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    fill_n(a + 1, 100, 0);
    for (int i = 1, x; i <= n; ++i) {
      cin >> x;
      a[x] = 1;
    }
    for (int i = 1, x; i <= m; ++i) {
      cin >> x;
      a[x] = 1;
    }
    cout << n + m - count(a + 1, a + 101, 1) << '\n';
  }
  return 0;
}