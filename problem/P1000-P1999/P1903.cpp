#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
using Pii = pair<int, int>;

const int kN = 7, kV = 7;

int n, nr, nq, m, b, a[kN], c[kN], ans[kN], s;
Pii r[kN];
char ch;
struct Q {
#define id(x) (x / b)
  int l, r, t, i;
  bool operator<(const Q &o) const {
    return (id(l) ^ id(o.l)) ? l < o.l : ((id(r) ^ id(o.r)) ? ((id(l) & 1) ? r < o.r : r > o.r) : t < o.t);
  }
} q[kN];

void A(int x) { s += !c[x]++; }
void D(int x) { s -= !--c[x]; }
void A(int _l, int _r, int t) {
  int x = r[t].first, &v = r[t].second;
  if (_l <= x && x <= _r) D(a[x]), A(v), swap(a[x], v);
}
void D(int _l, int _r, int t) {
  int x = r[t].first, &v = r[t].second;
  if (_l <= x && x <= _r) D(a[x]), A(v), swap(a[x], v);
}

int main() {
  freopen("P1903.in", "r", stdin);
  freopen("P1903.out", "w", stdout);
  cin >> n >> m;
  b = pow(n, 2.0 / 3);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) {
    cin >> ch;
    if (ch == 'Q') {
      cin >> q[++nq].l >> q[nq].r;
      q[nq].i = nq, q[nq].t = nr;
    } else {
      cin >> r[++nr].first >> r[nr].second;
    }
  }
  sort(q + 1, q + nq + 1);
  for (int i = 1, l = 1, r = 0, t = 0; i <= nq; ++i) {
    while (l > q[i].l) A(a[--l]);
    while (r < q[i].r) A(a[++r]);
    while (l < q[i].l) D(a[l++]);
    while (r > q[i].r) D(a[r--]);
    while (t < q[i].t) A(l, r, ++t);
    while (t > q[i].t) D(l, r, t--);
    ans[q[i].i] = s;
  }
  for (int i = 1; i <= nq; ++i) cout << ans[i] << endl;
  return 0;
}