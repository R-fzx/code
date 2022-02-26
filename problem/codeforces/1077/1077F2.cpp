#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 5001;
const LL kI = 1e18;

int n, k, m, a[kN], h, t, q[kN];
LL f[kN], g[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  fill(f + 1, f + n + 1, -kI);
  fill(g + 1, g + n + 1, -kI);
  for (int i = 1; i <= m; ++i) {
    h = 1, t = 0;
    for (int j = 1; j <= n; ++j) {
      for (; h <= t && q[h] + k < j; ++h) {
      }
      for (; h <= t && g[j - 1] >= g[q[t]]; --t) {
      }
      q[++t] = j - 1, f[j] = g[q[h]] + a[j];
    }
    copy(f + 1, f + n + 1, g + 1);
  }
  LL ans = *max_element(f + n - k + 1, f + n + 1);
  cout << (ans < 0 ? -1 : ans);
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}