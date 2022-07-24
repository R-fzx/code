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

const int kN = 51;

int n, m, k, q, a[kN][kN], b[kN][kN];
const function<void(int, int)> kF[7] = {
  [&](int x, int y) {},
  [&](int x, int y) {
    for (int i = 1; i <= m; ++i) {
      for (int j = x; j >= 1; --j) {
        a[j][i] = a[j - 1][i], b[j][i] = b[j - 1][i];
      }
    }
  },
  [&](int x, int y) {
    
  }
};


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> b[i][j];
    }
  }
  for (int x1, y1, x2, y2; q--; ) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (abs(x1 - x2) + abs(y1 - y2) == 1) {
      
    }
  }
  return 0;
}