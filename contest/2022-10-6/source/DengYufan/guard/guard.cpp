#include <algorithm>
#include <iomanip>
#include <iostream>
#define LL long long

using namespace std;

LL n, m, l, x, y;
double ans, f[201][201] = {1.0}, g[201][201][202] = {1.0};  // f:前i场 赢j场 g:前i场 赢j场 拿k容量的包
pair<LL, double> a[201];

int main() {
  freopen("guard.in", "r", stdin);
  freopen("guard.out", "w", stdout);
  cin >> n >> m >> l;
  for (LL i = 1; i <= n; i++) {
    cin >> a[i].second;
    a[i].second /= 100.0;
  }
  for (LL i = 1; i <= n; i++) {
    cin >> a[i].first;
    ~a[i].first ? y++ : x++;
  }
  sort(a + 1, a + n + 1);
  for (LL i = 1; i <= x; i++) {
    for (LL j = 0; j <= i; j++) {
      f[i][j] += f[i - 1][j] * (1.0 - a[i].second);
      if (j) {
        f[i][j] += f[i - 1][j - 1] * a[i].second;
      }
    }
  }
  for (LL i = 0; i < y; i++) {
    for (LL j = 0; j <= i; j++) {
      for (LL k = 0; k <= 201; k++) {
        g[i + 1][j][k] += g[i][j][k] * (1.0 - a[i + 1 + x].second);
        g[i + 1][j + 1][min(k + a[i + 1 + x].first, 201LL)] += g[i][j][k] * a[i + 1 + x].second;
      }
    }
  }
  for (LL i = 0; i <= x; i++) {
    for (LL j = max(m - i, 0LL); j <= y; j++) {
      for (LL k = max(i - l, 0LL); k <= 201; k++) {
        ans += f[x][i] * g[y][j][k];
      }
    }
  }
  cout << fixed << setprecision(6) << ans;
  return 0;
}
