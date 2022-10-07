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
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kK = 12, kN = 1 << kK;

int k, n;
bool v[kN], b[kN + kK];

bool D(int i, int x) {
  // debug("%d %d\n", i, x);
  if (i == n + k) {
    for (int j = 1; j <= n; ++j) {
      cout << b[j];
    }
    cout << '\n';
    return 1;
  }
  if (v[x] || i > n && (x & 1)) {
    return 0;
  }
  v[x] = 1, b[i] = x & 1;
  if (D(i + 1, (x << 1) & (n - 1))) {
    return 1;
  }
  if (D(i + 1, (x << 1) & (n - 1) | 1)) {
    return 1;
  }
  v[x] = 0;
  return 0;
}

int main() {
  RF("taiko");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> k, n = 1 << k;
  cout << n << ' ';
  D(k, 0);
  return 0;
}