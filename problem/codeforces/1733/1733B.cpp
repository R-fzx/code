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

int t, n, x, y;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n >> x >> y;
    if (!x) {
      swap(x, y);
    }
    if (!x || y || (n - 1) % x) {
      cout << "-1\n";
    } else {
      for (int i = 2, j = 1, c = 0; i <= n; ++i) {
        cout << j << ' ';
        if (++c == x) {
          j = i + 1, c = 0;
        }
      }
      cout << '\n';
    }
  }
  return 0;
}