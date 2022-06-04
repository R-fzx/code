#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
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
  int s, a;
} e[kN << 2];
int n, q, o, l, r;

void Rev(int x, int l, int v) { e[x].s = (v ? l - e[x].s : e[x].s), e[x].a ^= v; }
int Do(int x, Pll o, Pll t, int v) {
  if (o == t) {
    Rev(x, o.second - o.first + 1, v);
    return e[x].s;
  }
  LL m = o.first + o.second >> 1, s = 0;
  Rev(x * 2, m - o.first + 1, e[x].a), Rev(x * 2 + 1, o.second - m, e[x].a), e[x].a = 0;
  if (t.first <= m) {
    s += Do(x * 2, {o.first, m}, {t.first, min(m, t.second)}, v);
  }
  if (m < t.second) {
    s += Do(x * 2 + 1, {m + 1, o.second}, {max(m + 1, t.first), t.second}, v);
  }
  e[x].s = e[x * 2].s + e[x * 2 + 1].s;
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  while (q--) {
    cin >> o >> l;
    if (o == 1) {
      cin >> r;
      Do(1, {1, n}, {l, r}, 1);
    } else {
      cout << Do(1, {1, n}, {l, l}, 0) << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}