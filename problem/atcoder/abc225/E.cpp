#include <iostream>
#include <algorithm>

using namespace std;

const int kN = 2e5 + 1;

struct E {
  struct F {
    int a, b;
    bool operator<(const F &o) const { return 1LL * a * o.b < 1LL * o.a * b; }
    bool operator<=(const F &o) const { return 1LL * a * o.b <= 1LL * o.a * b; }
  } l, r;
} e[kN];

int n, f[kN], d[2][kN];

int main() {
  cin >> n;
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    e[i].l = {y, x - 1}, e[i].r = {y - 1, x}, d[0][i] = d[1][i] = i;
  }
  sort(d[0] + 1, d[0] + n + 1, [](int i, int j) { return e[i].l < e[j].l; });
  sort(d[1] + 1, d[1] + n + 1, [](int i, int j) { return e[i].r < e[j].r; });
  f[d[0][1]] = 1;
  for (int i = 2, j = 1, m = -1; i <= n; ++i) {
    for (; j <= n && e[d[1][j]].r <= e[d[0][i]].l; ++j) m = max(m, f[d[1][j]]);
    f[d[0][i]] = m + 1;
  }
  cout << f[d[0][n]];
  return 0;
}
/*
a/b<o.a/o.b
a*o.b<o.a*b
*/