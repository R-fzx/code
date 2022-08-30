#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const LL kM = 1e9 + 7;

struct E {
  LL l, r;
  mutable LL v;

  E(LL l, LL r, LL v) : l(l), r(r), v(v) {}
  bool operator<(const E &o) const { return l < o.l; }
};
LL n, q, vmax;
LL seed;
set<E> odt;

LL rnd() { return exchange(seed, (seed * 7 + 13) % kM); }
LL G(LL n) { return rnd() % n + 1; }
auto Split(LL x) {  // Split [l,r] to [l,x), [x,r] and return [x,r]
  if (x > n) {
    return odt.end();
  }
  auto i = --odt.upper_bound({x, 0, 0});
  if (i->l == x) {
    return i;
  }
  LL l = i->l, r = i->r, v = i->v;
  return odt.erase(i), odt.emplace(l, x - 1, v), odt.emplace(x, r, v).first;
}
void Assign(LL l, LL r, LL v) {
  auto ir = Split(r + 1), il = Split(l);
  odt.erase(il, ir), odt.emplace(l, r, v);
}
void Add(LL l, LL r, LL v) {
  auto ir = Split(r + 1), il = Split(l);
  for (; il != ir; ++il) {
    il->v += v;
  }
}
LL Kth(LL l, LL r, LL k) {
  auto ir = Split(r + 1), il = Split(l);
  if (il == ir) {
    return il->v;
  }
  vector<Pll> s;
  for (; il != ir; ++il) {
    s.emplace_back(il->v, il->r - il->l + 1);
  }
  sort(s.begin(), s.end());
  for (Pll i : s) {
    if (k <= i.second) {
      return i.first;
    }
    k -= i.second;
  }
  return -1;
}
LL P(LL b, LL e, LL m) {
  LL s = 1;
  for (b %= m; e; e >>= 1, b = b * b % m) {
    if (e & 1) {
      s = s * b % m;
    }
  }
  return s;
}
LL Sum(LL l, LL r, LL x, LL y) {
  auto ir = Split(r + 1), il = Split(l);
  LL s = 0;
  for (; il != ir; ++il) {
    s = (s + P(il->v, x, y) * (il->r - il->l + 1) % y) % y;
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q >> seed >> vmax;
  for (LL i = 1; i <= n; ++i) {
    odt.emplace(i, i, G(vmax));
  }
  for (LL o, l, r, x; q--;) {
    o = G(4), l = G(n), r = G(n);
    if (l > r) {
      swap(l, r);
    }
    x = G(o == 3 ? r - l + 1 : vmax);
    if (o == 1) {
      Add(l, r, x);
    } else if (o == 2) {
      Assign(l, r, x);
    } else if (o == 3) {
      cout << Kth(l, r, x) << '\n';
    } else {
      cout << Sum(l, r, x, G(vmax)) << '\n';
    }
  }
  return 0;
}
/*
8 9 7 2 3 1 5 6 4 8
8 9 7 2 3 9 9 6 4 8
8 9 15 10 11 17 17 14 12 16
8 9 15 10 11 17 17 14 12 16
8 9 15 18 19 17 17 14 12 16
1 1 1 1 1 1 1 14 12 16
1 10 10 10 10 10 10 14 12 16
1 10 10 10 5 5 5 14 12 16

*/