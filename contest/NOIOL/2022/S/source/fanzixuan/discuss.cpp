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
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 6e4 + 1;

int t, n;
bitset<kN> a[kN];
// vector<int> b[kN];

void S() {
  // for (int i = 1; i <= n; ++i) {
  //   bitset<kN> v;
  //   for (int j : b[i]) {
  //     v |= a[j];
  //   }
  // }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      auto x = a[i] & a[j], y = a[i] ^ a[j] | x;
      if (x.any() && y != a[i] && y != a[j]) {
        cout << "YES\n" << i << " " << j << endl;
        return;
      }
    }
  }
  cout << "NO\n";
}

int main() {
#define FILEIO(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout);
  FILEIO("discuss");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1, j, x; i <= n; ++i) {
      a[i].reset();
      for (cin >> j; j--;) {
        cin >> x;
        // b[x].push_back(i);
        a[i].set(x);
      }
    }
    S();
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
2
5
4 1 2 3 5
3 1 2 3
2 1 2
1 1
1 4
4
3 1 2 3
3 2 3 4
0
4 1 2 3 4
*/