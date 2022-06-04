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

const int kN = 2e5 + 1;

int n, q, a[kN], x, y, e[kN << 2];
char o;

void Build(int x, int l, int r) {
  if (l == r) {
    e[x] = a[l];
    return;
  }
  int m = l + r >> 1;
  Build(x * 2, l, m), Build(x * 2 + 1, m + 1, r), e[x] = max(e[x * 2], e[x * 2 + 1]);
}
int Do(int x, int l, int r, int tl, int tr, int v) {
  if (l == tl && r == tr) {
    e[x] = max(e[x], v);
    return e[x];
  }
  int m = l + r >> 1, s = INT32_MIN;
  if (tl <= m) {
    s = max(s, Do(x * 2, l, m, tl, min(m, tr), v));
  }
  if (m < tr) {
    s = max(s, Do(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, v));
  }
  e[x] = max(e[x * 2], e[x * 2 + 1]);
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  Build(1, 1, n);
  while (q--) {
    cin >> o >> x >> y;
    if (o == 'U') {
      Do(1, 1, n, x, x, y);
    } else {
      cout << Do(1, 1, n, x, y, INT32_MIN) << '\n';
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}