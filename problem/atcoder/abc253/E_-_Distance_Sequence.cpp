#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using mL = modint998244353;

const int kN = 1001, kM = 5001;

int n, m, k;
mL f[kN][kM], s[kN][kM];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    f[1][i] = 1, s[1][i] = i;
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (k) {
        // for (int k = 1; k <= j - ::k; ++k) {
        //   f[i][j] += f[i - 1][k];
        // }
        if (j - k >= 1) {
          f[i][j] += s[i - 1][max(1, j - k)];
        }
        if (j + k <= m) {
          f[i][j] += s[i - 1][m] - s[i - 1][j + k - 1];
        }
        // for (int k = m; k >= j + ::k; --k) {
        //   f[i][j] += f[i - 1][k];
        // }
      } else {
        f[i][j] = s[i - 1][m];
        // for (int k = 1; k <= m; ++k) {
        //   f[i][j] += f[i - 1][k];
        // }
      }
      s[i][j] = s[i][j - 1] + f[i][j];
    }
  }
  cout << s[n][m].val();
  return 0;
}