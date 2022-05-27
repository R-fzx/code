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

const int kN = 51;

int n, m, k;
mL w[kN], f[kN][kN][kN], p[kN][kN], fc[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  fc[0] = 1;
  for (int i = 1; i <= k; ++i) {
    fc[i] = fc[i - 1] * i;
  }
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    w[0] += x, w[i] = x;
  }
  for (int i = 1; i <= n; ++i) {
    w[i] /= w[0], p[i][0] = 1;
    for (int j = 1; j <= k; ++j) {
      p[i][j] = p[i][j - 1] * w[i];
    }
  }
  f[0][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= ::k; ++j) {
      for (int k = 0; k <= m; ++k) {
        f[i][j][k] = f[i - 1][j][k];
        for (int x = 1; x <= j; ++x) {
          f[i][j][k] += f[i - 1][j - x][k - 1] * p[i][x] / fc[x];
        }
      }
    }
  }
  cout << (f[n][k][m] * fc[k]).val();
  return 0;
}