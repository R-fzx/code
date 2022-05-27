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

const int kN = 4e4 + 1, kM = 1e5 + 1, kB = 200, kL = 16;

struct Q {
  int l, r, d, x;
  bool operator<(const Q &o) const {
    return l / kB == o.l / kB ? r < o.r : l < o.l;
  }
} q[kM];
int n, m, a[kN], f[kN][kL], d[kN], l[kN << 1], p[kN][2], _c, c[kN], s, v[kN], ans[kM];
vector<int> e[kN];

void D(int x, int _f) {
  l[p[x][0] = ++_c] = x, d[x] = d[f[x][0] = _f] + 1;
  for (int i = 1; i < kL; ++i) {
    f[x][i] = f[f[x][i - 1]][i - 1];
  }
  for (int i : e[x]) {
    if (i ^ _f) {
      D(i, x);
    }
  }
  l[p[x][1] = ++_c] = x;
}
int L(int x, int y) {
  if (d[x] < d[y]) {
    swap(x, y);
  }
  for (int i = 0; i < kL; ++i) {
    if (d[x] - d[y] >> i & 1) {
      x = f[x][i];
    }
  }
  for (int i = kL - 1; i >= 0; --i) {
    if (f[x][i] ^ f[y][i]) {
      x = f[x][i], y = f[y][i];
    }
  }
  return x == y ? x : f[x][0];
}
void A(int x) { s += !c[x]++; }
void D(int x) { s -= !--c[x]; }
void U(int x) { (v[x] ? (D(a[x]), 0) : (A(a[x]), 0)), v[x] ^= 1; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    l[i] = a[i];
  }
  sort(l + 1, l + n + 1);
  int _n = unique(l + 1, l + n + 1) - l;
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(l + 1, l + _n, a[i]) - l;
    // debug("%d ", a[i]);
  }
  // debug("\n");
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  D(1, 0);
  // for (int i = 1; i <= 2 * n; ++i) {
    // debug("%d ", l[i]);
  // }
  // debug("\n");
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    int _f = L(x, y);
    if (_f ^ x) {
      swap(x, y);
    }
    if (_f != x && p[y][1] < p[x][0]) {
      swap(x, y);
    }
    q[i] = {p[x][_f != x], p[y][0], i, _f != x ? _f : 0};
  }
  sort(q + 1, q + m + 1);
  for (int i = 1, l = 1, r = 0; i <= m; ++i) {
    // debug("%d %d %d %d\n", q[i].l, q[i].r, q[i].d, q[i].x);
    for (; r < q[i].r; U(::l[++r])) {
    }
    for (; l > q[i].l; U(::l[--l])) {
    }
    for (; l < q[i].l; U(::l[l++])) {
    }
    for (; r > q[i].r; U(::l[r--])) {
    }
    if (q[i].x) {
      U(q[i].x);
    }
    ans[q[i].d] = s;
    if (q[i].x) {
      U(q[i].x);
    }
  }
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}