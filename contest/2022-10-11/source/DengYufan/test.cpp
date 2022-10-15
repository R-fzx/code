#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int kMaxN = 1e5 + 1;
struct V {
  int l, r, d;
} v[kMaxN];
int n, m, q, a[kMaxN], b[kMaxN], l[kMaxN], ans[kMaxN];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l[i] = i;
  }
  m = sqrt(n);
  sort(l + 1, l + n + 1, [](int i, int j) { return a[i] < a[j]; });
  for (int i = 1; i <= n; i++) {
    b[l[i]] = b[l[i - 1]] + (a[l[i]] != a[l[i - 1]]);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= q; i++) {
    cin >> v[i].l >> v[i].r;
    v[i].d = i;
  }
  sort(v + 1, v + q + 1, [](V i, V j) { return (i.l - 1) / m == (j.l - 1) / m ? i.r < j.r : i.l < j.l; });
  for (int i = 1, j, k, t, _t; i <= q; i++) {
    if (i == 1 || (v[i].l - 1) / m != (v[i - 1].l - 1) / m) {
      k = (v[i].l - 1) / m * m + m, j = k + 1, t = 0;
    }
  }
  return 0;
}
