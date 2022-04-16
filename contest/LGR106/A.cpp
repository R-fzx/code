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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 2;

int t, n, s[kN], a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1, p = 0; i <= n + 1; ++i) {
      if (i <= n) {
        cin >> s[i];
      } else {
        s[i] = s[p] + (i - p);
      }
      if (~s[i]) {
        int d = (s[i] - s[p]) / (i - p);
        for (int j = p + 1; j < i; ++j) {
          s[j] = s[j - 1] + d + (j - p <= (s[i] - s[p]) % (i - p));
        }
        p = i;
      }
    }
    for (int i = 1; i <= n; ++i) {
      debug("%d ", s[i]);
    }
    debug("\n");
    for (int i = 1; i <= n; ++i) {
      cout << s[i] - s[i - 1] << " ";
    }
    cout << endl;
  }
  return 0;
}