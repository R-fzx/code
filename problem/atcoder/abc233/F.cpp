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

const int kN = 1001;

int n, m, a[kN], d[kN], p[kN], _d[kN], f[kN];
vector<Pll> e[kN];
bool v = 1, b[kN];
Vl ans;

void D(int x, int f) {
  if (_d[x]) {
    return;
  }
  _d[x] = _d[f] + 1;
  for (auto i : e[x]) {
    D(i.first, x);
  }
}
bool S(int x, int s, int t) {
  if (x == t) {
    return 1;
  }
  if (f[x] == s || b[x]) {
    return 0;
  }
  f[x] = s;
  for (auto i : e[x]) {
    if (S(i.first, s, t)) {
      ans.push_back(i.second), swap(a[x], a[i.first]), swap(p[a[x]], p[a[i.first]]);
      return 1;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]] = d[i] = i;
  }
  cin >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back({y, i}), e[y].push_back({x, i});
  }
  for (int i = 1; i <= n; ++i) {
    D(i, 0);
  }
  stable_sort(d + 1, d + n + 1, [](int i, int j) { return _d[i] > _d[j]; });
  for (int i = 1; i <= n; ++i) {
    v &= S(d[i], d[i], p[d[i]]), b[d[i]] = 1;
  }
  if (v) {
    cout << ans.size() << endl;
    for (auto i : ans) {
      cout << i << " ";
    }
  } else {
    cout << -1;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
2 3 1
{3,2}
{1,3}
{2,1}
*/