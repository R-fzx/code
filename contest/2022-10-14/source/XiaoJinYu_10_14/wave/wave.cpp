#include <bits/stdc++.h>

using namespace std;

const int MAXN = 21;

unsigned long long f[MAXN][MAXN][2];

int main() {
  freopen("wave.in", "r", stdin);
  freopen("wave.out", "w", stdout);
  f[1][1][0] = f[1][1][1] = 1;
  for (int i = 2; i < 21; ++i) {
    for (int j = 1; j <= i; ++j) {
      for (int k = 1; k < j; ++k) {
        f[i][j][0] += f[i - 1][k][0];
      }
      for (int k = j; k < i; ++k) {
        f[i][j][0] += f[i - 1][k][1];
      }
    }
  }
  for (int i = 1; i < 21; ++i) {
    for (int j = 1; j < 21; ++j) {
      cout << f[i][j][0] << '|' << f[i][j][1] << ' ';
    }
    cout << '\n';
  }
  // int t, n;
  // unsigned long long c;
  // cin >> t;
  // while (t--) {
  //   cin >> n >> c;
  //   for (int i = n; i > 0; --i) {
  //     for (int j = 1; j <= n; ++j) {
  //       if (f[i][])
  //     }
  //   }
  // }
  return 0;
}