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

const int kN = 2e5 + 1;

struct Q {
  int o, x, c;
} a[kN];
int q, l[kN], t, e[kN << 2];

void U(int x, int l, int r, int tx, int v) {
  if (l == r) {
    e[x] = max(0, e[x] + v);
    return;
  }
  int m = l + r >> 1;
  if (tx <= m) {
    U(x * 2, l, m, tx, v);
  } else {
    U(x * 2 + 1, m + 1, r, tx, v);
  }
  e[x] = e[x * 2] + e[x * 2 + 1];
}
int F(int x, int l, int r, int o) {
  if (l == r) {
    return l;
  }
  int m = l + r >> 1;
  if (!o) {
    if (e[x * 2]) {
      return F(x * 2, l, m, o);
    } else {
      return F(x * 2 + 1, m + 1, r, o);
    }
  } else {
    if (e[x * 2 + 1]) {
      return F(x * 2 + 1, m + 1, r, o);
    } else {
      return F(x * 2, l, m, o);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> a[i].o;
    if (a[i].o != 3) {
      cin >> a[i].x;
      l[++t] = a[i].x;
    }
    if (a[i].o == 2) {
      cin >> a[i].c;
    }
  }
  sort(l + 1, l + t + 1), t = unique(l + 1, l + t + 1) - l;
  for (int i = 1; i <= q; ++i) {
    if (a[i].o != 3) {
      a[i].x = lower_bound(l + 1, l + t, a[i].x) - l;
    }
    if (a[i].o == 1) {
      U(1, 1, t, a[i].x, 1);
    } else if (a[i].o == 2) {
      U(1, 1, t, a[i].x, -a[i].c);
    } else {
      // cout << F(1, 1, t, 1) << " " << F(1, 1, t, 0) << endl;
      cout << l[F(1, 1, t, 1)] - l[F(1, 1, t, 0)] << endl;
    }
  }

  return 0;
}