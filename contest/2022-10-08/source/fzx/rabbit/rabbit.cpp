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

int n;

int main() {
  RF("rabbit");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  cout << n * (n - 1) / 2 << '\n';
  for (int d = 1; d <= n / 2; ++d) {
    for (int i = 0; i < n; ++i) {
      cout << (i - d + n) % n + 1 << ' ' << i + 1 << ' ' << (i + d) % n + 1 << '\n';
    }
  }
  return 0;
}
/*
1 2 3
1 2 3
1 2 3
1 4 5
1 4 5
1 4 5
2 4 5
2 4 5
2 4 5

1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
*/