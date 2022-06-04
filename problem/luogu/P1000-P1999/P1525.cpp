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
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 20001;

int n, m, l, r, c[kN], _m;
vector<Pii> e[kN];

bool F(int x, int p) {
  if (c[x]) {
    return c[x] == p;
  }
  c[x] = p;
  for (auto i : e[x]) {
    if (i.second > _m && !F(i.first, p ^ 1)) {
      return 0;
    }
  }
  return 1;
}
bool C() {
  fill(c + 1, c + n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    if (!c[i] && !F(i, 2)) {
      return 0;
    }
  }
  return 1;
}

int main() {
  // freopen("P1525.in", "r", stdin);
  // freopen("P1525.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y, v; i <= m; ++i) {
    cin >> x >> y >> v;
    e[x].push_back({y, v}), e[y].push_back({x, v});
  }
  for (l = 0, r = 1e9; l < r; ) {
    _m = l + r >> 1;
    if (C()) {
      r = _m;
    } else {
      l = _m + 1;
    }
  }
  cout << l;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}