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

const int kN = 1e5 + 1;

int t, n, m;
LL p, f[kN] = {1}, vf[kN];

LL C(int n, int m) {
  if (!m) {
    return 1;
  }
  int _n = n % p, _m = m % p;
  return C(n / p, m / p) * (_n < _m ? 0 : f[_n] * vf[_m] % p * vf[_n - _m] % p) % p;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> p;
    for (int i = 1; i < p; ++i) {
      f[i] = f[i - 1] * i % p;
    }
    vf[p - 1] = 1;
    for (LL b = f[p - 1], e = p - 2; e; e >>= 1, b = b * b % p) {
      if (e & 1) {
        vf[p - 1] = vf[p - 1] * b % p;
      }
    }
    for (int i = p - 1; i; --i) {
      vf[i - 1] = vf[i] * i % p;
    }
    cout << C(n + m, n) << endl;
  }
  return 0;
}