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
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Pdd = pair<double, double>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 2e5 + 1;

int n, b[kN << 1], p[kN << 1];
Pll a[kN];
LL ans;

void Add(int x, int v = 1) {
  for (; x <= (n << 1); p[x] += v, x += x & -x) {
  }
}
int Sum(int x) {
  int s = 0;
  for (; x; s += p[x], x -= x & -x) {
  }
  return s;
}

int main() {
  // freopen("F.in", "r", stdin);
  // freopen("F.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first;
    b[i] = a[i].first;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].second;
    b[i + n] = a[i].second;
  }
  sort(b + 1, b + (n << 1) + 1);
  int m = unique(b + 1, b + (n << 1) + 1) - b;
  for (int i = 1; i <= n; ++i) {
    a[i] = {lower_bound(b + 1, b + m, a[i].first) - b, lower_bound(b + 1, b + m, a[i].second) - b};
  }
  sort(a + 1, a + n + 1, greater<Pll>());
  for (int i = 1, j = 1; i <= n; ) {
    for (; j <= n && a[i].first == a[j].first; Add(a[j++].second)) {
    }
    for (; i < j; ans += Sum(a[i++].second)) {
    }
  }
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}