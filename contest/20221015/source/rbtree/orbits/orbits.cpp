// Please submit with C++14! It's best to use C++20 or higher version.
constexpr bool __MTCS__ = 0;  // Spectre (admin@rbtree.app)
#ifndef LOCAL                 // By rbtree (https://rbtree.app)
#pragma region HEAD           // DO OR DIE
#endif
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

tp k, m, cnt;

void dfs(tp idx, tp x) {
  if (!idx) {
    cnt += !(x % k) && __gcd(k, x / k) == 1;
    return;
  }
  for (tp i = 1; i <= m; ++i) dfs(idx - 1, x * i);
}

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n = ra;
  m = ra;
  k = ra;
  dfs(n, 1);
  printf("%lld\n", cnt % 10007);
}

struct __Initer_t {
  __Initer_t() {
    freopen("orbits.in", "r", stdin);
    freopen("orbits.out", "w", stdout);
  }
} __Initer;

//*/