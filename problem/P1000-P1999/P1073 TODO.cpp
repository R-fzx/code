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

const int kN = 1e5 + 1;

int n, m, a[kN], d[kN], ans;
vector<int> e[2][kN];
bool v[2][kN];

void D(int x, int o) {
  if (v[o][x]) {
    return;
  }
  v[o][x] = 1;
  for (int i : e[o][x]) {
    D(i, o);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    d[i] = i;
  }
  sort(d + 1, d + n + 1, [](int i, int j) { return a[i] < a[j]; });
  for (int i = 1, x, y, h; i <= m; ++i) {
    cin >> x >> y >> h;
    e[0][x].push_back(y), e[1][y].push_back(x);
    if (h == 2) {
      e[0][y].push_back(x), e[1][x].push_back(y);
    }
  }
  D(1, 0), D(n, 1);
  for (int i = 1; i <= n; ++i) {
    if (v[0][d[i]]) {
      D(d[i], 0);
      int j = n;
      for (; j >= 1 && !(v[0][d[j]] && v[1][d[j]]); --j) {
      }
      ans = max(ans, a[d[j]] - a[d[i]]);
      break;
    }
  }
  for (int i = n; i >= 1; --i) {
    if (v[1][d[i]]) {
      D(d[i], 1);
      int j = 1;
      for (; j <= n && !(v[0][d[j]] && v[1][d[j]]); ++j) {
      }
      ans = max(ans, a[d[i]] - a[d[j]]);
      break;
    }
  }
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}