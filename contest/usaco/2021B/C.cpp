#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Pdd = pair<double, double>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 51;

int t, n, k;
char a[kN][kN];
LL f[kN][kN][5][2];  // 0 D 1 R

int main() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        cin >> a[i][j];
      }
    }
    fill(&f[0][0][0][0], &f[n][n][k][1] + 1, 0);
    f[1][1][0][0] = f[1][1][0][1] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if ((i != 1 || j != 1) && a[i][j] == '.') {
          for (int u = 0; u <= k; ++u) {
            f[i][j][u][0] = f[i - 1][j][u][0] + f[i][j - 1][(u + 4) % 5][1]/* + f[i][j][(u + 4) % 5][1]*/;
            f[i][j][u][1] = f[i - 1][j][(u + 4) % 5][0] + f[i][j - 1][u][1]/* + f[i][j][(u + 4) % 5][0]*/;
          }
        }
      }
    }
    LL ans = 0;
    for (int i = 0; i <= k; ++i) {
      ans += f[n][n][i][0] + f[n][n][i][1];
    }
    cout << ans << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
f[i][j][u][0] = f[i - 1][j][u][0] + f[i][j - 1][u][1] + f[i][j][u - 1][1];
f[i][j][u][1] = f[i - 1][j][u][0] + f[i][j - 1][u][1] + f[i][j][u - 1][0];
*/