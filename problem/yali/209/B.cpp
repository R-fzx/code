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
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 60;
const LL kP[kN] = {
    0,
    1000000000000000000,
    1000000000,
    1000000,
    31622,
    3981,
    1000,
    372,
    177,
    100,
    63,
    43,
    31,
    24,
    19,
    15,
    13,
    11,
    10,
    8,
    7,
    7,
    6,
    6,
    5,
    5,
    4,
    4,
    4,
    4,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
};

LL a, b, p[kN], f[kN];

LL P(LL b, LL e) {
  LL s = 1;
  for (; e; e >>= 1, b *= b) {
    (e & 1) && (s *= b);
  }
  return s;
}
LL S(LL x) {
  for (int i = 1; i < kN; ++i) {
    LL l = 2, r = kP[i];
    while (l < r) {
      LL m = l + r >> 1;
      if (P(m, i) < x) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    // debug("%lld %d %lld\n", l, i, x);
    for (LL j = max(2LL, l - 5); j <= min(kP[i], l + 5); ++j) {
      if (P(j, i) > x) {
        p[i] = j - 2;
        break;
      }
    }
    // p[i] = l - (P(l, i) != x) - 1;
  }
  LL ans = 0;
  for (int i = kN - 1; i >= 1; --i) {
    f[i] = p[i];
    for (int j = 2; i * j < kN; ++j) {
      f[i] -= f[i * j];
    }
    ans += f[i] * i;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  while ((cin >> a >> b) && a && b) {
    cout << S(b) - S(a - 1) << '\n';
  }
  return 0;
}
/*
1 1
2
*/