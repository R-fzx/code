#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1;

int n, m, d[kN];
vector<int> e[kN], _l;
vector<pair<int, vector<int>>> l2;
vector<Pii> ans;
bool v[kN];
queue<int> l1;

void D(int x) {
  if (v[x]) {
    return;
  }
  _l.push_back(x), v[x] = 1;
  for (int i : e[x]) {
    D(i);
  }
}
bool S() {
  for (int i = 1; i <= n; ++i) {
    if (d[i] < 0) {
      return 0;
    }
  }
  if (m == n - 1) {
    return 1;
  }
  for (int i = 1; i <= n; ++i) {
    _l.clear(), D(i);
    int s = 0;
    for (int j : _l) {
      s += d[j];
    }
    if (!s && !_l.empty()) {
      return 0;
    } else if (s == 1) {
      int x = 0;
      for (int i : _l) {
        if (d[i]) {
          x = i;
          break;
        }
      }
      l1.push(x);
    } else if (s > 1) {
      l2.push_back({s, _l});
    }
  }
  while (!l1.empty() && !l2.empty()) {
    int i = l1.front();
    for (; !d[l2.back().second.back()]; l2.back().second.pop_back()) {
    }
    debug("%d %d\n", i, l2.back().second.back());
    l1.pop(), ans.emplace_back(i, l2.back().second.back());
    --d[l2.back().second.back()];
    if (--l2.back().first == 1) {
      for (; !d[l2.back().second.back()]; l2.back().second.pop_back()) {
      }
      l1.push(l2.back().second.back()), l2.pop_back();
    }
  }
  if (l1.size() == 2 && l2.empty()) {
    int i = l1.front();
    l1.pop(), ans.emplace_back(i, l1.front());
    return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
  }
  if (accumulate(d + 1, d + n + 1, 0) != (n - 1) * 2) {
    cout << -1;
    return 0;
  }
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
    --d[x], --d[y];
  }
  if (S()) {
    for (auto [i, j] : ans) {
      cout << i << " " << j << endl;
    }
  } else {
    cout << -1;
  }
  return 0;
}