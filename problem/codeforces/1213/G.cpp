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

struct E {
  int x, y, w;
  bool operator<(const E &o) const { return w < o.w; }
} e[kN];
int n, m, f[kN], s[kN], d[kN];
LL q[kN], _p, p[kN];

int F(int x) { return x == f[x] ? x : (f[x] = F(f[x])); }
LL C(LL x) { return x * (x - 1) / 2; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  iota(f + 1, f + n + 1, 1), fill_n(s + 1, n, 1);
  for (int i = 1; i < n; ++i) {
    cin >> e[i].x >> e[i].y >> e[i].w;
  }
  sort(e + 1, e + n);
  for (int i = 1; i <= m; ++i) {
    cin >> q[i];
    d[i] = i;
  }
  sort(d + 1, d + m + 1, [](int i, int j) { return q[i] < q[j]; });
  for (int i = 1, j = 1; i <= m; ++i) {
    for (; j < n && e[j].w <= q[d[i]]; ++j) {
      int rx = F(e[j].x), ry = F(e[j].y);
      _p -= C(s[rx]) + C(s[ry]), s[rx] += s[ry], f[ry] = rx, _p += C(s[rx]);
    }
    p[d[i]] = _p;
  }
  for (int i = 1; i <= m; ++i) {
    cout << p[i] << " ";
  }
  return 0;
}