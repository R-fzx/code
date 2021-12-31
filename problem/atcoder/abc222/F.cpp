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

const int kN = 2e5 + 1;

int n;
vector<Pll> e[kN << 1];
LL d[2][kN << 1];

Pll D(int x, int f) {
  LL m = 0, v = 0;
  for (auto i : e[x]) {
    Pll p;
    if (i.first != f && (p = D(i.first, x)).second + i.second > v) {
      v = p.second + i.second, m = p.first;
    }
  }
  return {m ? m : x, v};
}
void F(int x, int f, int o) {
  for (auto i : e[x]) {
    if (i.first != f && i.first <= n) {
      d[o][i.first] = d[o][x] + i.second, F(i.first, x, o);
    }
  }
}

int main() {
  // freopen("F.in", "r", stdin);
  // freopen("F.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x, y, z; i < n; ++i) {
    cin >> x >> y >> z;
    e[x].emplace_back(y, z), e[y].emplace_back(x, z);
  }
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    e[i].emplace_back(i + n, x), e[i + n].emplace_back(i, x);
  }
  Pll s = D(1, 0), t = D(s.first, 0);
  // cout << s.first << " " << t.first << endl;
  F(s.first, 0, 0), F(t.first, 0, 1);
  for (int i = 1; i <= n; ++i) {
    // cout << d[0][i] << " " << d[1][i] << endl;
    cout << max(s.first == i + n ? 0 : d[0][i], t.first == i + n ? 0 : d[1][i]) << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}