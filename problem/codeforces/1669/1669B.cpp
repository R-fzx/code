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

const int kN = 2e5 + 1;

int t, n, a[kN], c[kN];

int F() {
  for (int i = 1; i <= n; ++i) {
    if (c[i] >= 3) {
      return i;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    fill(c + 1, c + n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      ++c[a[i]];
    }
    cout << F() << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}