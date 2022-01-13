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

const int kN = 1.5e5 + 1;

int t, n, a[kN], p[kN], ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    fill(p + 1, p + kN, 0), ans = -1;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if (p[a[i]]) {
        ans = max(ans, p[a[i]] + n - i);
      }
      p[a[i]] = i;
    }
    cout << ans << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
... 1 ... 1 ... 1 ...

*/