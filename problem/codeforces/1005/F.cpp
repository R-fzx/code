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

const int kN = 2e5 + 1;
using S = string;

int n, m, k, d[kN], q[kN], h = 1, t;
vector<Pll> e[kN];
Vl p[kN];
vector<S> v;
S s;

void R(int x, int _d) {
  if (d[x] > _d) {
    d[x] = _d, q[++t] = x;
  }
}
void D(int x) {
  if (v.size() >= k) {
    return;
  }
  if (x > n) {
    v.push_back(s);
    return;
  }
  for (int i : p[x]) {
    s[i - 1] = '1', D(x + 1), s[i - 1] = '0';
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back({i, y}), e[y].push_back({i, x});
  }
  fill(d + 1, d + n + 1, 1 << 30);
  for (R(1, 0); h <= t; ++h) {
    int x = q[h];
    for (auto i : e[x]) {
      R(i.second, d[x] + 1);
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (auto j : e[i]) {
      if (d[j.second] + 1 == d[i]) {
        p[i].push_back(j.first);
      }
    }
  }
  s = string(m, '0'), D(2);
  cout << v.size() << endl;
  for (auto &&i : v) {
    cout << i << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}