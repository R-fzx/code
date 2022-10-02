#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

struct Node {
  int v, l, r;
} a[MAXN * MAXN];

bool cmp(Node a, Node b) {
  return a.v > b.v;
}

int main() {
  freopen("garland.in", "r", stdin);
  freopen("garland.out", "w", stdout);
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i * n + j].v;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i * n + j].l;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i * n + j].r;
    }
  }
  sort(a, a + n * n - 1, cmp);
  int x = a[0].r, y = a[n * n - 1].l;
  for (int l = 0, r = n * n - 1; a[l].v != a[r].v && l < r;) {
    if (x + y > 0) {
      ans += -y * a[l].v + y * a[r].v;
      x += y, y -= y;
      y += a[--r].l;
    } else if (x + y < 0) {
      ans += x * a[l].v + -x * a[r].v;
      y += x, x -= x;
      x += a[++l].r;
    }
  }
  cout << ans;
  return 0;
}