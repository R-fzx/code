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

const int kN = 201, kM = 10001;

struct E {
  int y, n;
  LL w;
} e[kM];
struct V {
  int h, d, c;
} a[kN];
int n, m, s, t, c = 1, _h, _t, q[kN];
LL ans;

void A(int x, int y, LL w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
void R(int x, int d) {
  if (!a[x].d) {
    a[x].d = d, q[++_t] = x;
  }
}
bool B() {
  for (int i = 1; i <= n; ++i) {
    a[i].d = 0, a[i].c = a[i].h;
  }
  for (_h = 1, _t = 0, R(s, 1); _h <= _t; ++_h) {
    int x = q[_h];
    for (int i = a[x].h; i; i = e[i].n) {
      if (e[i].w) {
        R(e[i].y, a[x].d + 1);
        if (e[i].y == t) {
          return 1;
        }
      }
    }
  }
  return 0;
}
LL D(int x, LL b) {
  if (x == t) {
    return b;
  }
  LL r = b;
  for (int &i = a[x].c; i && b; b && (i = e[i].n)) {
    if (e[i].w && a[e[i].y].d == a[x].d + 1) {
      LL w = D(e[i].y, min(b, e[i].w));
      e[i].w -= w, e[i ^ 1].w += w, b -= w;
    }
  }
  return r - b;
}

int main() {
  // freopen("P3376.in", "r", stdin);
  // freopen("P3376.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> s >> t;
  for (int i = 1, x, y, d; i <= m; ++i) {
    cin >> x >> y >> d;
    A(x, y, d), A(y, x, 0);
  }
  for (; B(); ans += D(s, 1e18)) {
  }
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}