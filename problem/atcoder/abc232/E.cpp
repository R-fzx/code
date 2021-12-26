#include <algorithm>
#include <bitset>
// #include <cmath>
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
using LD = long double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const LL kM = 998244353;

int h, w, k, x1, y1, x2, y2;
LL ans, f[2][2], p[2][2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
  f[x1 == x2][y1 == y2] = 1;
  while (k--) {
    p[0][0] = f[0][0] * (h + w - 4) % kM + f[0][1] * (w - 1) % kM + f[1][0] * (h - 1) % kM;
    p[0][1] = f[0][0] % kM + f[0][1] * (h - 2) % kM + f[1][1] * (h - 1) % kM;
    p[1][0] = f[0][0] % kM + f[1][0] * (w - 2) % kM + f[1][1] * (w - 1) % kM;
    p[1][1] = f[0][1] % kM + f[1][0] % kM;
    f[0][0] = p[0][0] % kM, f[0][1] = p[0][1] % kM, f[1][0] = p[1][0] % kM, f[1][1] = p[1][1] % kM;
  }
  cout << f[1][1];
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/**
 * @brief
 * l[i][j] = abs(a[i]-b[j])
 */