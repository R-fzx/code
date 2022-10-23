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

constexpr tp Hat_N = 1e5 + 3;

tp xs[Hat_N], xe[Hat_N], ys[Hat_N], ye[Hat_N], zs[Hat_N], ze[Hat_N], qxs[Hat_N],
    qys[Hat_N], qzs[Hat_N], sxs[Hat_N], sys[Hat_N], szs[Hat_N], qxe[Hat_N],
    qye[Hat_N], qze[Hat_N], sxe[Hat_N], sye[Hat_N], sze[Hat_N];

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n = ra, sum = 0, bx = -1ull >> 2, by = -1ull >> 2, bz = -1ull >> 2,
     sx = -bx, sy = -by, sz = -bz;
  for (tp i = 1; i <= n; ++i) {
    xs[i] = ra;
    ys[i] = ra;
    zs[i] = ra;
    xe[i] = ra;
    ye[i] = ra;
    ze[i] = ra;
  }
  qxs[0] = -(-1ull >> 2);
  qys[0] = -(-1ull >> 2);
  qzs[0] = -(-1ull >> 2);
  sxs[n + 1] = -(-1ull >> 2);
  sys[n + 1] = -(-1ull >> 2);
  szs[n + 1] = -(-1ull >> 2);
  qxe[0] = -1ull >> 2;
  qye[0] = -1ull >> 2;
  qze[0] = -1ull >> 2;
  sxe[n + 1] = -1ull >> 2;
  sye[n + 1] = -1ull >> 2;
  sze[n + 1] = -1ull >> 2;
  for (tp i = 1; i <= n; ++i) {
    qxs[i] = max(qxs[i - 1], xs[i]);
    qys[i] = max(qys[i - 1], ys[i]);
    qzs[i] = max(qzs[i - 1], zs[i]);
    qxe[i] = min(qxe[i - 1], xe[i]);
    qye[i] = min(qye[i - 1], ye[i]);
    qze[i] = min(qze[i - 1], ze[i]);
  }
  for (tp i = n; i >= 1; --i) {
    sxs[i] = max(sxs[i + 1], xs[i]);
    sys[i] = max(sys[i + 1], ys[i]);
    szs[i] = max(szs[i + 1], zs[i]);
    sxe[i] = min(sxe[i + 1], xe[i]);
    sye[i] = min(sye[i + 1], ye[i]);
    sze[i] = min(sze[i + 1], ze[i]);
  }
  for (tp i = 1; i <= n; ++i) {
    sx = max(sx, xs[i]);
    sy = max(sy, ys[i]);
    sz = max(sz, zs[i]);
    bx = min(bx, xe[i]);
    by = min(by, ye[i]);
    bz = min(bz, ze[i]);
  }
  sum = (1 - n) * (bx - sx + 1) * (by - sy + 1) * (bz - sz + 1);
  for (tp i = 1; i <= n; ++i) {
    sum += (min(qxe[i - 1], sxe[i + 1]) - max(qxs[i - 1], sxs[i + 1]) + 1) *
           (min(qye[i - 1], sye[i + 1]) - max(qys[i - 1], sys[i + 1]) + 1) *
           (min(qze[i - 1], sze[i + 1]) - max(qzs[i - 1], szs[i + 1]) + 1);
  }
  printf("%lld\n", sum);
}

struct __Initer_t {
  __Initer_t() {
    freopen("cube.in", "r", stdin);
    freopen("cube.out", "w", stdout);
  }
} __Initer;

//*/
