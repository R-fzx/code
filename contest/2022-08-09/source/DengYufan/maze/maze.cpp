#include <iostream>
#define LL long long

using namespace std;

LL n, m, k, a[21][21], f[21][21][16384];

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  cin >> n >> m >> k;
  for (LL i = 1; i <= n; i++) {
    for (LL j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  f[1][1][a[1][1]] = 1;
  for (LL i = 1; i <= n; i++) {
    for (LL j = 1; j <= m; j++) {
      for (LL k = 0; k <= 16383; k++) {
        i < n && (f[i + 1][j][k ^ a[i + 1][j]] += f[i][j][k]);
        j < m && (f[i][j + 1][k ^ a[i][j + 1]] += f[i][j][k]);
      }
    }
  }
  cout << f[n][m][k];
  return 0;
}
