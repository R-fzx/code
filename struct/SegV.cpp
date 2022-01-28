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
using Pii = pair<int, int>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 1e5 + 1;

struct E {
  int s, a;
} e[kN << 2];
int n, m, t, o[kN], x[kN], b[kN];

void Add(int x, int v, Pii o) { e[x].s += v * (o.second - o.first + 1), e[x].a += v; }
int Do(int x, Pii o, Pii t, int v = 0) {
  if (t.first > t.second) {
    return 0;
  }
  if (o == t) {
    Add(x, v, o);
    return e[x].s;
  }
  int m = o.first + o.second >> 1, s = 0;
  Add(x * 2, e[x].a, {o.first, m}), Add(x * 2 + 1, e[x].a, {m + 1, o.second}), e[x].a = 0;
  if (t.first <= m) {
    s += Do(x * 2, {o.first, m}, {t.first, min(m, t.second)}, v);
  }
  if (m < t.second) {
    s += Do(x * 2 + 1, {m + 1, o.second}, {max(m + 1, t.first), t.second}, v);
  }
  e[x].s = e[x * 2].s + e[x * 2 + 1].s;
  return s;
}
int At(int k) {
  int l = 1;
  for (int x = 1, r = m; l < r;) {
    x <<= 1;
    int m = l + r >> 1, ls = e[x].s;
    if (k > ls) {
      ++x, k -= ls, l = m + 1;
    } else {
      r = m;
    }
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> o[i] >> x[i];
    if (o[i] != 4) {
      b[++t] = x[i];
    }
  }
  sort(b + 1, b + t + 1), m = unique(b + 1, b + t + 1) - b - 1;
  for (int i = 1; i <= n; ++i) {
    if (o[i] != 4) {
      x[i] = lower_bound(b + 1, b + m + 1, x[i]) - b;
    }
    // cerr << o[i] << " " << x[i] << endl;
    if (o[i] == 1) {
      Do(1, {1, m}, {x[i], x[i]}, 1);
    } else if (o[i] == 2) {
      Do(1, {1, m}, {x[i], x[i]}, -1);
    } else if (o[i] == 3) {
      cout << Do(1, {1, m}, {1, x[i] - 1}) + 1 << endl;
    } else if (o[i] == 4) {
      cout << b[At(x[i])] << endl;
    } else if (o[i] == 5) {
      cout << b[At(Do(1, {1, m}, {1, x[i] - 1}))] << endl;
    } else {
      cout << b[At(Do(1, {1, m}, {1, x[i]}) + 1)] << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}