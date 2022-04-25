#include <algorithm>
#include <iostream>

using namespace std;

const int kMaxN = 2e5 + 1;

struct T {
  int s, a = -1;
} t[kMaxN * 4];
int n, q, x, y, p, o, c, l, r, s;

void U(int i, int l, int r, int tl, int tr, int v) {
  if (l == tl && r == tr) {
    if (v == -1) {
      s += t[i].s;
    } else {
      t[i].a = v, t[i].s = (r - l + 1) * v;
    }
    return;
  }
  int m = (l + r) / 2;
  if (t[i].a != -1) {
    U(i * 2, l, m, l, m, t[i].a), U(i * 2 + 1, m + 1, r, m + 1, r, t[i].a);
    t[i].a = -1;
  }
  if (tl <= m) {
    U(i * 2, l, m, tl, min(tr, m), v);
  }
  if (tr > m) {
    U(i * 2 + 1, m + 1, r, max(m + 1, tl), tr, v);
  }
  t[i].s = t[i * 2].s + t[i * 2 + 1].s;
}

int main() {
  cin >> n >> q >> x;
  for (int i = 1; i <= n; i++) {
    cin >> y;
    U(1, 1, n, i, i, y < x);
    y == x && (p = i);
  }
  while (q--) {
    cin >> c >> l >> r;
    int b = l <= p && p <= r;
    s = 0, U(1, 1, n, l, r, -1);
    if (c == 1) {
      U(1, 1, n, l, l + s - 1, 1);
      U(1, 1, n, l + s, r, 0);
      b && (p = l + s);
    } else {
      U(1, 1, n, r - s + 1, r, 1);
      U(1, 1, n, l, r - s, 0);
      b && (p = r - s);
    }
  }
  cout << p;
  return 0;
}