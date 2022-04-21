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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#include <atcoder/all>

using namespace std;
using LL = long long;
using mL = atcoder::modint998244353;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 16;

int n;
LL m, d[kN];
mL f[1 << kN], a[kN + 1], s[1 << kN] = {1};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }
  mL _ = 1;
  for (int i = 1; i <= n; ++i) {
    a[i] = ((i & 1) ? 1 : -1) * _, _ *= i;
    debug("%u ", a[i].val());
  }
  for (int i = 0; i < 1 << n; ++i) {
    int c = 0;
    LL l = 1;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        ++c;
        if ((double)(l /= gcd(l, d[j])) * d[j] > m) {
          l = m + 1;
        } else {
          l *= d[j];
        }
      }
    }
    f[i] = mL(m / l) * a[c];
  }
  for (int i = 1; i < 1 << n; ++i) {
    s[i] = f[i & -i] * s[i ^ (i & -i)];
    for (int c = i ^ (i & -i), j = c; j; j = j - 1 & c) {
      s[i] += f[j | (i & -i)] * s[c ^ j];
    }
  }
  cout << s[(1 << n) - 1].val();
  return 0;
}