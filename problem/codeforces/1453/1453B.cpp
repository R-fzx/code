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

const int kN = 2e5 + 2;

int t, n;
LL a[kN], d[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n;
    for (int i = n; i >= 1; --i) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
      d[i] = a[i] - a[i - 1];
    }
    d[n + 1] = -a[n];
    LL s = 0, ans = 0;
    for (int i = 2; i <= n; ++i) {
      s = max(s, abs(d[i]));
      if (i > 2) {
        s = max(s, abs(d[i]) + abs(d[i - 1]) - abs(d[i - 1] + d[i]));
      }
      ans += abs(d[i]);
    }
    cout << ans - s << '\n';
  }
  return 0;
}
/*
95 97 96 99
95 2 -1 3 -99


*/