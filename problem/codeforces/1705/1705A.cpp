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

const int kN = 201;

int t, n, x, a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> x;
    for (int i = 1; i <= 2 * n; ++i) {
      cin >> a[i];
    }
    sort(a + 1, a + 2 * n + 1);
    bool f = 1;
    for (int i = 1; i <= n; ++i) {
      f &= a[i + n] - a[i] >= x;
    }
    cout << (f ? "YES" : "NO") << '\n';
  }
  return 0;
}