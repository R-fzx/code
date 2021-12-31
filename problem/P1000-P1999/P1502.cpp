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

const int kN = 10001;

struct E {
  LL x, y, v;
  bool operator<(const E &o) const {
    return x < o.x;
  }
} e[kN];
int t, n, w, h;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> w >> h;
    for (int i = 1; i <= n; ++i) {
      cin >> e[i].x >> e[i].y >> e[i].v;
      e[i].x += w - 1, e[i].y += h - 1;
    }
    sort(e + 1, e + n + 1);
    for (int i = 1; i <= n; ++i) {
      
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}