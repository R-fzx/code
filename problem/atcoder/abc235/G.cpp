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

const int kN = 5e6 + 1;
const LL kM = 998244353;

int n, a[3];
LL s[3][kN], f[kN] = {1}, vf[kN] = {1};

LL P(LL b, LL e = kM - 2) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) {
    if (e & 1) {
      s = s * b % kM;
    }
  }
  return s;
}
LL C(LL n, LL m) {
  if (n < 0 || m < 0 || m > n) {
    return 0;
  }
  return f[n] * vf[m] % kM * vf[n - m] % kM;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> a[0] >> a[1] >> a[2];
  for (int i = 1; i <= n; ++i) {
    vf[i] = P(f[i] = f[i - 1] * i % kM);
  }
  for (int i = 0; i < 3; ++i) {
    s[i][0] = 1;
    for (int j = 1; j <= n; ++j) {
      s[i][j] = (s[i][j - 1] * 2 % kM - C(j - 1, a[i]) + kM) % kM;
    }
  }
  LL ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans = (ans + (((n - i & 1) ? -1 : 1) * C(n, i) + kM) % kM * s[0][i] % kM * s[1][i] % kM * s[2][i] % kM) % kM;
  }
  cout << ans;
  return 0;
}