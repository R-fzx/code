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

const int kN = 50001, kL = 16;

int n, m, b[kN << 1], p[kL][kN];
bool v[kL][kN];
Pii a[kN], q[kN];

int C(int x, int y) {
  if (p[0][x] > p[0][y]) {
    return 0;
  }
  
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
    b[i] = a[i].first;
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> q[i].first >> q[i].second;
    b[i + n] = q[i].first, b[i + n + m] = q[i].second;
  }
  sort(b + 1, b + n + m + m + 1);
  int _ = unique(b + 1, b + n + m + m + 1) - b;
  for (int i = 1; i <= n; ++i) {
    a[i].first = lower_bound(b + 1, b + _, a[i].first) - b;
  }
  for (int i = 1; i <= m; ++i) {
    q[i].first = lower_bound(b + 1, b + _, q[i].first) - b;
    q[i].second = lower_bound(b + 1, b + _, q[i].second) - b;
  }
  for (int i = 1; i <= n; ++i) {
    p[0][a[i].first] = a[i].second, v[0][a[i].first] = 1;
  }
  for (int i = 1; i < kL; ++i) {
    for (int j = 1; j <= n; ++j) {
      p[i][j] = max(p[i - 1][j], p[i - 1][j + (1 << i - 1)]);
      v[i][j] = v[i - 1][j] && v[i - 1][j + (1 << i - 1)];
    }
  }
  for (int i = 1; i <= m; ++i) {
    int x = C(q[i].first, q[i].second);
    cout << (x == 2 ? "maybe" : (x ? "yes" : "no")) << '\n';
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}