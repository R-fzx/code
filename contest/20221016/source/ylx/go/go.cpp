#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 105, M = 2005;

struct E {
  int a, b, t;
} a[N];

int n, k, m, T, f[N][N][M][2], r;

int main() {
  freopen("go.in", "r", stdin);
  freopen("go.out", "w", stdout);
  cin >> n >> k >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].a >> a[i].b >> a[i].t;
    T = max(T, a[i].t);
  }
  sort(a + 1, a + m + 1, [](E x, E y) { return x.a < y.a; });
  for (int i = 1; i <= m; i++) {
    f[i][i][abs(a[i].a - k) + 1][0] = f[i][i][abs(a[i].a - k) + 1][1] = a[i].b;
  }
  for (int l = 2; l <= m; l++) {
    for (int i = 1; i + l - 1 <= m; i++) {
      int j = i + l - 1;
      for (int o = 1; o <= min(a[i].t, a[j].t); o++) {
        if (o > abs(a[i].a - a[i + 1].a)) {
          f[i][j][o][0] = max(f[i][j][o][0], f[i + 1][j][o - abs(a[i].a - a[i + 1].a)][0] + a[i].b);
        }
        if (o > abs(a[i].a - a[j].a) + 1) {
          f[i][j][o][0] = max(f[i][j][o][0], f[i + 1][j][o - abs(a[i].a - a[j].a)][1] + a[i].b);
        }
        if (o > abs(a[i].a - a[j].a)) {
          f[i][j][o][1] = max(f[i][j][o][1], f[i][j - 1][o - abs(a[i].a - a[j].a)][0] + a[j].b);
        }
        if (o > abs(a[j].a - a[j - 1].a)) {
          f[i][j][o][1] = max(f[i][j][o][1], f[i][j - 1][o - abs(a[j - 1].a - a[j].a)][1] + a[i].b);
        }
        r = max({r, f[i][j][o][0], f[i][j][o][1]});
      }
    }
  }
  cout << r;
  return 0;
}
/*
f[i][j]
*/