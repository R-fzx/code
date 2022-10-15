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
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kM = 1e9 + 7, kN = 1e6 + 1;

int n, m, k;
LL f[kN], vf[kN], ans;

LL P(LL b, LL e) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) {
    (e & 1) && (s = s * b % kM);
  }
  return s;
}

int main() {
  RF("painting");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = f[0] = 1; i <= k; ++i) {
    f[i] = f[i - 1] * i % kM;
  }
  vf[k] = P(f[k], kM - 2);
  for (int i = k; i; --i) {
    vf[i - 1] = vf[i] * i % kM;
  }
  for (int i = 1; i <= k; ++i) {
    ans = (ans + P(f[k] * vf[i] % kM * vf[k - i] % kM * (P(i, n) - i * P(i - 1, n) % kM + kM) % kM, m)) % kM;
  }
  cout << ans << endl;
  return 0;
}