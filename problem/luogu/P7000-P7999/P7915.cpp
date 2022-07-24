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

string C(int l1, int r1, int l2, int r2) {
  string s(2 * n, ' ');
  s[0] = (l1 == 1 ? 'R' : 'L'), s[2 * n - 1] = 'L';
  for (int i = 1; i < n; ++i) {
    if (l1 < r1 && a[l1] == a[r1]) {
      ++l1, --r1, s[i] = 'L', s[2 * n - 1 - i] = 'L';
    } else if (l1 <= r1 && l2 <= r2 && a[l1] == a[l2]) {
      ++l1, ++l2, s[i] = 'L', s[2 * n - 1 - i] = 'R';
    } else if (l1 <= r1 && l2 <= r2 && a[r1] == a[r2]) {
      --r1, --r2, s[i] = 'R', s[2 * n - 1 - i] = 'L';
    } else if (l2 < r2 && a[l2] == a[r2]) {
      ++l2, --r2, s[i] = 'R', s[2 * n - 1 - i] = 'R';
    } else {
      return "";
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
      cin >> a[i];
    }
    int p;
    for (int i = 2; i <= 2 * n; ++i) {
      a[i] == a[1] && (p = i);
    }
    string s = C(2, p - 1, p + 1, 2 * n);
    if (s == "") {
      for (int i = 1; i < 2 * n; ++i) {
        a[i] == a[2 * n] && (p = i);
      }
      s = C(1, p - 1, p + 1, 2 * n - 1);
      cout << (s == "" ? "-1" : s) << '\n';
    } else {
      cout << s << '\n';
    }
  }
  return 0;
}