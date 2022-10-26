// #define fastcall __attribute__((optimize("-O3")))
// #pragma GCC optimize(1)
// #pragma GCC optimize(2)
// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-fhoist-adjacent-loads")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kN = 2e5 + 2, kL = 18;

int n, k, h[kN], m, sr[kN], p[kN][kL];
Pii a[kN];
LL ans, b[kN];

int main() {
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
  // RF("h");
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    b[i] = i - h[i];
  }
  for (int i = 0; i < kL; ++i) {
    p[n + 1][i] = n + 1;
  }
  for (int i = n; i >= 1; --i) {
    int x = i + 1;
    for (int j = kL - 1; j >= 0; --j) {
      if (h[p[x][j]] >= h[i]) {
        x = p[x][j];
      }
    }
    if (h[x] >= h[i]) {
      x = p[x][0];
    }
    p[i][0] = x;
    for (int j = 1; j < kL; ++j) {
      p[i][j] = p[p[i][j - 1]][j - 1];
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   cerr << p[i] << ' ';
  // }
  // cerr << '\n';
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i].first >> a[i].second;
    ++sr[a[i].first];
  }
  for (int i = 2; i <= n; ++i) {
    sr[i] += sr[i - 1];
  }
  sort(a + 1, a + m + 1);
  for (int i = n, j = m, pj; i >= 1; --i) {
    for (pj = j; j >= 1 && a[j].first == i; --j) {
      int _p = i + 1;
      for (int k = kL - 1; k >= 0; --k) {
        if (h[p[_p][k]] >= a[j].second) {
          _p = p[_p][k];
        }
      }
      if (h[_p] >= a[j].second) {
        _p = p[_p][0];
      }
      cerr << a[j].first << ' ' << a[j].second << ' ' << _p << '\n';
      if (_p == n + 1) {
        
      } else {
        int _k = k - (b[_p] - a[j].first + a[j].second);
      }
    }
  }
  return 0;
}