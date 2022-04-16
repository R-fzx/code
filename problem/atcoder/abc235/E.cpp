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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1;

struct E {
  int x, y, w, d;
  bool operator<(const E &o) const { return w < o.w; }
} e[kN << 1];
int n, m, q, f[kN], ans[kN];

int F(int x) { return x == f[x] ? x : (f[x] = F(f[x])); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  iota(f + 1, f + n + 1, 1);
  for (int i = 1; i <= m + q; ++i) {
    cin >> e[i].x >> e[i].y >> e[i].w;
    e[i].d = i;
  }
  sort(e + 1, e + m + q + 1);
  for (int i = 1; i <= m + q; ++i) {
    if (e[i].d > m) {
      ans[e[i].d - m] = F(e[i].x) != F(e[i].y);
    } else {
      f[F(e[i].x)] = F(e[i].y);
    }
  }
  for (int i = 1; i <= q; ++i) {
    cout << (ans[i] ? "Yes" : "No") << '\n';
  }
  return 0;
}