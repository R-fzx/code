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

const int kN = 5e4 + 2;

int n, m, a[kN];

bool C(int x) {
  for (int i = 0, j = m, k; i <= n; i = k) {
    for (k = i; k <= n + 1 && a[k] - a[i] < x; ++k) {
    }
    if (k > n + 1 || j < k - i - 1) {
      return 0;
    }
    j -= k - i - 1;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m >> n, a[n + 1] = m, cin >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int l = 1, r = 1e9;
  while (l < r) {
    int x = l + r + 1 >> 1;
    if (C(x)) {
      l = x;
    } else {
      r = x - 1;
    }
  }
  cout << l;
  return 0;
}