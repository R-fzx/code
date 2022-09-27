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

const int kN = 1e5 + 1;

int t, n, a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--; ) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    cout << n - 1 << '\n';
    if (a[1] & 1) {
      for (int i = n; i > 1; --i) {
        if (a[i] & 1) {
          for (int j = 1; j < i; ++j) {
            if (a[j] & 1) {
              cout << j << ' ' << i << '\n';
            }
          }
          break;
        }
      }
      for (int i = 2; i <= n; ++i) {
        if (!(a[i] & 1)) {
          cout << "1 " << i << '\n';
        }
      }
    } else {
      for (int i = n; i > 1; --i) {
        if (!(a[i] & 1)) {
          for (int j = 1; j < i; ++j) {
            if (!(a[j] & 1)) {
              cout << j << ' ' << i << '\n';
            }
          }
          break;
        }
      }
      for (int i = 2; i <= n; ++i) {
        if (a[i] & 1) {
          cout << "1 " << i << '\n';
        }
      }
    }
  }
  return 0;
}
/*
eeeooeoeeooo
eeeeeeeeeee
5 5 5 5 5
*/