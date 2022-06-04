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

const int kN = 1e5 + 1;

int t, q, o;
LL p, x, e[kN << 2];

void B(int x, int l, int r) {
  if (l == r) {
    e[x] = 1;
    return;
  }
  int m = l + r >> 1;
  B(x * 2, l, m), B(x * 2 + 1, m + 1, r);
  e[x] = e[x * 2] * e[x * 2 + 1] % p;
}
void U(int x, int l, int r, int t, LL v) {
  debug("U %d %d %d %d %lld %lld\n", x, l, r, t, v, e[x]);
  if (l == r) {
    e[x] = v % p;
  debug("S %d %d %d %d %lld %lld\n", x, l, r, t, v, e[x]);
    return;
  }
  int m = l + r >> 1;
  if (t <= m) {
    U(x * 2, l, m, t, v);
  } else {
    U(x * 2 + 1, m + 1, r, t, v);
  }
  e[x] = e[x * 2] * e[x * 2 + 1] % p;
  debug("E %d %d %d %d %lld %lld\n", x, l, r, t, v, e[x]);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> q >> p;
    B(1, 1, q);
    for (int i = 1; i <= q; ++i) {
      cin >> o >> x;
      if (o == 1) {
        U(1, 1, q, i, x);
      } else {
        U(1, 1, q, x, 1);
      }
      debug("\n");
      cout << e[1] << endl;
    }
  }
  return 0;
}