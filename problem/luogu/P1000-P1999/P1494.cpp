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
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 5e4 + 1, kB = 200;

struct Q {
  int l, r, i;

  bool operator<(const Q &o) const { return l / kB == o.l / kB ? r < o.r : l < o.l; }
} q[kN];
int n, m, a[kN], c[kN];
LL s;
Pll ans[kN];

LL G(LL a, LL b) { return b ? G(b, a % b) : a; }
void A(int x) { s += c[a[x]]++; }
void D(int x) { s -= --c[a[x]]; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> q[i].l >> q[i].r, q[i].i = i;
  }
  sort(q + 1, q + m + 1);
  for (int i = 1, l = 1, r = 0; i <= m; ++i) {
    for (; q[i].l < l; A(--l)) {
    }
    for (; q[i].r > r; A(++r)) {
    }
    for (; q[i].l > l; D(l++)) {
    }
    for (; q[i].r < r; D(r--)) {
    }
    ans[q[i].i] = (q[i].l == q[i].r ? Pll{0, 1} : Pll{s, 1LL * (r - l + 1) * (r - l) / 2});
  }
  for (int i = 1; i <= m; ++i) {
    LL g = G(ans[i].first, ans[i].second);
    cout << ans[i].first / g << '/' << ans[i].second / g << '\n';
  }
  return 0;
}