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

const int kN = 21;

int n, c[kN], b[kN][kN], ans;
string a[kN];

void D(int x, int s) {
  if (c[x] == 2) {
    return;
  }
  ans = max(ans, s), ++c[x];
  for (int i = 1; i <= n; ++i) {
    if (~b[x][i]) {
      D(i, s + a[i].size() - b[x][i]);
    }
  }
  --c[x];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  c[0] = 1, cin >> a[0];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      b[i][j] = -1;
      for (int k = 1; k <= min(a[i].size(), a[j].size()); ++k) {
        if (a[i].substr(a[i].size() - k, k) == a[j].substr(0, k)) {
          b[i][j] = k;
          break;
        }
      }
      if (i == j && b[i][j] == a[i].size()) {
        b[i][j] = -1;
      }
      debug("%d ", b[i][j]);
    }
    debug("\n");
  }
  D(0, 1);
  cout << ans;
  return 0;
}