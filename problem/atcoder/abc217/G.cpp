#include <iostream>

using namespace std;
using LL = long long;

const int kN = 5002;
const LL kM = 998244353;

int n, m;
LL f[kN][kN], g[kN], ig[kN];

LL P(LL b, LL e) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) {
    if (e & 1) {
      s = s * b % kM;
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  f[0][0] = g[0] = ig[0] = 1;
  for (int i = 1; i <= n; ++i) {
    ig[i] = P(g[i] = g[i - 1] * i % kM, kM - 2);
  }
  for (int i = 1; i <= m; ++i) {
    int x = n / m + (i <= n % m);
    for (int j = x; j <= n; ++j) {
      for (int k = 0; k <= x; ++k) {
        f[i][j] = (f[i][j] + f[i - 1][j - k] * g[x] % kM * ig[x - k] % kM * ig[k] % kM * g[j - k] % kM * ig[j - x] % kM) % kM;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << f[m][i] << endl;
  }
  return 0;
}