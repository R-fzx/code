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

int n, m, b, w;
mL f[kN * kN], vf[kN * kN], ans, c[2][kN][kN];

mL C(int n, int m) { return n < m ? 0 : f[n] * vf[m] * vf[n - m]; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> b >> w;
  f[0] = 1;
  for (int i = 1; i <= n * m; ++i) {
    f[i] = f[i - 1] * i;
  }
  vf[n * m] = 1 / f[n * m];
  for (int i = n * m; i >= 1; --i) {
    vf[i - 1] = vf[i] * i;
  }
  for (int o = 0; o < 2; ++o) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        c[o][i][j] = C(i * j, o ? w : b);
        for (int _i = 1; _i <= i; ++_i) {
          for (int _j = 1; _j <= j; ++_j) {
            if (_i != i || _j != j) {
              c[o][i][j] -= C(i, _i) * C(j, _j) * c[o][_i][_j];
            }
          }
        }
      }
    }
  }
  for (int ib = 0; ib <= n; ++ib) {
    for (int jb = 0; jb <= m; ++jb) {
      for (int iw = 0; iw <= n; ++iw) {
        for (int jw = 0; jw <= m; ++jw) {
          ans += C(n, ib) * C(m, jb) * C(n - ib, iw) * C(m - jb, jw) * c[0][ib][jb] * c[1][iw][jw];
        }
      }
    }
  }
  cout << ans.val();
  return 0;
}