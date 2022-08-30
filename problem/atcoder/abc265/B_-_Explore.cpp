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

int n, m, a[kN];
LL t, b[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> t;
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    b[x] = y;
  }
  for (int i = 1; i < n; ++i) {
    t += b[i];
    if (t <= a[i]) {
      cout << "No";
      return 0;
    }
    t -= a[i];
  }
  cout << "Yes";
  return 0;
}