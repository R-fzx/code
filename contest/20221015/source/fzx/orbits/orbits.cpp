#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

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

const int kN = 3001, kC = 6501, kM = 10007, kV = 1e7 + 1;

int n, m, k, f[kC], g[kN][kC], lks, plks;
vector<int> lk, plk;
vector<int> llk[kC];
int d[kV];

int main() {
  RF("orbits");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i * i <= k; ++i) {
    if (k % i == 0) {
      lk.push_back(i);
    }
  }
  for (int i = lk.size() - 1; i >= 0; --i) {
    if (k / lk[i] != lk[i]) {
      lk.push_back(k / lk[i]);
    }
  }
  lks = lk.size();
  int x = k;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      plk.push_back(i);
      for (; x % i == 0; x /= i) {
      }
    }
  }
  if (x > 1) {
    plk.push_back(x);
  }
  plks = plk.size();
  for (int i = 0; i < lks; ++i) {
    int x = lk[i], _m = m / x;
    d[x] = i;
    for (int j = 0; j < 1 << plks; ++j) {
      int c = 0, s = 1;
      for (int k = 0; k < plks; ++k) {
        if (j >> k & 1) {
          ++c, s *= plk[k];
        }
      }
      f[i] += ((c & 1) ? -1 : 1) * (_m / s);
    }
    g[1][i] = f[i] %= kM;
  }
  for (int i = 0; i < lks; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (lk[i] % lk[j] == 0) {
        llk[i].push_back(j);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < lks; ++j) {
      for (int k : llk[j]) {
        g[i][j] = (g[i][j] + g[i - 1][k] * f[d[lk[j] / lk[k]]]) % kM;
      }
    }
  }
  cout << g[n][lks - 1];
  return 0;
}