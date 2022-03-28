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

const int kN = 1001;

int n, m, a[kN], c;

int main() {
#define FILEIO(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout);
  FILEIO("kingdom")
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1, x; j <= n; ++j) {
      cin >> x;
      a[j] += (x ? 1 : -1);
    }
  }
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    // cout << a[i] << " ";
    c += x ^ (a[i] < 0);
  }
  // cout << endl;
  cout << c;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
5 6
1 0 1 1 1 0
0 1 0 1 1 1
0 0 1 0 1 0
1 0 1 0 1 0
0 1 0 1 0 0

0 0 1 1 1 0
1 0 1 0 1 0
*/