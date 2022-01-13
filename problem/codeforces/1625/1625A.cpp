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
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using LD = long double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 101;

int t, n, l, a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> l;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < l; ++i) {
      int c = 0;
      for (int j = 1; j <= n; ++j) {
        c += a[j] >> i & 1;
      }
      // cout << c << " ";
      ans |= (c > n - c) << i;
    }
    // cout << endl;
    cout << ans << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}