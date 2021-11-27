#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
using Pii = pair<int, int>;

const int kN = 2e5 + 1;

int n, m, b, a[kN], d[kN], nr, nq, o, c[kN << 1], _c[kN << 1], ans[kN];
Pii r[kN];
struct Q {
  int l, r, t, i;
#define id(x) (x / b)
  bool operator<(const Q &o) const {
    return (id(l) ^ id(o.l)) ? l < o.l : ((id(r) ^ id(o.r)) ? ((id(l) & 1) ? r < o.r : r > o.r) : t < o.t);
  }
} q[kN];

void U(int x, int t) { --_c[c[x]], ++_c[c[x] += t]; }
void U(int _l, int _r, int t) {
  int &x = r[t].first, &y = r[t].second;
  swap(a[x], y), _l <= x &&x <= _r && (U(a[x], 1), U(y, -1), 0);
}

int main() {
  cin >> n >> m;
  b = pow(n, 2.0 / 3);
  for (int i = 1; i <= n; ++i) cin >> a[i], d[i] = a[i];
  for (int i = 1; i <= m; ++i) {
    cin >> o;
    if (o ^ 1) {
      cin >> r[++nr].first >> r[nr].second, d[nr + n] = r[nr].second;
    } else {
      cin >> q[++nq].l >> q[nq].r, q[nq].t = nr, q[nq].i = nq;
    }
  }
  sort(d + 1, d + n + nr + 1);
  int l = unique(d + 1, d + n + nr + 1) - d;
  for (int i = 1; i <= n; ++i) a[i] = lower_bound(d + 1, d + l, a[i]) - d;
  for (int i = 1; i <= nr; ++i) r[i].second = lower_bound(d + 1, d + l, r[i].second) - d;
  sort(q + 1, q + nq + 1);
  for (int i = 1, l = 1, r = 0, t = 0; i <= nq; ++i) {
    while (l > q[i].l) U(a[--l], 1);
    while (r < q[i].r) U(a[++r], 1);
    while (l < q[i].l) U(a[l++], -1);
    while (r > q[i].r) U(a[r--], -1);
    while (t < q[i].t) U(l, r, ++t);
    while (t > q[i].t) U(l, r, t--);
    for (ans[q[i].i] = 1; _c[ans[q[i].i]];) ++ans[q[i].i];
  }
  for (int i = 1; i <= nq; ++i) cout << ans[i] << endl;
  return 0;
}