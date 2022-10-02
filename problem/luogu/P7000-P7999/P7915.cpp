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

const int kN = 1e6 + 1;

int t, n, a[kN];
string s;

bool C(int l1, int r1, int l2, int r2, char c) {
  s[0] = c, s[n - 1] = 'L';
  for (int i = 1; i < n / 2; ++i) {
    debug("%d %d %d %d\n", l1, r1, l2, r2);
    if (l1 < r1 && a[l1] == a[r1]) {
      s[i] = s[n - 1 - i] = 'L', ++l1, --r1;
    } else if (l1 <= r1 && l2 <= r2 && a[l1] == a[l2]) {
      s[i] = 'L', s[n - 1 - i] = 'R', ++l1, ++l2;
    } else if (l1 <= r1 && l2 <= r2 && a[r1] == a[r2]) {
      s[i] = 'R', s[n - 1 - i] = 'L', --r1, --r2;
    } else if (l2 < r2 && a[l2] == a[r2]) {
      s[i] = s[n - 1 - i] = 'R', ++l2, --r2;
    } else {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n, n <<= 1;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    s.resize(n);
    int y = 2;
    for (; a[y] != a[1]; ++y) {
    }
    debug("%d\n", y);
    if (C(2, y - 1, y + 1, n, 'L')) {
      cout << s << '\n';
    } else {
      y = n - 1;
      for (; a[y] != a[n]; --y) {
      }
      debug("%d\n", y);
      if (C(1, y - 1, y + 1, n - 1, 'R')) {
        cout << s << '\n';
      } else {
        cout << "-1\n";
      }
    }
  }
  return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
    l1        l2
    r1        r2
4 1 2 4 5 3 1 2 3 5
*/