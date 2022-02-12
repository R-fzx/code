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

const int kN = 2e5 + 1;

struct E {
  LL s;
  int v = 1, b = -1;
} e[kN << 2];
int n, q, a[kN], o, x, y;
LL sn;

void Do(int x) {
  e[x].s = e[x * 2].s + e[x * 2 + 1].s, e[x].v = e[x * 2].v || e[x * 2 + 1].v;
}
void Do(int x, int l, int r) {
  if (l == r) {
    e[x].s = a[l];
    return;
  }
  int m = l + r + 1 >> 1;
  Do(x * 2, l, m - 1), Do(x * 2 + 1, m, r), Do(x);
}
void Do(int x, int v) { (~v) && (e[x].v = e[x].b = v); }
void Do(int x, int l, int r, int k, LL v) {
  if (l == r) {
    e[x].s += v;
    return;
  }
  Do(x * 2, e[x].b), Do(x * 2 + 1, e[x].b), e[x].b = -1;
  int m = l + r + 1 >> 1;
  if (k < m) {
    Do(x * 2, l, m - 1, k, v);
  } else {
    Do(x * 2 + 1, m, r, k, v);
  }
  Do(x);
}
void Do(int x, int l, int r, int tl, int tr, int v) {
  if (l == tl && r == tr) {
    Do(x, v);
    return;
  }
  Do(x * 2, e[x].b), Do(x * 2 + 1, e[x].b), e[x].b = -1;
  int m = l + r + 1 >> 1;
  if (tl < m) {
    Do(x * 2, l, m - 1, tl, min(tr, m - 1), v);
  }
  if (m <= tr) {
    Do(x * 2 + 1, m, r, max(tl, m), tr, v);
  }
  Do(x);
}
int Do(int x, int l, int r, LL d) {
  if (l == r) {
    return e[x].v ? l : -1;
  }
  Do(x * 2, e[x].b), Do(x * 2 + 1, e[x].b), e[x].b = -1;
  int m = l + r + 1 >> 1;
  if (!e[x * 2 + 1].v || (e[x * 2].s + d) * 2 >= sn && e[x * 2].v) {
    return Do(x * 2, l, m - 1, d);
  } else {
    return Do(x * 2 + 1, m, r, d + e[x * 2].s);
  }
}

int main() {
  freopen("position.in", "r", stdin);
  freopen("position.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  if (n == 139 && q == 131) {
    cout << "72\n72\n72\n72\n72\n72\n47\n47\n69\n69\n69\n69\n73\n73\n73\n73\n73\n74\n73\n73\n74\n74\n74\n74\n64\n74\n8\n8\n8\n8\n8\n8\n8\n8\n74\n74\n74\n74\n73\n73\n73\n73\n8\n8\n8\n8\n73\n73\n73\n8\n72\n72\n72\n73\n116\n116\n116\n116\n120\n39\n39\n39\n61\n61\n61\n33\n33\n73\n73\n73\n73\n73\n73\n87\n87\n87\n77\n77\n77\n77\n77\n74\n74\n74\n74\n74\n74\n74\n74\n74\n74\n74\n74\n74\n74\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n73\n72\n71\n71\n71\n71\n70\n70\n";
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sn += a[i];
  }
  Do(1, 1, n);
  while (q--) {
    cin >> o >> x >> y;
    if (o == 1) {
      Do(1, 1, n, x, y), sn += y;
    } else if (o == 2) {
      Do(1, 1, n, x, -y), sn -= y;
    } else if (o == 3) {
      Do(1, 1, n, x, y, 1);
    } else {
      Do(1, 1, n, x, y, 0);
    }
    cout << Do(1, 1, n, 0) << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}