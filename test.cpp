#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1;

int n, m, s;
vector<Pll> e[kN];
LL ans;
using A = pair<Pll, int>;
priority_queue<A, vector<A>, greater<A>> q;
Pll d[kN];

void R(int x, Pll _d) {
  if (_d < d[x]) {
    d[x] = _d, q.emplace(_d, x);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1, x, y, w; i <= m; ++i) {
    cin >> x >> y >> w;
    e[x].emplace_back(y, w), e[y].emplace_back(x, w);
  }
  fill_n(d + 1, n, Pll{1e18, 1e18});
  cin >> s;
  for (R(s, {0, 0}); !q.empty();) {
    A x = q.top();
    q.pop();
    for (Pll &i : e[x.second]) {
      R(i.first, {d[x.second].first + i.second, i.second});
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans += d[i].second;
  }
  cout << n - 1 << ' ' << ans;
  return 0;
}