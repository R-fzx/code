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

const int kN = 5001;

int n, k, a[kN], f[kN][kN], p[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1, p = 1; i <= n; ++i) {
    for (; a[i] - a[p] > 5; ++p) {
    }
    // cerr << i << " " << p << endl;
    for (int j = 1; j <= k; ++j) {
      f[i][j] = max(f[i - 1][j], f[p - 1][j - 1] + i - p + 1);
    }
  }
  cout << f[n][k];
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*

*/