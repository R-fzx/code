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

struct M {
  int n, m;
  LL a[4][4];
  M() {
    n = m = 0, fill(&a[0][0], &a[3][3] + 1, 0);
  }
  const M operator*(const M &o) const {
    M x;
    x.n = n, x.m = o.m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < o.m; ++j) {
        for (int k = 0; k < m; ++k) {
          x.a[i][j] = (x.a[i][j] + a[i][k] * o.a[k][j] % kM) % kM;
        }
      }
    }
    return x;
  }
} s, f;
int h, w, k, x1, y1, x2, y2;
// LL ans, f[2][2], p[2][2];

M P(M b, LL e) {
  M s;
  s.n = 4, s.m = 4, s.a[0][0] = s.a[1][1] = s.a[2][2] = s.a[3][3] = 1;
  for (; e; e >>= 1, b = b * b) {
    (e & 1) && (s = s * b, 1);
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
  s.n = 1, s.m = 4, s.a[0][(x1 == x2) * 2 + (y1 == y2)] = 1;
  f.n = f.m = 4;
  f.a[0][0] = (h + w - 4) % kM, f.a[0][1] = (w - 1) % kM, f.a[0][2] = (h - 1) % kM;
  f.a[1][0] = 1, f.a[1][1] = (h - 2) % kM, f.a[1][3] = (h - 1) % kM;
  f.a[2][0] = 1, f.a[2][2] = (w - 2) % kM, f.a[2][3] = (w - 1) % kM;
  f.a[3][1] = 1, f.a[3][2] = 1;
  // f[x1 == x2][y1 == y2] = 1;
  // while (k--) {
  //   p[0][0] = f[0][0] * (h + w - 4) % kM + f[0][1] * (w - 1) % kM + f[1][0] * (h - 1) % kM;
  //   p[0][1] = f[0][0] % kM + f[0][1] * (h - 2) % kM + f[1][1] * (h - 1) % kM;
  //   p[1][0] = f[0][0] % kM + f[1][0] * (w - 2) % kM + f[1][1] * (w - 1) % kM;
  //   p[1][1] = f[0][1] % kM + f[1][0] % kM;
  //   f[0][0] = p[0][0] % kM, f[0][1] = p[0][1] % kM, f[1][0] = p[1][0] % kM, f[1][1] = p[1][1] % kM;
  // }
  cout << (s * P(f, k)).a[0][3] % kM;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
