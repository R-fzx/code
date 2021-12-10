#include <iostream>

using namespace std;
using LL = long long;

const int kN = 2e5 + 1;
const LL kInf = 1LL << 60;

int n;
LL a[kN], b[kN], f[kN][2][2], ans = kInf;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  fill(&f[0][0][0], &f[n][1][1] + 1, kInf);
  f[1][0][0] = a[1], f[1][1][1] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        for (int _j = 0; _j < 2; ++_j) {
          f[i][j][k] = min(f[i][j][k], f[i - 1][_j][k] + (j ? 0 : a[i]) + (j == _j ? b[i - 1] : 0));
        }
      }
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      ans = min(ans, f[n][i][j] + (i == j ? b[n] : 0));
    }
  }
  cout << ans;
  return 0;
}