#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...)
#endif

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;

int read() {
  int x = 0, f = 0; char ch = getchar();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x * 10) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}

typedef double db;

const int kMaxN = 205, kMaxK = 4e4 + 5;

struct Node {
  int a; double p;
} a[kMaxN];

int n, l, t, mx, cm;
db f[kMaxN], g[kMaxN][kMaxK];

bool cmp(Node a, Node b) {
  return a.a < b.a;
}

int main() {
  file("guard");
  n = read(), l = read(), t = read();
  for (int i = 1; i <= n; ++i) {
    a[i].p = read();
    a[i].p /= 100.0;
  }
  for (int i = 1; i <= n; ++i) {
    a[i].a = read();
    if (a[i].a == -1) ++cm;
    a[i].a = min(n, a[i].a);
  }
  sort(a + 1, a + 1 + n, cmp);
  f[0] = 1;
  for (int i = 1; i <= cm; ++i) {
    for (int j = i; ~j; --j) {
      f[j] = f[j] * (1 - a[i].p);
      if (j >= 1) f[j] += f[j - 1] * a[i].p;
    }
  }
  g[0][t] = 1;
  mx = t;
  for (int i = cm + 1; i <= n; ++i) {
    mx += a[i].a;
    for (int j = i - cm; ~j; --j) {
      for (int k = mx; ~k; --k) {
        g[j][k] = g[j][k] * (1 - a[i].p);
        if (j >= 1 && k >= a[i].a) g[j][k] += g[j - 1][k - a[i].a] * a[i].p;
      }
    }
  }
  db ans = 0;
  for (int i = 0; i <= cm; ++i) {
    for (int j = max(l - i, 0); j <= n - cm; ++j) {
      for (int k = i; k <= mx; ++k) {
        ans += f[i] * g[j][k];
      }
    }
  }
  printf("%.6lf\n", ans);
  cerr << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  return 0;
}