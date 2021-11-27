#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int kN = 40001, kQ = 100001, kL = 16;

int n, m, b, a[kN], b[kN], c[kN], _c[kN], d[kN], f[kN][kL], p[kN][2], _p[kN << 1], pc, ans[kQ], s;
vector<int> e[kN];
struct Q {
#define id(x) (x / b)
  int l, r, i;
  bool operator<(const Q &o) const {
    return (id(l) ^ id(o.l)) ? l < o.l : ((id(l) & 1) ? r < o.r : r > o.r);
  }
} q[kQ];

void _D(int x, int _f) {
  d[x] = d[_f] + 1, f[x][0] = _f, p[x][0] = ++pc, _p[pc] = x;
  for (int i = 1; i < kL; ++i) f[x][i] = f[f[x][i - 1]][i - 1];
  for (int i : e[x]) (i ^ _f) && (_D(i, x), 0);
  p[x][1] = ++pc, _p[pc] = x;
}
void U(int x, bool f) { f ? (s += !_c[a[x]]++) : (s -= !--_c[a[x]]); }

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  copy_n(a + 1, n, b + 1), sort(b + 1, b + n + 1);
  int l = unique(b + 1, b + n + 1) - b;
  for (int i = 1; i <= n; ++i) a[i] = lower_bound(b + 1, b + l, a[i]) - b;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  _D(1, 0);
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    if (d[x] < d[y]) swap(x, y);
    int _x = x, _y = y;
    for (int i = 0; i < kL; ++i)
      if (d[_x] - d[_y] >> i & 1) _x = f[_x][i];
    for (int i = kL - 1; ~i; --i)
      if (f[_x][i] ^ f[_y][i]) _x = f[_x][i], _y = f[_y][i];
    (_x ^ _y) && (_x = f[_x][0]);
    if (y == _x)
      q[i] = {p[y][0], p[x][0], i};
    else
      q[i] = (p[x][1] < p[y][0] ? Q{p[x][1], p[y][0], i} : Q{p[y][1], p[x][0], i});
  }
  b = sqrt(n <<= 1);
  sort(q + 1, q + m + 1);
  for (int i = 1, l = 1, r = 0; i <= m; ++i) {
    while (l > q[i].l) U(_p[--l], c[_p[l]]++);
  }
  return 0;
}