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
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 11, kD[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Q {
  int x, y, v;
  LL d;
};
int n, m, p, k, s, a[kN][kN][4], b[kN][kN];
LL d[kN][kN][1 << kN];
queue<Q> q;

void R(int x, int y, int v, LL _d) {
  if (x >= 1 && x <= n && y >= 1 && y <= m) {
    v |= b[x][y];
    if (!d[x][y][v]) {
      d[x][y][v] = _d, q.push({x, y, v, _d});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> p >> k;
  for (int i = 1, x1, y1, x2, y2, g; i <= k; ++i) {
    cin >> x1 >> y1 >> x2 >> y2 >> g;
    for (int k = 0; k < 4; ++k) {
      if (x1 + kD[k][0] == x2 && y1 + kD[k][1] == y2) {
        a[x1][y1][k] = g - !g;
      }
      if (x2 + kD[k][0] == x1 && y2 + kD[k][1] == y1) {
        a[x2][y2][k] = g - !g;
      }
    }
  }
  cin >> s;
  for (int i = 1, x, y, g; i <= s; ++i) {
    cin >> x >> y >> g;
    b[x][y] |= 1 << g;
  }
  for (R(1, 1, 0, 1); !q.empty();) {
    Q x = q.front();
    debug("%d %d %d %d\n", x.x, x.y, x.v, x.d);
    q.pop();
    for (int k = 0; k < 4; ++k) {
      if (!a[x.x][x.y][k] || ~a[x.x][x.y][k] && (x.v >> a[x.x][x.y][k] & 1)) {
        R(x.x + kD[k][0], x.y + kD[k][1], x.v, x.d + 1);
      }
    }
  }
  debug("awa\n");
  LL ans = 1e18;
  for (int i = 0; i < 1 << p + 1; ++i) {
    if (d[n][m][i]) {
      ans = min(ans, d[n][m][i]);
    }
  }
  cout << (ans == 1e18 ? -1 : ans - 1);
  return 0;
}