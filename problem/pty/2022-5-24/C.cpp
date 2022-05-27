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

const int kN = 2e5 + 1;

int n, a[kN], q[kN], h, t, d[2][kN];
vector<int> e[kN];

void R(int x, int _d, int o) {
  if (!~d[o][x]) {
    d[o][x] = _d, q[++t] = x;
  }
}
void S(int o) {
  h = 1, t = 0;
  debug("S(%d)\n", o);
  for (int i = 1; i <= n; ++i) {
    if (i - a[i] >= 1) {
      e[i - a[i]].push_back(i);
    }
    if (i + a[i] <= n) {
      e[i + a[i]].push_back(i);
    }
    d[o][i] = -1;
    if ((a[i] & 1) == o) {
      R(i, 0, o);
    }
  }
  for (; h <= t; ++h) {
    int x = q[h];
    for (int i : e[x]) {
      R(i, d[o][x] + 1, o);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  S(0), S(1);
  for (int i = 1; i <= n; ++i) {
    debug("%d %d\n", d[0][i], d[1][i]);
    cout << d[a[i] & 1 ^ 1][i] << ' ';
  }
  return 0;
}