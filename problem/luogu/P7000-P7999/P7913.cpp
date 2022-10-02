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
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1;

int n, m[2], s[2][kN];
Pii a[2][kN];
template <typename T>
using Q = priority_queue<T, vector<T>, greater<T>>;
Q<int> q;
Q<Pii> p;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m[0] >> m[1];
  for (int k = 0; k < 2; ++k) {
    for (int i = 1; i <= m[k]; ++i) {
      cin >> a[k][i].first >> a[k][i].second;
    }
    sort(a[k] + 1, a[k] + m[k] + 1), q = Q<int>(), p = Q<Pii>();
    for (int i = 1; i <= n; ++i) {
      q.push(i);
    }
    for (int i = 1; i <= m[k]; ++i) {
      for (; !p.empty() && p.top().first <= a[k][i].first; q.push(p.top().second), p.pop()) {
      }
      if (!q.empty()) {
        int x = q.top();
        q.pop(), p.emplace(a[k][i].second, x), ++s[k][x];
      }
    }
    for (int i = 1; i <= n; ++i) {
      s[k][i] += s[k][i - 1];
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans = max(ans, s[0][i] + s[1][n - i]);
  }
  cout << ans;
  return 0;
}
/*
1 4
2 6
5 7
  1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18
1 1               5
1         3                   8
1                     6               10
1                                 9                   14
1                                                 13                  18
2     2                                   11
2             4                                           15
2                         7                                       17
2                                             12              16
  1,0 1,1 2,1 2,2 1,2 2,2 2,3 1,3 2,3 1,3 1,2 1,3 2,3 1,3 1,2 1,1 1,0 0,0
*/