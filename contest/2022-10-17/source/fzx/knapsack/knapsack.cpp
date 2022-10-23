#define fastcall __attribute__((optimize("-O3")))
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

const int kN = 1001, kC = 7002, kI = -1e9, kM = 3e5 + 1;

int n, m, nc, lc[kN], rc[kN], qk[kM], qt[kM], mt;
LL v[kC], w[kC], f[kC][kN], g[kC][kN], h[kN][kN];

int main() {
  RF("knapsack");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, _v, _w, c; i <= n; ++i) {
    cin >> _v >> _w >> c;
    lc[i] = nc;
    for (int j = 1; c >= j; c -= j, j <<= 1) {
      ++nc, v[nc] = _v * j, w[nc] = _w * j;
    }
    if (c) {
      ++nc, v[nc] = _v * c, w[nc] = _w * c;
    }
    rc[i] = nc;
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> qk[i] >> qt[i], ++qk[i], mt = max(mt, qt[i]);
  }
  for (int j = 1; j <= mt; ++j) {
    f[0][j] = kI;
  }
  for (int i = 1; i <= nc; ++i) {
    for (int j = 0; j <= mt; ++j) {
      f[i][j] = max(f[i - 1][j], j >= v[i] ? f[i - 1][j - v[i]] + w[i] : kI);
    }
  }
  for (int i = 0; i <= nc; ++i) {
    for (int j = 1; j <= mt; ++j) {
      f[i][j] = max(f[i][j], f[i][j - 1]);
    }
  }
  for (int j = 1; j <= mt; ++j) {
    g[nc + 1][j] = kI;
  }
  for (int i = nc; i >= 1; --i) {
    for (int j = 0; j <= mt; ++j) {
      g[i][j] = max(g[i + 1][j], j >= v[i] ? g[i + 1][j - v[i]] + w[i] : kI);
    }
  }
  for (int i = 1; i <= nc + 1; ++i) {
    for (int j = 1; j <= mt; ++j) {
      g[i][j] = max(g[i][j], g[i][j - 1]);
    }
  }
  for (int i = 1; i <= m; ++i) {
    // cout << h[qk[i]][qt[i]] << '\n';
    LL x = 0;
    for (int j = 0; j <= qt[i]; ++j) {
      x = max(x, f[lc[qk[i]]][j] + g[rc[qk[i]] + 1][qt[i] - j]);
    }
    cout << x << '\n';
  }
  return 0;
}
/*
f[i][j] [1,i]物品，背包容量j，最大价值
g[i][j] [i,nc]物品，背包容量j，最大价值
h[i][j] [1,lc[i]]+[rc[i]+1,nc]，背包容量j，最大价值

f[i+1][j] = max(f[i+1][j], f[i][j])
f[i+1][j+v[i]] = max(f[i+1][j+v[i]], f[i][j]+w[i])
O(ntlogc)
*/