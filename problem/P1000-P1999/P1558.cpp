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

const int kN = 1e5 + 1, kT = 31;

struct E {
  int s = 1, a = -1;
} e[kN << 2];
int n, t, q, l, r, c;
char o;

void Build(int x, int l, int r) {
  if (l == r) {
    return;
  }
  int m = l + r >> 1;
  Build(x * 2, l, m), Build(x * 2 + 1, m + 1, r);
  e[x].s = e[x * 2].s | e[x * 2 + 1].s;
}
void Set(int x, int v) { ~v && (e[x].s = v, e[x].a = v); }
int Do(int x, int l, int r, int tl, int tr, int v) {
  if (l == tl && r == tr) {
    Set(x, v);
    return e[x].s;
  }
  Set(x * 2, e[x].a), Set(x * 2 + 1, e[x].a), e[x].a = -1;
  int m = l + r >> 1, s = 0;
  if (tl <= m) {
    s |= Do(x * 2, l, m, tl, min(tr, m), v);
  }
  if (tr > m) {
    s |= Do(x * 2 + 1, m + 1, r, max(tl, m + 1), tr, v);
  }
  e[x].s = e[x * 2].s | e[x * 2 + 1].s;
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> t >> q;
  Build(1, 1, n);
  while (q--) {
    cin >> o >> l >> r;
    if (l > r) {
      swap(l, r);
    }
    if (o == 'C') {
      cin >> c;
      Do(1, 1, n, l, r, 1 << c - 1);
    } else {
      cout << bitset<kT>(Do(1, 1, n, l, r, -1)).count() << '\n';
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}