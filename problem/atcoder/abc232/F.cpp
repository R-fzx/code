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
using LD = long double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 19;

int n;
LL x, y, ans, a[kN], b[kN], f[1 << kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x >> y;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  fill(f, f + (1 << n) + 1, 1LL << 60);
  f[0] = 0;
  for (int i = 0; i < (1 << n); ++i) {
    int c = 0;
    for (int j = 0; j < n; ++j) {
      c += i >> j & 1;
    }
    for (int j = 0, _c = 0; j < n; ++j) {
      if (i >> j & 1 ^ 1) {
        f[i | (1 << j)] = min(f[i | (1 << j)], f[i] + _c * y + abs(a[j] - b[c]) * x), ++_c;
      }
    }
  }
  cout << f[(1 << n) - 1];
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
l[i][j] = abs(a[i]-b[j])

*/