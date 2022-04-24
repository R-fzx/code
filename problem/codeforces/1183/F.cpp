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

const int kN = 2e5 + 1;

int t, n, a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1;
    int s = 0;
    for (int i = max(1, n - 100); i <= n; ++i) {
      int j, k;
      for (j = i; j && !(a[i] % a[j]); --j) {
      }
      for (k = j; k && !(a[i] % a[k] && a[j] % a[k]); --k) {
      }
      debug("%d %d %d\n", a[i], a[j], a[k]);
      s = max(s, a[i] + a[j] + a[k]);
    }
    debug("\n");
    cout << s << endl;
  }
  return 0;
}