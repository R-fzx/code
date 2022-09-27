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

const int kN = 2e5 + 1;

int t, n, k;
LL a[kN], s[kN], f[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i], s[i] = s[i - 1] + a[i];
    }
    f[k] = 0;
    for (int i = k - 1; i >= 1; --i) {
      f[i] = f[i + 1] + max(0LL, -a[i]);
    }
  }
  return 0;
}