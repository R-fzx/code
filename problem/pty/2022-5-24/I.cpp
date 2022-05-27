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

const int kN = 2001;

int n, m, k, s, t, x;
vector<int> e[kN];
mL f[kN][kN][2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> s >> t >> x;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  f[s][0][0] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k : e[j]) {
        f[j][i][0] += f[k][i - 1][j == x], f[j][i][1] += f[k][i - 1][j != x];
      }
    }
  }
  cout << f[t][k][0].val();
  return 0;
}