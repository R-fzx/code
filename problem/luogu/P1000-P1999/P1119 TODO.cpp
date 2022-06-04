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

const int kN = 201;

int n, m, q, t[kN];
vector<Pii> e[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }
  for (int i = 1, x, y, h; i <= m; ++i) {
    cin >> x >> y >> h;
    e[x].emplace_back(y, h), e[y].emplace_back(x, h);
  }
  cin >> q;
  while (q--) {
    int x, y, _t;
    cin >> x >> y >> _t;
    
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}