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

Mll lg;
void Init(int n) {
  for (LL i = 0, s = 1; s <= n; lg[s] = i++, s <<= 1) {
  }
}
struct vEB {
  int u, mi = -1, mx = -1, p, su;
  vector<int> l;
} e[kN << 1];
int n, m, t, o, x, r;
int Where(int o, int x) { return x / e[o].su; }
int Pos(int o, int x) { return x % e[o].su; }
int Index(int o, int w, int p) { return w * e[o].su + p; }
void Build(int o, int lu) {
  e[o].p = e[o].mi = e[o].mx = -1;
  if (lu <= 1) {
    e[o].u = 2, e[o].su = 1;
    return;
  }
  e[o].u = 1 << lu, e[o].su = 1 << (lu >> 1);
  int cs = lu + 1 >> 1;
  Build(e[o].p = ++t, cs), e[o].l.resize(1 << cs);
  for (int &i : e[o].l) {
    Build(i = ++t, lu >> 1);
  }
}
bool Contains(int o, int x) { return x == e[o].mi || x == e[o].mx || (e[o].u > 2 && Contains(e[o].l[Where(o, x)], Pos(o, x))); }
int Min(int o) { return e[o].mi; }
int Max(int o) { return e[o].mx; }
int Next(int o, int x) {
  if (e[o].u == 2) {
    return x == 0 && e[o].mx == 1 ? 1 : -1;
  }
  if (x < e[o].mi) {
    return e[o].mi;
  }
  int w = Where(o, x);
  if (Pos(o, x) < Max(e[x].l[w])) {
    return Index(o, w, Next(e[x].l[w], Pos(o, x)));
  }
  int nl = Next(e[x].p, w);
  if (nl == -1) {
    return -1;
  }
  return Index(o, nl, Min(e[x].l[nl]));
}
int Pre(int o, int x) {
  if (e[o].u == 2) {
    return x == 1 && e[o].mi == 0 ? 0 : -1;
  }
  if (e[o].mx != -1 && x > e[o].mx) {
    return e[o].mx;
  }
  int w = Where(o, x);
  if (Min(e[x].l[w]) != -1 && Pos(o, x) > Min(e[x].l[w])) {
    return Index(o, w, Pre(e[x].l[w], Pos(o, x)));
  }
  int pl = Pre(e[x].p, w);
  if (pl == -1) {
    return e[x].mi != -1 && x > e[x].mi ? e[x].mi : -1;
  }
  return Index(o, pl, Max(e[x].l[pl]));
}
void Insert(int o, int x) {
  if (e[o].mi == -1) {
    e[o].mi = e[o].mx = x;
    return;
  }
  if (x < e[o].mi) {
    swap(x, e[o].mi);
  }
  if (e[o].u > 2) {
    if (Min(e[o].l[Where(o, x)]) == -1) {
      Insert(e[o].p, Where(o, x));
    }
    Insert(e[o].l[Where(o, x)], Pos(o, x));
  }
  if (x > e[o].mx) {
    e[o].mx = x;
  }
}
void Delete(int o, int x) {
  if (e[o].mi == e[o].mx) {
    e[o].mi = e[o].mx = -1;
    return;
  }
  if (e[o].u == 2) {
    e[o].mi = e[o].mx = !x;
    return;
  }
  if (x == e[o].mi) {
    int fl = Min(e[o].p);
    e[o].mi = x = Index(o, fl, Min(e[o].l[fl]));
  }
  int w = Where(o, x), l = e[o].l[w];
  Delete(l, Pos(o, x));
  if (Min(l) == -1) {
    Delete(e[o].p, w);
    if (x == e[o].mx) {
      int ml = Max(e[o].p);
      e[o].mx = (ml == -1 ? e[o].mi : Index(o, ml, Max(e[o].l[ml])));
    }
  } else if (x == e[o].mx) {
    e[o].mx = Index(o, w, Max(l));
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  Init(kN << 1);
  cin >> n >> m;
  int u = 0;
  for (--n; n; n >>= 1, ++u) {
  }
  Build(r = ++t, u);
  while (m--) {
    cin >> o;
    if (o == 3) {
      cout << Min(r) << endl;
    } else if (o == 4) {
      cout << Max(r) << endl;
    } else {
      cin >> x;
      if (o == 1 && !Contains(r, x)) {
        Insert(r, x);
      } else if (o == 2 && Contains(r, x)) {
        Delete(r, x);
      } else if (o == 5) {
        cout << Pre(r, x) << endl;
      } else if (o == 6) {
        cout << Next(r, x) << endl;
      } else {
        cout << (Contains(r, x) ? 1 : -1) << endl;
      }
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}