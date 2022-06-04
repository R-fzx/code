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

const int kN = 1e5 + 1, kL = 31;

int n, p[kN * kL][2], c, d[kN];
vector<Pii> e[kN];

void D(int x, int f, int v) {
  d[x] = v;
  int o = 1;
  for (int i = kL - 1; ~i; --i) {
    int &j = p[o][v >> i & 1];
    if (!j) {
      j = ++c;
    }
    o = j;
  }
  for (auto [y, w] : e[x]) {
    if (y != f) {
      D(y, x, v ^ w);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x, y, z; i < n; ++i) {
    cin >> x >> y >> z;
    e[x].emplace_back(y, z), e[y].emplace_back(x, z);
  }
  D(1, 0, 0);
  int m = 0;
  for (int i = 1; i <= n; ++i) {
    debug("%d ", d[i]);
    int x = 1, s = 0;
    for (int j = kL - 1; ~j; --j) {
      int k = p[x][d[i] >> j & 1 ^ 1];
      if (k) {
        s |= 1 << j, x = k;
      } else {
        x = p[x][d[i] >> j & 1];
      }
    }
    debug("%d ", s);
    m = max(m, s);
  }
  debug("\n");
  cout << m;
  return 0;
}