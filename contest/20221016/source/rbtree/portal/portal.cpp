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

constexpr tp Hat_N = 503;
constexpr tp dir[][2] = {1, 0, 0, -1, -1, 0, 0, 1};

tp n, m;

tp dist[Hat_N * Hat_N];
bool a[Hat_N][Hat_N], iq[Hat_N * Hat_N];
vector<pair<tp, tp>> g[Hat_N * Hat_N];

tp id(tp x, tp y) { return x * m - m + y; }

void init(tp x, tp y) {
  pair<tp, tp> t[5];
  tp MIN = -1ull >> 2;
  for (auto&& p : dir) {
    tp dx = x + p[0], dy = y + p[1], len = 1;
    while (!a[dx][dy]) {
      dx += p[0];
      dy += p[1];
      ++len;
    }
    t[++t[0].first] = make_pair(dx - p[0], dy - p[1]);
    MIN = min(MIN, len);
  }
  for (tp i = 1; i <= 4; ++i)
    g[id(x, y)].emplace_back(id(t[i].first, t[i].second), MIN);
}

void spfa(tp s) {
  queue<tp> q;
  for (tp i = 0; i < Hat_N * Hat_N; ++i) dist[i] = -1ull >> 2;
  q.push(s);
  for (dist[s] = 0; q.size(); q.pop()) {
    for (auto&& i : g[q.front()]) {
      if (dist[q.front()] + i.second < dist[i.first]) {
        dist[i.first] = dist[q.front()] + i.second;
        if (!iq[i.first]) {
          q.push(i.first);
          iq[i.first] = 1;
        }
      }
    }
  }
}

void __Cored__([[maybe_unused]] tp __TID__) {
  tp s, t;
  n = ra;
  m = ra;
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      a[i][j] = c == '#';
      if (c == 'C') s = id(i, j);
      if (c == 'F') t = id(i, j);
    }
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= m; ++j) {
      if (!a[i][j]) init(i, j);
    }
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= m; ++j) {
      if (!a[i][j]) {
        for (auto&& p : dir) {
          if (!a[i + p[0]][j + p[1]]) {
            g[id(i, j)].emplace_back(id(i + p[0], j + p[1]), 1);
          }
        }
      }
    }
  }
  spfa(s);
  if (dist[t] == (-1ull >> 2)) {
    puts("nemoguce");
  } else {
    printf("%lld\n", dist[t]);
  }
}

struct __Initer_t {
  __Initer_t() {
    freopen("portal.in", "r", stdin);
    freopen("portal.out", "w", stdout);
  }
} __Initer;

//*/