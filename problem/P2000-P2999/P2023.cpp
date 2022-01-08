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

const int kN = 1e5 + 1;

struct E {
  LL a = 1, b, s;
} e[kN << 2];
int n, m, o, l, r;
LL p, v;

void Add(int x, Pll o, LL v) {
  e[x].b = (e[x].b + v) % p, e[x].s = (e[x].s + v * (o.second - o.first + 1)) % p;
}
void Mul(int x, LL v) {
  e[x] = {e[x].a * v % p, e[x].b * v % p, e[x].s * v % p};
}
LL Do(int ty, int x, Pll o, Pll t, LL v = 0) {
  if (o == t) {
    if (ty == 1) {
      Mul(x, v);
    } else if (ty == 2) {
      Add(x, o, v);
    }
    return e[x].s;
  }
  LL m = o.first + o.second >> 1, s = 0;
  Mul(x * 2, e[x].a), Mul(x * 2 + 1, e[x].a), Add(x * 2, {o.first, m}, e[x].b), Add(x * 2 + 1, {m + 1, o.second}, e[x].b);
  e[x].a = 1, e[x].b = 0;
  if (t.first <= m) {
    s = (s + Do(ty, x * 2, {o.first, m}, {t.first, min(m, t.second)}, v)) % p;
  }
  if (m < t.second) {
    s = (s + Do(ty, x * 2 + 1, {m + 1, o.second}, {max(m + 1, t.first), t.second}, v)) % p;
  }
  e[x].s = (e[x].a * (e[x * 2].s + e[x * 2 + 1].s) + e[x].b * (o.second - o.first + 1)) % p;
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) {
    cin >> v;
    Do(2, 1, {1, n}, {i, i}, v);
  }
  cin >> m;
  while (m--) {
    cin >> o >> l >> r;
    o == 3 ? (v = 0) : (cin >> v, 0);
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
ax+b
a(cx+d)+b
ac ad+b
*/