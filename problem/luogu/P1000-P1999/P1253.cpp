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
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 1e6 + 1;

struct E {
  LL m, a = INT64_MAX, b;
} e[kN << 2];
int n, q, o, l, r, v;

void Set(int x, LL v) {
  if (v != INT64_MAX) {
    e[x].m = e[x].a = v, e[x].b = 0;
  }
}
void Add(int x, LL v) {
  e[x].m += v, e[x].b += v;
}
LL Do(int ty, int x, Pll o, Pll t, LL v) {
  if (o == t) {
    if (ty == 1) {
      Set(x, v);
    } else if (ty == 2) {
      Add(x, v);
    }
    return e[x].m;
  }
  Set(x * 2, e[x].a), Set(x * 2 + 1, e[x].a);
  Add(x * 2, e[x].b), Add(x * 2 + 1, e[x].b);
  e[x].a = INT64_MAX, e[x].b = 0;
  LL m = o.first + o.second >> 1, s = INT64_MIN;
  if (t.first <= m) {
    s = max(s, Do(ty, x * 2, {o.first, m}, {t.first, min(m, t.second)}, v));
  }
  if (m < t.second) {
    s = max(s, Do(ty, x * 2 + 1, {m + 1, o.second}, {max(m + 1, t.first), t.second}, v));
  }
  e[x].m = max(e[x * 2].m, e[x * 2 + 1].m);
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> v;
    Do(1, 1, {1, n}, {i, i}, v);
  }
  while (q--) {
    cin >> o >> l >> r;
    if (o != 3) {
      cin >> v;
    }
    LL s = Do(o, 1, {1, n}, {l, r}, v);
    if (o == 3) {
      cout << s << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
1: m = x, a = x, b = 0
2: m += x, b += x
PushDown:
l.1(a), l.2(b), r.1(a), r.2(b)
a = -1, b = 0
*/