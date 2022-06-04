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
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1;

struct E {
  int f, t, d, s, h;
  vector<int> e;
} a[kN];
struct T {
  int s, a = -1;
} e[kN << 2];
int n, q, c, x;
string o;

void Set(int x, int v, int s) { ~v && (e[x].s = v * s, e[x].a = v); }
int Do(int ty, int x, int l, int r, int tl, int tr, int v) {
  if (l == tl && r == tr) {
    ty && (Set(x, v, r - l + 1), 0);
    return v ? e[x].s : r - l + 1 - e[x].s;
  }
  int m = l + r >> 1, s = 0;
  Set(x * 2, e[x].a, m - l + 1), Set(x * 2 + 1, e[x].a, r - m), e[x].a = -1;
  if (tl <= m) {
    s += Do(ty, x * 2, l, m, tl, min(tr, m), v);
  }
  if (m < tr) {
    s += Do(ty, x * 2 + 1, m + 1, r, max(tl, m + 1), tr, v);
  }
  e[x].s = e[x * 2].s + e[x * 2 + 1].s;
  return s;
}
void D(int x) {
  a[x].s = 1;
  for (int i : a[x].e) {
    D(i), a[x].s += a[i].s, a[i].s > a[a[x].h].s && (a[x].h = i);
  }
}
void H(int x, int t) {
  if (x) {
    a[x].t = t, a[x].d = ++c, H(a[x].h, t);
    for (int i : a[x].e) {
      if (i != a[x].h) {
        H(i, i);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    cin >> a[i].f;
    a[++a[i].f].e.push_back(i);
  }
  D(1), H(1, 1);
  cin >> q;
  while (q--) {
    cin >> o >> x;
    ++x;
    if (o[0] == 'i') {
      int s = 0;
      for (; x; x = a[a[x].t].f) {
        s += Do(0, 1, 1, n, a[a[x].t].d, a[x].d, 0), Do(1, 1, 1, n, a[a[x].t].d, a[x].d, 1);
      }
      cout << s << endl;
    } else {
      cout << Do(0, 1, 1, n, a[x].d, a[x].d + a[x].s - 1, 1) << endl;
      Do(1, 1, 1, n, a[x].d, a[x].d + a[x].s - 1, 0);
    }
    // for (int i = 1; i <= n; ++i) {
    //   cerr << Do(0, 1, 1, n, a[i].d, a[i].d, 1) << " ";
    // }
    // cerr << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}