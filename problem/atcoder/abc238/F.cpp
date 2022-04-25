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

const int kN = 302;

int n, k, p[kN], a[kN];
mL f[kN][kN][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> p[a[i]];
  }
  for (int i = 1; i <= n; ++i) {
    debug("%d ", p[i]);
  }
  debug("\n");
  f[0][0][n + 1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= min(k, i); ++j) {
      for (int k = 1; k <= n + 1; ++k) {
        if (p[i] < k && j) {
          f[i][j][k] += f[i - 1][j - 1][k];  // 选
        }
        f[i][j][min(k, p[i])] += f[i - 1][j][k];  // 不选
      }
    }
  }
  mL ans = 0;
  for (int i = 1; i <= n + 1; ++i) {
    ans += f[n][k][i];
  }
  cout << ans.val();
  return 0;
}
/*
2 4 3 1
2 1 4 3

p: [3, 2, 4, 1]

1 2 3 4
3 2 4 1

f[i][j][k] 前 i 个数选 j 个的方案，其中没选的人中 p 的最小值为 k
选：f[i][j][k] = f[i - 1][j - 1][k]  (p[i] < k)
不选：f[i][j][min(k, p[i])] = f[i - 1][j][k];
*/