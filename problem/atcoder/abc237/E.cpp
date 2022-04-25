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
#include <queue>
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

int n, m;
LL a[kN], d[kN];
vector<Pll> e[kN];
priority_queue<Pll, vector<Pll>, greater<Pll>> q;

void R(int x, LL _d) {
  if (d[x] > _d) {
    d[x] = _d, q.push({_d, x});
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].emplace_back(y, max(0LL, a[y] - a[x])), e[y].emplace_back(x, max(0LL, a[x] - a[y]));
  }
  for (int i = 1; i <= n; ++i) {
    d[i] = 1e18;
  }
  for (R(1, 0); !q.empty(); ) {
    int x = q.top().second;
    q.pop();
    for (auto [y, w] : e[x]) {
      R(y, d[x] + w);
    }
  }
  LL ans = -1e18;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, -d[i] + a[1] - a[i]);
  }
  cout << ans;
  return 0;
}