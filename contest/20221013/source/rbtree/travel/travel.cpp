// Please submit with C++14! It's best to use C++20 or higher version.
constexpr bool __MTCS__ = 0;  // Spectre
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
#define fe(arr, exp) for_each(se(arr), exp)
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

constexpr tp Hat_N = 1003;

struct Item {
  tp u, v, l, r;

  Item() = default;
  Item(tp _u, tp _v, tp _l, tp _r) : u(_u), v(_v), l(_l), r(_r) {}

  bool operator<(const Item& comp) const { return r > comp.r; }
};

tp f[Hat_N];
vector<Item> g;

tp n, m;

tp find(tp x) { return f[x] == x ? x : f[x] = find(f[x]); }

void link(tp u, tp v) { f[find(u)] = find(v); }

tp check(tp c) {
  iota(f + 1, f + n + 1, 1);
  for (tp i = 0; i < m; ++i) {
    if (g[i].l <= c) {
      link(g[i].u, g[i].v);
      if (find(1) == find(n)) {
        return g[i].r;
      }
    }
  }
  return -(-1ull >> 2);
}

void __Cored__([[maybe_unused]] tp __TID__) {
  tp tl = 0, tr = -1;
  n = ra;
  for (tp i = m = ra; i; --i) {
    tp u = ra, v = ra, l = ra, r = ra;
    g.emplace_back(u, v, l, r);
  }
  stable_sort(se(g));
  for (tp i = 0; i < m; ++i) {
    tp r = check(g[i].l);
    if ((r - g[i].l > tr - tl) || (r - g[i].l == tr - tl && g[i].l < tr)) {
      tr = r;
      tl = g[i].l;
    }
  }
  printf("%lld\n", tr - tl + 1);
  for (tp i = tl; i <= tr; ++i) {
    printf("%lld ", i);
  }
  puts("");
}

struct __Initer_t {
  __Initer_t() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
  }
} __Initer;

//*/
