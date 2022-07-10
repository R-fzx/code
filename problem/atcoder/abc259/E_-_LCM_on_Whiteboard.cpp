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
using mL = modint998244353;

const int kN = 2e5 + 1;

int n, ans, f[kN];
map<int, vector<Pii>> a;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, m; i <= n; ++i) {
    cin >> m;
    for (int j = 1, p, e; j <= m; ++j) {
      cin >> p >> e;
      a[p].push_back({i, e});
    }
  }
  for (auto i : a) {
    int m = 0, c = 0;
    for (auto j : i.second) {
      if (j.second > m) {
        m = j.second, c = 0;
      }
      if (j.second == m) {
        ++c;
      }
    }
    if (c == 1) {
      for (auto j : i.second) {
        if (j.second == m) {
          f[j.first] = 1;
        }
      }
    }
  }
  cout << count(f + 1, f + n + 1, 1) + !!count(f + 1, f + n + 1, 0);
  return 0;
}
/*
  2 3 5 7
1 0 0 0 2
2 2 0 1 0
3 0 0 1 0
4 1 0 0 1
*/