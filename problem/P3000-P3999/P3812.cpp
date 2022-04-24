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

const int kN = 51;

int n;
LL a[kN], x, ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    for (int j = kN - 1; ~j; --j) {
      if (x >> j & 1) {
        if (!a[j]) {
          a[j] = x;
          break;
        }
        x ^= a[j];
      }
    }
  }
  for (int j = kN - 1; ~j; --j) {
    ans = max(ans, ans ^ a[j]);
  }
  cout << ans;
  return 0;
}