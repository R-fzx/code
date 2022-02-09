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
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1001;

int n, m, v[kN], t, p[kN], _[kN * kN];
LL d[kN], s[kN];
vector<Pii> e[kN];

bool F(int x) {
  if (v[x] ^ t) {
    v[x] = t;
    for (Pii &i : e[x]) {
      if (s[x] + s[i.first] == i.second) {
        if (!p[i.first] || F(p[i.first])) {
          return p[i.first] = x, p[x] = i.first;
        }
      } else {
        d[i.first] = min(d[i.first], s[x] + s[i.first] - i.second);
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  iota(_, _ + kN * kN, 0), cin >> n >> m;
  for_each_n(_ + 1, m, [](int i) {
    int x, y, h;
    cin >> x >> y >> h, e[x].push_back({y + n, h}), e[y + n].push_back({x, h});
  }), for_each_n(_ + 1, n, [](int i) { s[i] = max_element(e[i].begin(), e[i].end(), [](Pii x, Pii y) { return x.second < y.second; })->second; }), for_each_n(_ + 1, n, [](int i) {
    for (++t;; ++t) {
      fill_n(d + n + 1, n, 1 << 30);
      if (F(i)) {
        break;
      }
      LL x = *min_element(d + n + 1, d + n + n + 1);
      for_each_n(_ + 1, n, [x](int j) { s[j] -= (v[j] == t) * x, s[j + n] += (v[j + n] == t) * x; });
    }
  });
  cout << accumulate(s + 1, s + n + n + 1, 0) << endl;
  for_each_n(_ + 1, n, [](int i) { cout << p[i + n] << ' '; });
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}