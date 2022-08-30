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

const LL kM = 998244353;
const int kN = 3e6 + 1;

int n, r, g, b, k;
LL f[kN] = {1}, vf[kN], ans;

LL P(LL b, LL e) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) {
    if (e & 1) {
      s = s * b % kM;
    }
  }
  return s;
}
LL C(int n, int m) { return f[n] * vf[m] % kM * vf[n - m] % kM; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> r >> g >> b >> k;
  n = r + g + b;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] * i % kM;
  }
  vf[n] = P(f[n], kM - 2);
  for (int i = n; i >= 1; --i) {
    vf[i - 1] = vf[i] * i % kM;
  }
  r -= k, g -= k;
  return 0;
}
/*
n=r+g+b
C(n/2,k)+C((n+1)/2-1,k)
C(n-2k,r-k)
rr r  r rrr
n=11, r=7, g=2, rr=3 f=1
C(n-2r+rr+f,g)
==========================================

*/