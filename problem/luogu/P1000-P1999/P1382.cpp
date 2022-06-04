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

const int kN = 1e5 + 1;

struct E {
  int x, h, d;
  bool operator<(const E &o) const {
    return x < o.x || (x == o.x && (d < o.d || (d == o.d && (d ? h < o.h : h > o.h))));
  }
} e[kN << 1];
int n;
multiset<int> s;
vector<Pii> l;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, l, r, h; i <= n; ++i) {
    cin >> h >> l >> r;
    e[i] = {l, h, 0}, e[i + n] = {r, h, 1};
  }
  sort(e + 1, e + n + n + 1);
  // for (int i = 1; i <= n + n; ++i) {
  //   cout << e[i].x << " " << e[i].h << " " << e[i].d << endl;
  // }
  s.insert(0);
  for (int i = 1, j = 0; i <= n + n; ++i) {
    int x = -*s.begin();
    if (e[i].d) {
      if (e[i].h == x) {
        int y = -*++s.begin();
        if (x ^ y) {
          l.emplace_back(e[i].x, x), l.emplace_back(e[i].x, y);
        }
        s.erase(s.begin());
      } else {
        s.erase(s.find(-e[i].h));
      }
    } else {
      if (e[i].h > x) {
        l.emplace_back(e[i].x, x), l.emplace_back(e[i].x, e[i].h);
      }
      s.insert(-e[i].h);
    }
  }
  cout << l.size() << endl;
  for (Pii &i : l) {
    cout << i.first << " " << i.second << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}