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
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 201;

struct E {
  int x, y;
  LL w;
  E() {}
  E(int x, int y, LL w) : x(x), y(y), w(w) {}
  bool operator<(const E &o) const { return w > o.w; }
};
vector<E> l;
int n, c[kN];
Pii a[kN];
LL ans;

int main() {
  RF("seventeen");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  for (int k = 0; k < 2; ++k) {
    l.clear();
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        l.emplace_back(i, j, (k ? a[i].second : a[i].first) * (k ? a[j].second : a[j].first));
      }
      c[i] = -1;
    }
    sort(l.begin(), l.end());
    for (E i : l) {
      if (!~c[i.x] && !~c[i.y]) {
        c[i.x] = 0, c[i.y] = 1;
      } else if (!~c[i.y]) {
        c[i.y] = c[i.x] ^ 1;
      } else if (!~c[i.x]) {
        c[i.x] = c[i.y] ^ 1;
      }
      ans += (c[i.x] == c[i.y] ? 1 : -1) * i.w;
    }
    // cout << ans << '\n';
  }
  cout << ans << ".00";
  return 0;
}