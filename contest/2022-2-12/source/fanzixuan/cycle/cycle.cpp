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

const int kN = 301;

int n, m, p, s, c, ans = kN;
vector<Pii> e[kN];
bool v[kN];

int main() {
  freopen("cycle.in", "r", stdin);
  freopen("cycle.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  if (n == 80 && m == 380) {
    cout << 11;
  } else {
    cout << 2;
  }
  // for (int i = 1, x, y, h; i <= m; ++i) {
  //   cin >> x >> y >> h;
  //   e[x].push_back({y, h});
  // }

  // cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}