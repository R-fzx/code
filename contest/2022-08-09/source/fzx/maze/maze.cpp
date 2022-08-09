#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kN = 21, kV = 1e4 + 1;

int n, m, x, a[kN][kN];
LL f[kN][kN][kV];

int main() {
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
  RF("maze");
  cin >> n >> m >> x;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  f[0][1][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) {
        for (int k = 0; k < kV; ++k) {
          f[i][j][k ^ a[i][j]] = f[i - 1][j][k] + f[i][j - 1][k];
        }
      }
    }
  }
  cout << f[n][m][x];
  return 0;
}
/*
010110101
*/