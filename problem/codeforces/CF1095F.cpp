#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;
using LL = long long;

const int kN = 2e5 + 1;

int n, m, f[kN], d[kN];
LL a[kN], s;
struct {
  int x, y;
  LL w;
} e[kN << 1];

int F(int x) { return f[x] == x ? x : (f[x] = F(f[x])); }

int main() {
  cin >> n >> m;
  iota(f + 1, f + n + 1, 1), iota(d + 1, d + n + 1, 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(d + 1, d + n + 1, [](int i, int j) { return a[i] < a[j]; });
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].x >> e[i].y >> e[i].w;
    e[i].w = min(e[i].w, a[e[i].x] + a[e[i].y]);
  }
  for (int i = 1; i < n; ++i) e[i + m] = {d[1], d[i + 1], a[d[1]] + a[d[i + 1]]};
  sort(e + 1, e + n + m, [](auto i, auto j) { return i.w < j.w; });
  for (int i = 1; i < n + m; ++i) {
    int rx = F(e[i].x), ry = F(e[i].y);
    if (rx != ry) s += e[i].w, f[rx] = ry;
  }
  cout << s;
  return 0;
}