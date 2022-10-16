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
#define ra (scanf("%lld", &la), la)
#define se(exp) exp.begin(), exp.end()
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)

typedef long long tp;
using namespace std;
void __Cored__(tp);
tp la;

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

constexpr tp Hat_M = 103;

struct HZT {
  tp a, b, t;

  HZT() = default;
  HZT(tp _a, tp _b, tp _t) : a(_a), b(_b), t(_t) {}

  bool operator<(const HZT& comp) const { return a < comp.a; }
} a[Hat_M];

tp m, MAX = 0;
bool b[Hat_M];

void dfs(tp x, tp c, tp t) {
  function<void(tp pi)> update = [&](tp pi) -> void {
    for (tp i = x; i >= 1 && i <= m; i += pi) {
      if (a[i].t >= abs(a[x].a - a[i].a) + t && !b[i]) {
        b[i] = 1;
        dfs(i, c + a[i].b, t + abs(a[x].a - a[i].a));
        b[i] = 0;
        break;
      }
    }
  };
  update(1);
  update(-1);
  MAX = max(MAX, c);
}

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n = ra, k = ra;
  m = ra;
  for (tp i = 1; i <= m; ++i) {
    a[i].a = ra;
    a[i].b = ra;
    a[i].t = ra;
  }
  stable_sort(a + 1, a + m + 1);
  if (a[m].a < k) {
    dfs(m, 0, abs(a[m].a - k) + 1);
    printf("%lld\n", MAX);
    return;
  }
  for (tp lk = 1; lk <= m; ++lk) {
    if (a[lk].a == k) {
      dfs(lk, 0, 1);
    } else if (a[lk].a > k) {
      dfs(lk - 1, 0, abs(a[lk - 1].a - k) + 1);
      dfs(lk, 0, abs(a[lk].a - k) + 1);
    }
  }
  printf("%lld\n", MAX);
}

struct __Initer_t {
  __Initer_t() {
    freopen("go.in", "r", stdin);
    freopen("go.out", "w", stdout);
  }
} __Initer;

//*/