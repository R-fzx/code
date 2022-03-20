#include <algorithm>
#include <iostream>

using namespace std;

const int kN = 2e5 + 1;

struct E {
  int l, r, x;
  bool operator<(const E& o) const {
    return r < o.r || r == o.r && l > o.l;
  }
} a[kN];
int n, m, e[kN << 2];
bool b[kN];

int Do(int o, int x, int l, int r, int tl, int tr, int v) {
  if (l == tl && r == tr) {
    if (o == 1) {  // Add
      return e[x] += v;
    } else if (o == 2) {  // Sum
      return e[x];
    } else {  // Last
      for (; l ^ r;) {
        int m = l + r >> 1;
        if (e[x * 2 + 1] < r - m) {
          x = x * 2 + 1, l = m + 1;
        } else {
          x = x * 2, r = m;
        }
      }
      return e[x] ? 0 : l;
    }
  }
  int m = l + r >> 1, s = 0;
  if (m < tr) {
    s = Do(o, x * 2 + 1, m + 1, r, max(m + 1, tl), tr, v);
  }
  if (s && o == 3) {
    return s;
  }
  if (tl <= m) {
    s += Do(o, x * 2, l, m, tl, min(m, tr), v);
  }
  e[x] = e[x * 2] + e[x * 2 + 1];
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i].l >> a[i].r >> a[i].x;
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1, x, s = Do(2, 1, 1, n, a[i].l, a[i].r, 0); j <= a[i].x - s; ++j) {
      b[x = Do(3, 1, 1, n, a[i].l, a[i].r, 0)] = 1, Do(1, 1, 1, n, x, x, 1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << b[i] << " ";
  }
  return 0;
}