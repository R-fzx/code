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

const int kN = 2e5 + 1;

int t, n, v[kN];
vector<int> e[kN];

bool D(int x, int c) {
  if (v[x]) {
    return v[x] == c;
  }
  v[x] = c;
  for (int i : e[x]) {
    if (!D(i, c ^ 1)) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--; ) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      e[i].clear(), v[i] = 0;
    }
    for (int i = 1, x, y; i <= n; ++i) {
      cin >> x >> y;
      e[x].push_back(y), e[y].push_back(x);
    }
    bool f = 1;
    for (int i = 1; i <= n; ++i) {
      if (e[i].size() > 2 || !v[i] && !D(i, 2)) {
        f = 0;
        break;
      }
    }
    cout << (f ? "YES" : "NO") << '\n';
  }
  return 0;
}