#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;

long double dp[2][MAXN * 2][MAXN];
int p[MAXN], a[MAXN];

int main () {
  freopen("guard.in", "r", stdin);
  freopen("guard.out", "w", stdout);
  int n, l, k;
  cin >> n >> l >> k;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  dp[0][min(k, n) + 200][0] = 1.0l * (100 - p[0]) / 100;
  dp[0][min(k + a[0], n) + 200][1] = 1.0l * p[0] / 100;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= 200 + n; ++j) { //容量
      for (int kl = 0; kl <= i; ++kl) {
        if (dp[(i + 1) % 2][j][kl] > 0) {
          dp[i % 2][j][kl] += dp[(i + 1) % 2][j][kl] * (100 - p[i]) / 100;
          dp[i % 2][min(j + a[i], 200 + n)][kl + 1] += dp[(i + 1) % 2][j][kl] * p[i] / 100;
        }
      }
    }
  }
  long double ans = 0;
  for (int i = 200; i <= n + 200; ++i) {
    for (int j = l; j <= n; ++j) {
      ans += dp[(n + 1) % 2][i][j];
    }
  }
  double anss = ans;
  printf("%.6lf", anss);
  return 0;
}