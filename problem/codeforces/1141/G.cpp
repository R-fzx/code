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

int n, k, mc, c[kN], d[kN];
vector<Pii> e[kN];

void D(int x, int f, int _c) {
  int p = 0;
  for (auto [i, d] : e[x]) {
    if (i ^ f) {
      D(i, x, c[d] = min(mc, p += ++p == _c));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  debug("1");
  cin >> n >> k;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].emplace_back(y, i), e[y].emplace_back(x, i);
  }
  iota(d + 1, d + n + 1, 1);
  sort(d + 1, d + n + 1, [&](int x, int y) { return e[x].size() > e[y].size(); });
  mc = e[d[k + 1]].size(), D(1, 0, 0);
  cout << mc << '\n';
  for (int i = 1; i < n; ++i) {
    cout << c[i] << ' ';
  }
  return 0;
}