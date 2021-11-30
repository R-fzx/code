#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int kN = 400001, kQ = 1e5 + 1, kL = 32;

int n, m, b, a[kN], r[kN], c[kN], _c[kN], d[kN], f[kN][kL], p[kN][2], _p[kN << 1], pc, ans[kQ], s;
vector<int> e[kN];
struct Q {
#define id(x) (x / b)
  int l, r, i, t;
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
void A(int x) { s += !_c[a[x]]++; }
void D(int x) { s -= !--_c[a[x]]; }
void U(int x) { c[x] ? D(x) : A(x), c[x] ^= 1; }

int main() {
  // freopen("SP10707.in", "r", stdin);
  // freopen("SP10707.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  copy_n(a + 1, n, r + 1), sort(r + 1, r + n + 1);
  int l = unique(r + 1, r + n + 1) - r;
  for (int i = 1; i <= n; ++i) a[i] = lower_bound(r + 1, r + l, a[i]) - r;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  _D(1, 0);
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    if (d[x] > d[y]) swap(x, y);
    int _x = x, _y = y;
    for (int i = 0; i < kL; ++i) (d[_y] - d[_x] >> i & 1) && (_y = f[_y][i]);
    for (int i = kL - 1; ~i; --i) (f[_x][i] ^ f[_y][i]) && (_x = f[_x][i], _y = f[_y][i]);
    (_x ^ _y) && (_x = f[_x][0]);
    bool _f = x ^ _x;
    _f && (p[x][1] > p[y][0]) && (swap(x, y), 0), q[i] = {p[x][_f], p[y][0], i, _f};
  }
  b = sqrt(n <<= 1);
  sort(q + 1, q + m + 1);
  for (int i = 1, l = 1, r = 0; i <= m; ++i) {
    while (l > q[i].l) U(_p[--l]);
    while (r < q[i].r) U(_p[++r]);
    while (l < q[i].l) U(_p[l++]);
    while (r > q[i].r) U(_p[r--]);
    ans[q[i].i] = s + (q[i].t && !_c[a[1]]);
  }
  for (int i = 1; i <= m; ++i) cout << ans[i] << endl;
  return 0;
}