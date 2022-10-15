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

constexpr tp Hat_N = 50003;

tp s, t;
bool vis[Hat_N];
tp p[Hat_N], c[Hat_N];
vector<pair<tp, double>> e[Hat_N];

void dfs(tp x, tp l, tp r) {
  vis[x] = 1;
  for (auto&& i : e[x]) {
    if (l <= i.second && i.second <= r && !vis[i.first]) dfs(i.first, l, r);
  }
}

bool check(tp l, tp r) {
  memset(vis, 0, sizeof vis);
  dfs(s, l, r);
  return vis[t];
}

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n = ra, m = ra, l = 0, r = 15000, b;
  vector<pair<tp, pair<tp, tp>>> _e;
  for (tp i = 0; i < m; ++i) {
    tp a = ra, b = ra, c = ra;
    _e.push_back(make_pair(a, make_pair(b, c)));
    _e.push_back(make_pair(b, make_pair(a, c)));
  }
  for (tp i = 1; i <= n; ++i) {
    t = ra;
    while (t--) p[ra] = i;
  }
  for (tp i = 1; i <= n; ++i) c[i] = ra;
  s = ra;
  t = ra;
  for (tp i = 0; i < _e.size(); ++i)
    e[_e[i].first].emplace_back(_e[i].second.first,
                                (c[p[_e[i].first]] + c[p[_e[i].second.first]]) /
                                    200.0 * _e[i].second.second);
  while (l <= r) {
    tp mid = l + r >> 1;
    if (check(mid, 15000)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  b = r;
  l = exchange(r, 15000);
  while (l <= r) {
    tp mid = l + r >> 1;
    if (check(b, mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%lld %lld\n", b, l);
}

struct __Initer_t {
  __Initer_t() {
    freopen("trip.in", "r", stdin);
    freopen("trip.out", "w", stdout);
  }
} __Initer;

//*/