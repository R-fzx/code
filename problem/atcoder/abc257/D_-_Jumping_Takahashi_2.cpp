#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using mL = modint998244353;

const int kN = 201;

int n, h, t, q[kN];
Pll a[kN];
LL p[kN];
bool v[kN];

void R(int x) {
  if (!v[x]) {
    q[++t] = x, v[x] = 1;
  }
}
bool C(LL m) {
  for (int i = 1; i <= n; ++i) {
    h = 1, t = 0, fill_n(v + 1, n, 0);
    for (R(i); h <= t; ++h) {
      int x = q[h];
      for (int j = 1; j <= n; ++j) {
        if (p[x] * m >= abs(a[x].first - a[j].first) + abs(a[x].second - a[j].second)) {
          R(j);
        }
      }
    }
    bool f = 1;
    for (int j = 1; j <= n; ++j) {
      f &= v[j];
    }
    if (f) {
      return 1;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second >> p[i];
  }
  LL l = 0, r = 5e9;
  for (LL m; l < r;) {
    m = l + r >> 1;
    if (C(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l;
  return 0;
}