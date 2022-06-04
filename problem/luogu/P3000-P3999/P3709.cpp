#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int kN = 2e5 + 1;

int n, m, b, a[kN], d[kN], l, ans[kN], c[kN], _c[kN], ms, s;

struct Q {
#define id(x) x / b
  int l, r, i;
  bool operator<(const Q &o) const {
    return (id(l) ^ id(o.l)) ? l < o.l : ((id(l) & 1) ? r < o.r : r > o.r);
  }
} q[kN];

void A(int x) { --_c[c[x]], ++_c[++c[x]], ms = max(ms, c[x]); }
void D(int x) { --_c[c[x]], ms -= c[x] == ms && !_c[ms], ++_c[--c[x]]; }

int main() {
  freopen("P3709.in", "r", stdin);
  freopen("P3709.out", "w", stdout);
  cin >> n >> m;
  b = sqrt(n);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  copy(a + 1, a + n + 1, d + 1), sort(d + 1, d + n + 1), l = unique(d + 1, d + n + 1) - d;
  for (int i = 1; i <= n; ++i) a[i] = lower_bound(d + 1, d + l, a[i]) - d;
  for (int i = 1; i <= m; ++i) cin >> q[i].l >> q[i].r, q[i].i = i;
  sort(q + 1, q + m + 1);
  for (int i = 1, l = 1, r = 0; i <= m; ++i) {
    while (l > q[i].l) A(a[--l]);
    while (r < q[i].r) A(a[++r]);
    while (l < q[i].l) D(a[l++]);
    while (r > q[i].r) D(a[r--]);
    ans[q[i].i] = -ms;
  }
  for (int i = 1; i <= m; ++i) cout << ans[i] << endl;
  return 0;
}
/*
1 2 3 3 4 5 5
*/