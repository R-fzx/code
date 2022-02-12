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
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 261;

int n, m, nl, p[kN], v[kN], t, ans;
vector<int> e[kN];

int Encode(int o, int x, int v) { return o * nl + (x - 1) * 13 + v + 1; }
bool F(int x) {
  if (v[x] ^ t) {
    v[x] = t;
    for (int i : e[x]) {
      if (!p[i] || F(p[i])) {
        return p[i] = x;
      }
    }
  }
  return 0;
}

int main() {
  // freopen("zzx.in", "r", stdin);
  // freopen("zzx.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  nl = 13 * n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, x; j <= m; ++j) {
      cin >> x;
      for (int k = 0; x + k <= 12; ++k) {
        if (x + k % 3 == 0) {
          for (int u = 0; u <= k; ++u) {
            e[Encode(0, i, u)].push_back(Encode(1, j, k - u));
          }
        }
      }
    }
  }
  for (int i = 1; i <= nl; ++i) {
    ++t, ans += F(i);
  }
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}