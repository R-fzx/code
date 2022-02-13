#include <iostream>

using namespace std;
using LL = long long;

const int kN = 1e5 + 1;

struct E {
  LL s, k, d;
} e[kN << 2];
int n, q, a[kN], o, l, r, k, d;

void Build(int x, int l, int r) {
  if (l == r) {
    e[x].s = a[l];
    return;
  }
  int m = l + r >> 1;
  Build(x * 2, l, m), Build(x * 2 + 1, m + 1, r);
  e[x].s = e[x * 2].s + e[x * 2 + 1].s;
}
void Add(int x, LL k, LL d, int l, int r) {
  e[x].s += (k + k + (r - l) * d) * (r - l + 1) / 2;  // 加上等差数列
  e[x].k += k, e[x].d += d;                           // 标记直接相加
}
LL Do(int x, int l, int r, int tl, int tr, LL k, LL d) {
  if (l == tl && r == tr) {
    Add(x, k, d, l, r);
    return e[x].s;
  }
  int m = l + r >> 1;
  LL s = 0;
  Add(x * 2, e[x].k, e[x].d, l, m), Add(x * 2 + 1, e[x].k + (m - l + 1) * e[x].d /* 注意加上 (m - l + 1) * d */, e[x].d, m + 1, r), e[x].k = e[x].d = 0;
  if (tl <= m) {
    s += Do(x * 2, l, m, tl, min(tr, m), k, d);
  }
  if (m < tr) {
    s += Do(x * 2 + 1, m + 1, r, max(tl, m + 1), tr, k + max(0, m - tl + 1) * d /* 同理，注意 tl 可能大于 m */, d);
  }
  e[x].s = e[x * 2].s + e[x * 2 + 1].s;
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  Build(1, 1, n);
  while (q--) {
    cin >> o >> l;
    if (o == 1) {
      cin >> r >> k >> d;
      Do(1, 1, n, l, r, k, d);
    } else {
      cout << Do(1, 1, n, l, l, 0, 0) << '\n';
    }
  }
  return 0;
}
