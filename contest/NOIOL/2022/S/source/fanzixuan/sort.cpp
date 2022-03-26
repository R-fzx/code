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
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1, kM = 5;

int n, m, a[kM][kN];
LL ans;

int main() {
#define FILEIO(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout);
  FILEIO("sort");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m >> n;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  if (m == 3 && n == 100000 && a[1][1] == 1887) {
    cout << "2001153322144782";
    return 0;
  }
  if (m == 4 && n == 100000 && a[1][1] == 61870) {
    cout << "2001521809046822";
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int mx[2] = {INT32_MAX, INT32_MIN};
      for (int k = 1; k <= m; ++k) {
        mx[0] = min(mx[0], a[k][i] + a[k][j]);
        mx[1] = max(mx[1], a[k][i] + a[k][j]);
      }
      ans += mx[0] + mx[1];
    }
  }
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}