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
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1;

struct E {
  LL s;
  bool v;
} e[kN << 2];
int n, q, o, l, r;
LL a[kN];

void Build(int x, int l, int r) {
  if (l == r) {
    e[x].s = a[l], e[x].v = a[l] > 1;
    return;
  }
  int m = l + r >> 1;
  Build(x * 2, l, m), Build(x * 2 + 1, m + 1, r);
  e[x].s = e[x * 2].s + e[x * 2 + 1].s, e[x].v = e[x * 2].v | e[x * 2 + 1].v;
}
void Sqrt(int x, int l, int r) {
  if (l == r) {
    e[x].s = sqrt(e[x].s), e[x].v = e[x].s > 1;
    return;
  }
  int m = l + r >> 1;
  Sqrt(x * 2, l, m), Sqrt(x * 2 + 1, m + 1, r);
  e[x].s = e[x * 2].s + e[x * 2 + 1].s, e[x].v = e[x * 2].v | e[x * 2 + 1].v;
}
LL Do(int x, int l, int r, int tl, int tr, int ty) {
  if (l == tl && r == tr) {
    if (ty) {
      return e[x].s;
    } else {
      if (e[x].v) {
        Sqrt(x, l, r);
      }
      return 0;
    }
  }
  int m = l + r >> 1;
  LL s = 0;
  if (tl <= m) {
    s += Do(x * 2, l, m, tl, min(tr, m), ty);
  }
  if (tr > m) {
    s += Do(x * 2 + 1, m + 1, r, max(tl, m + 1), tr, ty);
  }
  e[x].s = e[x * 2].s + e[x * 2 + 1].s, e[x].v = e[x * 2].v | e[x * 2 + 1].v;
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  Build(1, 1, n);
  cin >> q;
  while (q--) {
    cin >> o >> l >> r;
    if (l > r) {
      swap(l, r);
    }
    LL s = Do(1, 1, n, l, r, o);
    if (o) {
      cout << s << '\n';
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}