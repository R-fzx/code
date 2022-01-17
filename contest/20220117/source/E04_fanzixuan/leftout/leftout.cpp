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

const int kN = 1001;

int n, b[kN][kN], _i, _j, c;
bool ie = 1, je = 1;

int main() {
  freopen("leftout.in", "r", stdin);
  freopen("leftout.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char ch;
      cin >> ch;
      b[i][j] = ch == 'R';
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!b[i][1]) {
      for (int j = 1; j <= n; ++j) {
        b[i][j] ^= 1;
      }
    }
  }
  for (int j = 1; j <= n; ++j) {
    if (!b[1][j]) {
      for (int i = 1; i <= n; ++i) {
        b[i][j] ^= 1;
      }
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     cout << b[i][j];
  //   }
  //   cout << endl;
  // }
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= n; ++j) {
      if (!b[i][j]) {
        ++c, _i = _i ? _i : i, _j = _j ? _j : j;
        ie &= _i == i, je &= _j == j;
      }
    }
  }
  if (c == 1) {
    cout << _i << " " << _j;
  } else if (c == n - 1 && (ie || je)) {
    cout << (ie ? _i : 1) << " " << (je ? _j : 1);
  } else if (c == (n - 1) * (n - 1)) {
    cout << 1 << " " << 1;
  } else {
    cout << -1;
  }
#ifdef TIME
    fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}