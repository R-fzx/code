#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using mL = modint998244353;

const int kN = 2e5 + 1;

int n, s, ans;
Pii a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    s += a[i].second = c - '0';
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1, _s = 0; i <= n; ) {
    debug("%d %d %d %d\n", i, a[i].first, a[i].second, _s);
    ans = max(ans, _s + s - (i - 1 - _s));
    for (int j = i; i <= n && a[i].first == a[j].first; ++i) {
      _s += !a[i].second;
    }
  }
  cout << max(ans, n - s);
  return 0;
}
/*
00111
*/