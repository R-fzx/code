#include <iostream>

using namespace std;

const int N = 1e3 + 5;

int n, m;
char a[N][N];

int main() {
  freopen("chongjg.in", "r", stdin);
  freopen("chongjg.out", "w", stdout);
  cin >> n >> m;
  int l = min(n, m);
  for (int k = 1; k <= n - l + 1; k += l + 1) {
    for (int x = 1; x <= m - l + 1; x += l + 1) {
      for (int i = k; i <= min(k + l - 1, n); ++i) {
        for (int j = x; j <= min(x + l - 1, m); ++j) {
          a[i][j] = 'A';
        }
      }
    }
  }
  
  int f = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 'A') {
        cout << a[i][j];
      } else {
        if (f % 2) {
          cout << 'B';
        } else {
          cout << 'C';
        }
        ++f;
      }
    }
    cout << '\n';
  }
}
