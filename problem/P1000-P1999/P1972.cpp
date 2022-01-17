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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 1e6 + 1;

int n, m, a[kN], s[kN], p[kN], d[kN], ans[kN];
Pll q[kN];

void Add(int x, int v) {
  for (; x <= n; s[x] += v, x += x & -x) {
  }
}
int Sum(int x) {
  int _s = 0;
  for (; x; _s += s[x], x -= x & -x) {
  }
  return _s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> q[i].first >> q[i].second, d[i] = i;
  }
  sort(d + 1, d + m + 1, [](int x, int y) { return q[x].second < q[y].second; });
  for (int i = 1, j = 1; i <= m; ++i) {
    for (; j <= q[d[i]].second; ++j) {
      p[a[j]] && (Add(p[a[j]], -1), 0), Add(j, 1), p[a[j]] = j;
    }
    ans[d[i]] = Sum(q[d[i]].second) - Sum(q[d[i]].first - 1);
  }
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}