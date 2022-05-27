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

int q;
LL k;

LL C(LL d, LL c, LL p) { return (p + d + p + c * d) * c / 2; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> k;
    LL d = 1, c = 9, p = 0;
    for (LL x; k > (x = C(d, c, p)); k -= x, p += c * d, ++d, c *= 10) {
    }
    int l = 1, r = c;
    for (int m; l <= r; ) {
      m = l + r >> 1;
      if (k > C(d, m, p)) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    k -= C(d, r, p), d = 1, c = 9, p = 1;
    for (LL x; k > (x = d * c); k -= x, ++d, c *= 10, p *= 10) {
    }
    debug("%lld %lld %lld\n", k, d, c);
    LL x = p + (k - 1) / d;
    k = d - (k - 1) % d - 1;
    for (; k--; x /= 10) {
    }
    cout << x % 10 << endl;
  }
  return 0;
}
/*
1
12
123
1234
12345
123456
1234567
12345678
123456789
12345678910

1011121314151617...
k
*/