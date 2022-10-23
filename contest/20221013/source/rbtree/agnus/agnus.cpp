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

void __Cored__([[maybe_unused]] tp __TID__) {
  tp cnt = 0, t = 1;
  string s;
  cin >> s;
  for (tp i = 4; i < s.size(); ++i) {
    if (s[i - 4] == 'a' && s[i - 3] == 'g' && s[i - 2] == 'n' &&
        s[i - 1] == 'u' && s[i] == 's') {
      cnt += exchange(t, 5) * (s.size() - i);
      i += 4;
    } else {
      ++t;
    }
  }
  printf("%lld\n", cnt);
}

struct __Initer_t {
  __Initer_t() {
    freopen("agnus.in", "r", stdin);
    freopen("agnus.out", "w", stdout);
  }
} __Initer;

//*/