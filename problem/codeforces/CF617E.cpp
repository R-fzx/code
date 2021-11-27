#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using LL = long long;

const int kN = 1e5 + 1, kV = 1 << 20;

int n, m, k, b;
LL a[kN], c[kV], s, ans[kN];
struct Q {
#define id(x) (x / b)
  int l, r, i;
  bool operator<(const Q &o) const {
    return (id(l) ^ id(o.l)) ? l < o.l : ((id(l) & 1) ? r < o.r : r > o.r);
  }
} q[kN];

void A(int x) { s += c[x ^ k], ++c[x]; }
void D(int x) { --c[x], s -= c[x ^ k]; }

int main() {
  cin >> n >> m >> k;
  b = sqrt(n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> q[i].l >> q[i].r;
    q[i].i = i, --q[i].l;
  }
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
/*
[l-1,r]
a[i]^a[j]=k

*/