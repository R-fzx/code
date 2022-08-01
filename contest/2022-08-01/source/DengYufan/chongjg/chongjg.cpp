#include <iostream>
#define LL long long

using namespace std;

int n, m, a[101][101];

int main() {
  freopen("chongjg.in", "r", stdin);
  freopen("chongjg.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!a[i][j]) {
        int s = min(n - i + 1, m - j + 1), t = a[i - 1][j] == 1 || a[i][j - 1] == 1 ? (a[i - 1][j] == 2 || a[i][j - 1] == 2) + 2 : 1;
        for (int k = i; k < i + s; k++) {
          for (int l = j; l < j + s; l++) {
            a[k][l] = t;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << char(a[i][j] + 64);
    }
    cout << '\n';
  }
  return 0;
}
