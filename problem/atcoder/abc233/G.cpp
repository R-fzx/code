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

const int kN = 51;

int n, s[kN][kN], f[kN][kN][kN][kN];
char ch;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> ch;
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (ch == '#');
    }
  }
  for (int xl = 1; xl <= n; ++xl) {
    for (int yl = 1; yl <= n; ++yl) {
      for (int x1 = 1, x2; (x2 = x1 + xl - 1) <= n; ++x1) {
        for (int y1 = 1, y2; (y2 = y1 + yl - 1) <= n; ++y1) {
          int &x = f[x1][y1][xl][yl];
          x = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] ? max(xl, yl) : 0;
          for (int _xl = 1; _xl < xl; ++_xl) {
            x = min(x, f[x1][y1][_xl][yl] + f[x1 + _xl][y1][xl - _xl][yl]);
          }
          for (int _yl = 1; _yl < yl; ++_yl) {
            x = min(x, f[x1][y1][xl][_yl] + f[x1][y1 + _yl][xl][yl - _yl]);
          }
        }
      }
    }
  }
  cout << f[1][1][n][n];
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}