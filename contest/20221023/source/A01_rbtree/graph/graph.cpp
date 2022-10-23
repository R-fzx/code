// Please submit with C++14! It's best to use C++20 or higher version.
constexpr bool __MTCS__ = 0;  // Spectre (admin@rbtree.app)
#ifndef LOCAL                 // By rbtree (https://rbtree.app)
#pragma region HEAD           // DO OR DIE
#endif
#pragma GCC optimize("Ofast")
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
#ifdef ___RB_DEBUG___
#include "rb_debug.h"
#else
#define dbg(...)
#endif
#define ra (__Read(), la)
#define se(exp) begin(exp), end(exp)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)
#define qmx(exp1, exp2, exp3) exp1 = exp3(exp1, exp2)

typedef long long tp;
using namespace std;
void __Cored__(tp);
tp la;

void __Read() {
  bool f = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    f = c == '-';
    c = getchar();
  }
  la = c & 15;
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
    la = la * 10 + (c & 15);
  la = f ? -la : la;
}

signed main(/* >_< */) {
  for (static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0; __NOW__ < __TCS__;
       __Cored__(++__NOW__)) {
  }
  return 0;
}

#ifndef LOCAL
#pragma endregion HEAD
#endif

////////////////////////////////////////////////////////////////////////////////

constexpr tp Hat_N = 13;

bool s[Hat_N];
tp a[Hat_N], p[Hat_N];
vector<tp> h[Hat_N];

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n = ra, best = 0;
  iota(p + 1, p + n + 1, 1);
  for (tp i = 1; i <= n; ++i) a[i] = ra;
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= n; ++j) {
      if (!(a[i] & a[j])) h[i].push_back(j);
	}
  }
  do {
    tp tar = 0;
    for (tp i = 1; i <= n; ++i) s[i] = 0;
    for (tp i = 1; i <= n; ++i) {
      bool f = 0;
      tp MAX = 0;
      for (auto&& j : h[p[i]]) {
        if (s[j]) {
          qmx(MAX, a[j], max);
          f = 1;
        }
	  }
      if (f) tar += MAX;
      s[p[i]] = 1;
    }
    qmx(best, tar, max);
  } while (next_permutation(p + 1, p + n + 1));
  printf("%lld\n", best);
}

struct __Initer_t {
  __Initer_t() {
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
  }
} __Initer;

//*/
