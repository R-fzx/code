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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 1e5 + 2;

int t, n, a[kN], b[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      b[i] = a[i] - a[i - 1];
    }
    if (n == 2 && a[1] != a[2]) {
      cout << -1 << endl;
    } else {
      b[n + 1] = -a[n];
      LL ans = 0;
      for (int i = 2; i < n; ++i) {
        if (b[i] > 0) {
          ans += b[i], b[i + 2] += b[i], b[i] = 0;
        }
      }
      for (int i = n; i > 2; --i) {
        if (b[i] < 0) {
          ans -= b[i], b[i - 2] += b[i], b[i] = 0;
        }
      }
      bool f = 1;
      for (int i = 2; i <= n; ++i) {
        f &= !b[i];
      }
      cout << (f && b[1] >= 0 ? 2 * ans : -1) << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
d[i] = a[i] - a[i - 1]
a[i] = a[i - 1] + d[i]
3
8 10 5
8 2 -5 -5
 -1     1
 -1     1
-1   1
-1   1
-1   1
-1   1
-1   1
3 0 0 -3

6
4  6  4  4  6  4
4  2 -2  0  2 -2 -4
  -1     1
  -1     1
        -1     1
        -1     1
           -1     1
           -1     1
-1    1
-1    1

3
0  1  0
0  1 -1  0
  -1     1
-1    1
-1 0  0  1

2
1  2
1  1 -2

3
10  9  9
10 -1  0 -9

*/