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
  double s, s2, a;
} e[kN << 2];
int n, q, o, l, r;
double a[kN], k;

void PushUp(int x) { e[x].s = e[x * 2].s + e[x * 2 + 1].s, e[x].s2 = e[x * 2].s2 + e[x * 2 + 1].s2; }
void Build(int x, int l, int r) {
  if (l == r) {
    e[x].s = a[l], e[x].s2 = a[l] * a[l];
    return;
  }
  int m = l + r >> 1;
  Build(x * 2, l, m), Build(x * 2 + 1, m + 1, r), PushUp(x);
}
void Add(int x, double v, int l, int r) { e[x].s2 += v * (2 * e[x].s + (r - l + 1) * v), e[x].s += v * (r - l + 1), e[x].a += v; }
double Do(int x, int l, int r, int tl, int tr, double v, int ty) {
  if (l == tl && r == tr) {
    Add(x, v, l, r);
    return (ty ? e[x].s2 : e[x].s);
  }
  int m = l + r >> 1;
  double s = 0;
  Add(x * 2, e[x].a, l, m), Add(x * 2 + 1, e[x].a, m + 1, r), e[x].a = 0;
  if (tl <= m) {
    s += Do(x * 2, l, m, tl, min(tr, m), v, ty);
  }
  if (m < tr) {
    s += Do(x * 2 + 1, m + 1, r, max(tl, m + 1), tr, v, ty);
  }
  PushUp(x);
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(4);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  Build(1, 1, n);
  while (q--) {
    cin >> o >> l >> r;
    if (o == 1) {
      cin >> k;
      Do(1, 1, n, l, r, k, 0);
    } else if (o == 2) {
      cout << Do(1, 1, n, l, r, 0, 0) / (r - l + 1) << endl;
    } else {
      double m = Do(1, 1, n, l, r, 0, 0) / (r - l + 1);
      cout << ((r - l + 1) * m * m + (Do(1, 1, n, l, r, 0, 1) - 2 * m * Do(1, 1, n, l, r, 0, 0))) / (r - l + 1) << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}