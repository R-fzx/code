#include <algorithm>
#include <cmath>
#include <iostream>
#define id(x) (x / b)

using namespace std;
using LL = long long;

const int kN = 50001;

int n, m, k, b, a[kN], c[kN];
LL s, ans[kN];

struct Q {
  int l, r, i;
  bool operator<(const Q &o) const {
    return (id(l) ^ id(o.l)) ? l < o.l : ((id(l) & 1) ? r < o.r : r > o.r);
  }
} q[kN];

void A(int x) { s += (c[x]++ << 1) + 1; }
void D(int x) { s -= (--c[x] << 1) + 1; }

int main() {
  cin >> n >> m >> k;
  b = sqrt(n);
  for (int i = 1; i <= n; ++i) cin >> a[i];
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