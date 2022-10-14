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

const int kN = 1e5 + 1;

int n;
LL ans, a[kN], p = 1;

int main() {
  RF("bus");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> a[1];
  for (int i = 2; i <= n; ++i) {
    cin >> a[i];
    if (a[i] < a[p]) {
      ans += a[p] * (i - p), p = i;
    }
  }
  cout << ans + a[p] * (n - p + 1);
  return 0;
}