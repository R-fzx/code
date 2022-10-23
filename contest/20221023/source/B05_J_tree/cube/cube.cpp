#include <iostream>

using namespace std;

const int N = 105, k = 50;

long long ans;
int vis[N][N][N];
int n, x[2], y[2], z[2];

int main () {
  freopen ("cube.in", "r", stdin);
  freopen ("cube.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[0] >> y[0] >> z[0] >> x[1] >> y[1] >> z[1];
    for (int a = x[0]; a <= x[1]; a++) {
      for (int b = y[0]; b <= y[1]; b++) {
        for (int c = z[0]; c <= z[1]; c++) {
          vis[a + k][b + k][c + k]++;
        }
      }
    }
  }
  for (int i = 0; i <= 2 * k; i++) {
    for (int j = 0; j <= 2 * k; j++) {
      for (int w = 0; w <= 2 * k; w++) {
        ans += vis[i][j][w] >= n - 1;
      }
    }
  }
  cout << ans;
  return 0;
}