# include <bits/stdc++.h>
# define N 222

using namespace std;

double f[N][N][N+N], p[N];
int n, L, k;

int main() {
  freopen("guard.in", "r", stdin);
  freopen("guard.out", "w", stdout);
  scanf("%d%d%d", &n, &L, &k);
  if (k > n) {
    k = n;
  }
  f[0][0][n + k] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%lf", p + i);
    p[i] /= 100;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < i; j++) {
      for (int k = 0; k <= n + n; k++) {
        if (k + x >= 0) {
          f[i][j + 1][min(n + n, k + x)] += p[i] * f[i - 1][j][k];
          f[i][j][k] += (1 - p[i]) * f[i - 1][j][k];
        }
      }
    }
  }
  double ans;
  for (int i = L; i <= n; i++) {
    for (int k = n; k <= n + n; k++) {
      ans += f[n][i][k];
    }
  }
  printf("%.6f", ans);
}