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
using LD = long double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 2e5 + 1;

struct E {
  LL d = 1LL << 60;
  vector<Pll> n;
} e[kN << 1];
int n, m, a[kN << 1], d[kN << 1];
priority_queue<Pll, vector<Pll>, greater<Pll>> q;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = (m - a[i]) % m, d[i] = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i + n];
    e[i + n].n.push_back({i, 0}), d[i + n] = i + n;
  }
  n <<= 1;
  stable_sort(d + 1, d + n + 1, [](int i, int j) { return a[i] < a[j]; });
  for (int i = 1; i <= n; ++i) {
    e[d[i]].n.push_back({d[i % n + 1], (a[d[i % n + 1]] - a[d[i]] + m) % m});
  }
  for (q.push({0, 1}); !q.empty(); ) {
    Pll x = q.top();
    q.pop();
    if (x.first < e[x.second].d) {
      e[x.second].d = x.first;
      for (Pll i : e[x.second].n) {
        q.push({x.first + i.second, i.first});
      }
    }
  }
  cout << e[n].d;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}