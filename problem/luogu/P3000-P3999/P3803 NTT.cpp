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
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2097152;
const LL kM = 998244353, kG = 3;
LL P(LL b, LL e) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) {
    (e & 1) && (s = s * b % kM);
  }
  return s;
}
const LL kiG = P(kG, kM - 2);

int n, m, l, cl, r[kN];
LL f[kN], g[kN];

void NTT(LL *a, int l, bool t) {
  for (int i = 0; i < l; ++i) {
    if (i < r[i]) {
      swap(a[i], a[r[i]]);
    }
  }
  for (int _l = 1; _l < l; _l <<= 1) {
    LL wn = P(t ? kiG : kG, (kM - 1) / (_l << 1));
    for (int i = 0; i < l; i += _l << 1) {
      LL w = 1;
      for (int j = i; j < i + _l; ++j) {
        LL t = w * a[j + _l] % kM;
        a[j + _l] = (a[j] - t + kM) % kM, a[j] = (a[j] + t) % kM;
        w = w * wn % kM;
      }
    }
  }
  if (t) {
    LL il = P(l, kM - 2);
    for (int i = 0; i < l; ++i) {
      a[i] = a[i] * il % kM;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (l = 1; l <= n + m; l <<= 1, ++cl) {
  }
  for (int i = 0; i < l; ++i) {
    r[i] = r[i >> 1] >> 1 | (i & 1) << cl - 1;
  }
  for (int i = 0; i <= n; ++i) {
    cin >> f[i];
  }
  for (int i = 0; i <= m; ++i) {
    cin >> g[i];
  }
  NTT(f, l, 0), NTT(g, l, 0);
  for (int i = 0; i < l; ++i) {
    f[i] = f[i] * g[i] % kM;
  }
  NTT(f, l, 1);
  for (int i = 0; i <= n + m; ++i) {
    cout << f[i] << ' ';
  }
  return 0;
}