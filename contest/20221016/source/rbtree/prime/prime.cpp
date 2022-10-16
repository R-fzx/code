// Please submit with C++14! It's best to use C++20 or higher version.
constexpr bool __MTCS__ = 1;  // Spectre (admin@rbtree.app)
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

bool IP(tp x) {
  for (tp i = 2; i * i <= x; ++i) {
    if (!(x % i)) return 0;
  }
  return 1;
}

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n = ra, u = n + 1, v = n, a, b;
  while (!IP(u)) ++u;
  while (!IP(v)) --v;
  /*
   * 1/2 - 1/v + (n - v + 1)/(u(n) * v(n))
   * (u * v - 2 * u + 2 * (n - v + 1)) / (2 * u * v)
   */
  a = u * v - 2 * u + 2 * (n - v + 1);
  b = 2 * u * v;
  printf("%lld/%lld\n", a / __gcd(a, b), b / __gcd(a, b));
}

struct __Initer_t {
  __Initer_t() {
    freopen("prime.in", "r", stdin);
    freopen("prime.out", "w", stdout);
  }
} __Initer;

//*/