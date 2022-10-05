#include <iostream>
#define LL long long

using namespace std;

LL n, a, b, c, d, x, y, m, ans, s[3][3];
bool t[3][3][3][3];

int main() {
  freopen("crop.in", "r", stdin);
  freopen("crop.out", "w", stdout);
  cin >> n >> a >> b >> c >> d >> x >> y >> m;
  s[x % 3][y % 3]++;
  for (LL i = 1; i < n; i++) {
    x = (a * x + b) % m;
    y = (c * y + d) % m;
    s[x % 3][y % 3]++;
  }
  for (LL i = 0; i < 3; i++) {
    for (LL j = 0; j < 3; j++) {
      for (LL k = 0; k < 3; k++) {
        for (LL l = 0; l < 3; l++) {
          LL m = (3 - (i + k) % 3) % 3, n = (3 - (j + l) % 3) % 3;
          if (!t[i][j][k][l]) {
            t[i][j][k][l] = t[i][j][m][n] = t[k][l][i][j] = t[k][l][m][n] = t[m][n][i][j] = t[m][n][k][l] = 1;
            if (i == k && j == l && i == m && j == n) {  // 3 equals
              ans += max(s[i][j] * (s[k][l] - 1) * (s[m][n] - 2) / 6, 0LL);
            } else {  // 0 equals
              ans += s[i][j] * s[k][l] * s[m][n];
            }
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
