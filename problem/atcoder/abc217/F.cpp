#include <iostream>

using namespace std;
using LL = long long;

const int kN = 401;
const LL kM = 998244353;

int n, m;
bool v[kN][kN];
LL f[kN][kN], c[kN][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  n <<= 1;
  c[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= n; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % kM;
    }
  }
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    v[x][y] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    f[i][i - 1] = 1;
  }
  for (int l = 2; l <= n; l += 2) {
    for (int i = 1, j; (j = i + l - 1) <= n; ++i) {
      for (int k = j - 2; k >= i - 1; k -= 2) {
        f[i][j] = (f[i][j] + f[i][k] * v[k + 1][j] * f[k + 2][j - 1] % kM * c[l / 2][(k - i + 1) / 2] % kM) % kM;
      }
    }
  }
  cout << f[1][n];
  return 0;
}