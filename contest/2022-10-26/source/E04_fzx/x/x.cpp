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
#include <iostream>
#include <set>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kN = 1e5 + 1;

int n, ans;
bool subtask3;
Pii a[kN];

int main() {
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
  RF("x");
  cin >> n;
  subtask3 = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
    subtask3 &= !a[i].second;
  }
  sort(a + 1, a + n + 1);
  if (subtask3) {
    cout << unique(a + 1, a + n + 1) - a - 1;
    return 0;
  }
  for (LL i = 0; i < (1LL << n); ++i) {
    bool f = 1;
    int c = 0;
    for (int j = 0; f && j < n; ++j) {
      if (i >> j & 1) {
        ++c;
        for (int k = j + 1; f && k < n; ++k) {
          if (i >> k & 1) {
            f &= a[k + 1].first - a[j + 1].first > a[j + 1].second + a[k + 1].second;
          }
        }
      }
    }
    if (f) {
      ans = max(ans, c);
    }
  }
  cout << ans;
  return 0;
}