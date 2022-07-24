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

const int kN = 2e4 + 1;
using V = bitset<kN>;

int t, n;
V f[2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--; ) {
    cin >> n;
    f[0] = 1;
    // cout << f[0] << '\n';
    for (int i = 1, k; i <= n; ++i) {
      cin >> k;
      f[i & 1] = 0;
      for (int j = 1, x; j <= k; ++j) {
        cin >> x;
        f[i & 1] |= f[i & 1 ^ 1] << (int)log(x);
      }
      // cout << f[i & 1] << '\n';
    }
    cout << f[n & 1].count() << '\n';
  }
  return 0;
}