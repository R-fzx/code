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

const int kN = 1e5 + 1, kV = 2e5 + 1;

struct E {
  int a, b, c, p, f;
  bool operator<(const E &o) const { return tie(a, b, c) < tie(o.a, o.b, o.c); }
} a[kN];
int n, k;

void S(int l, int r) {
  if (l == r) {
    return;
  }
  int m = l + r >> 1;
  S(l, m), S(m + 1, r);
  // a[l...m].a <= a[m+1...r].a
  // a[l...m].b sorted
  // a[m+1...r].b sorted
  /*
  a 1 1 1 2 3 2
  b 1 2 3 2 4 5
  c 3 2 2 1 1 2
  ----------------------
  a 1 1 2 1 3 2
  b 1 2 2 3 4 5
  c 3 2 1 2 1 2
  */
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].a >> a[i].b >> a[i].c;
  }
  sort(a + 1, a + n + 1);
  for (int _n = exchange(n, 0), i = 1; i <= _n; ++i) {
    if (a[i] < a[n] || a[n] < a[i]) {
      a[++n] = a[i], a[n].p = 1;
    } else {
      ++a[n].p;
    }
  }
  for (int i = 1; i <= n; ++i) {
    debug("%d %d %d %d\n", a[i].a, a[i].b, a[i].c, a[i].p);
  }
  S(1, n);
  return 0;
}