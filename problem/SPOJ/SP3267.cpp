#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int kN = 30001, kQ = 200001, kV = 1e6 + 1;

int n, m, b, ans[kQ], a[kN], c[kV], s;

struct Q {
#define id(x) (x / b)
  int l, r, i;
  bool operator<(const Q &o) const {
    return (id(l) ^ id(o.l)) ? l < o.l : ((id(l) & 1) ? r < o.r : r > o.r);
  }
} q[kQ];

void A(int x) { s += !c[x]++; }
void D(int x) { s -= !--c[x]; }

int main() {
  cin >> n;
  b = sqrt(n);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cin >> m;
  for (int i = 1; i <= m; ++i) cin >> q[i].l >> q[i].r, q[i].i = i;
  sort(q + 1, q + m + 1);
  for (int i = 1, l = 1, r = 0; i <= m; ++i) {
    while (l > q[i].l) A(a[--l]);
    while (r < q[i].r) A(a[++r]);
    while (l < q[i].l) D(a[l++]);
    while (r > q[i].r) D(a[r--]);
    ans[q[i].i] = s;
  }
  for (int i = 1; i <= m; ++i) cout << ans[i] << endl;
  return 0;
}