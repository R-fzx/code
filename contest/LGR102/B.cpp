#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 4e6 + 1;

int n, a[kN], f[kN], p[kN];

int S() {
  int l = INT32_MAX, r = INT32_MIN, s = INT32_MAX;
  for (int i = 1; i <= n; ++i) {
    l = min(l, p[i]), r = max(r, p[i]);
    if (f[r - l + 1] < i + 1) {
      s = min(s, r - l + 1);
    }
  }
  return s == INT32_MAX ? 0 : s;
}

int main() {
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> f[i];
  }
  cout << S();
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}