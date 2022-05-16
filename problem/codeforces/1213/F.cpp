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

const int kN = 2e5 + 2;

int n, k, a[kN], b[kN], m, ans[kN];
Pii p[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[a[i]];
  }
  for (int i = 1; i <= n; ++i) {
    debug("%d ", b[i]);
  }
  debug("\n");
  for (int i = 1; i < n; ++i) {
    if (b[i] > b[i + 1]) {
      p[++m] = {b[i + 1], b[i]};
    }
  }
  sort(p + 1, p + m + 1);
  int c = -1, _k = 0, kc = 0;
  p[m + 1] = {n + 1, n + 1};
  for (int i = 1, r = 0, l = 0; i <= m + 1; ++i) {
    if (p[i].first <= r) {
      r = max(r, p[i].second);
    } else {
      p[++c] = {l, r}, _k += 1, kc += r - l + 1, l = p[i].first, r = p[i].second;
    }
  }
  for (int i = 1; i <= c; ++i) {
    debug("%d %d\n", p[i].first, p[i].second);
  }
  _k += n - kc;
  if (_k >= k) {
    cout << "YES\n";
    for (int i = 1, j = 1, c = -1; i <= n; ++i) {
      if (i == p[j].first) {
        ++c;
        for (; i <= p[j].second; ++i) {
          ans[a[i]] = min(k, c);
        }
        ++j, --i;
      } else {
        ans[a[i]] = min(k, ++c);
      }
    }
    for (int i = 1; i <= n; ++i) {
      cout << char(ans[i] + 'a');
    }
  } else {
    cout << "NO";
  }
  return 0;
}