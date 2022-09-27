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

int t, x, y;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--; ) {
    cin >> x >> y;
    if (x % 2 == y % 2) {
      if (x & 1) {
        cout << x / 2 << ' ' << y / 2 + 1 << '\n';
      } else {
        cout << x / 2 << ' ' << y / 2 << '\n';
      }
    } else {
      cout << "-1 -1\n";
    }
  }
  return 0;
}