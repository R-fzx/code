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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 25001;

int n;
Pll a[kN];
LL x, y;

int main() {
  freopen("climb.in", "r", stdin);
  freopen("climb.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1, [](Pll x, Pll y) {
    if (x.first < x.second) {
      return y.first >= y.second || x.first < y.first;
    }
    return y.first >= y.second && x.second > y.second;
  });
  for (int i = 1; i <= n; ++i) {
    x += a[i].first, y = max(y, x) + a[i].second;
  }
  cout << y;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}