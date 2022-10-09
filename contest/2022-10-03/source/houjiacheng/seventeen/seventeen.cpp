# include <bits/stdc++.h>
# define dis0 50000
// # define size 40000

using namespace std;

int f[100000][2], n, ansx, ansy;
int x[220], y[220];

int main() {
  freopen("seventeen.in", "r", stdin);
  freopen("seventeen.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", x + i, y + i);
  }
  int mx = 0;
  for (int i = 10000; i <= 90000; i++) {
    f[i][0] = f[i][1] = 2000000000;
  }f[dis0][1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = dis0 - mx; j <= dis0 + mx; j++) {
      f[j - x[i]][i&1^1] = min(f[j - x[i]][i&1^1], f[j][i&1] - (j - dis0) * x[i]);
      f[j + x[i]][i&1^1] = min(f[j + x[i]][i&1^1], f[j][i&1] + (j - dis0) * x[i]);
      ansx = min(ansx, min(f[j - x[i]][i&1^1], f[j + x[i]][i&1^1]));
    }
    mx += x[i];
  }
  mx = 0;
  for (int i = 10000; i <= 90000; i++) {
    f[i][0] = f[i][1] = 2000000000;
  }f[dis0][1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = dis0 - mx; j <= dis0 + mx; j++) {
      f[j - y[i]][i&1^1] = min(f[j - y[i]][i&1^1], f[j][i&1] - (j - dis0) * y[i]);
      f[j + y[i]][i&1^1] = min(f[j + y[i]][i&1^1], f[j][i&1] + (j - dis0) * y[i]);
      ansy = min(ansy, min(f[j - y[i]][i&1^1], f[j + y[i]][i&1^1]));
    }
    mx += y[i];
    // for (int j = dis0 - mx; j <= dis0 + mx; j++) {
    //   printf("%d ", f[j][1]);
    // }printf("\n");
  }
  printf("%lld.00", 1ll * ansx + ansy);
}


