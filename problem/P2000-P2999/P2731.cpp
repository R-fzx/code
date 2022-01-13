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
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 501, kM = 1026;

int n, m, c[kN], t[kN];
Vl e[kN], ans;
map<Pll, int> l;

void D(int x) {
  while (t[x] < e[x].size()) {
    for (; t[x] < e[x].size() && !l[{x, e[x][t[x]]}]; ++t[x]) {
    }
    if (t[x] == e[x].size()) {
      break;
    }
    --l[{x, e[x][t[x]]}], --l[{e[x][t[x]], x}], D(e[x][t[x]]);
  }
  ans.push_back(x);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
    ++l[{x, y}], ++l[{y, x}], ++c[x], ++c[y], n = max({n, x, y});
  }
  for (int i = 1; i <= n; ++i) {
    sort(e[i].begin(), e[i].end());
  }
  int s = 1;
  for (int i = 1; i <= n; ++i) {
    if (c[i] & 1) {
      s = i;
      break;
    }
  }
  D(s);
  for (auto i = ans.rbegin(); i != ans.rend(); ++i) {
    cout << *i << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}