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

const int kN = 5e4 + 1, kL = 16;

int n, m, a[kN][kL];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i][0];
  }
  for (int j = 0; j < kL - 1; ++j) {
    for (int i = 1; i <= n; ++i) {
      a[i][j + 1] = max(a[i][j], i + (1 << j) > n ? -kN : a[i + (1 << j)][j]);
    }
  }
  cin >> m;
  for (int l, r; m--;) {
    cin >> l >> r;
    int _ = r - l + 1, s = -1e9;
    for (int i = kL - 1; i >= 0; --i) {
      if (_ >> i & 1) {
        s = max(s, a[l][i]), l += 1 << i;
      }
    }
    cout << s << endl;
  }
  return 0;
}