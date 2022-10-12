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

const int kN = 11;

LL ans;
bool a[kN][kN];

void D(int x, int y, int c) {
  if (c == kN) {
    ++ans;
    for (int i = 1; i < kN; ++i) {
      for (int j = 1; j < kN; ++j) {
        cout << a[i][j];
      }
      cout << '\n';
    }
    cout << '\n';
    return;
  }
  if (y == x + 1) {
    D(x + 1, 1, c);
    return;
  }
  if (x == kN) {
    return;
  }
  int i = x + 1 - y, j = y;
  if (a[i - 1][j] || a[i][j - 1]) {
    a[i][j] = 1, D(x, y + 1, c + 1);
  }
  a[i][j] = 0, D(x, y + 1, c);
}

int main() {
  freopen("test.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  a[1][1] = 1;
  D(2, 1, 2);
  cout << ans;
  return 0;
}