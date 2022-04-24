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
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 51;

int t, n, a[kN], c[2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    c[0] = c[1] = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      c[i & 1] += a[i] & 1;
    }
    if ((!c[0] || c[0] == n / 2) && (!c[1] || c[1] == (n + 1) / 2)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}