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

const int kN = 1e5 + 1, kV = 5;
const LL kI = 1e14;

int n;
LL a[kN][kV], f[kN][kV];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, t, x, y; i <= n; ++i) {
    cin >> t >> x >> y;
    a[t][x] = y;
  }
  f[0][0] = a[0][0], f[0][1] = f[0][2] = f[0][3] = f[0][4] = -kI;
  for (int i = 1; i < kN; ++i) {
    for (int j = 0; j < kV; ++j) {
      f[i][j] = max({j ? f[i - 1][j - 1] : -kI, j + 1 == kV ? -kI : f[i - 1][j + 1], f[i - 1][j]}) + a[i][j];
      // cout << f[i][j] << ' ';
    }
    // cout << '\n';
  }
  cout << *max_element(f[kN - 1], f[kN - 1] + kV);
  return 0;
}