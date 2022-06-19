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

const int kN = 101, kK = 11, kD[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct E {
  int x, y, k;
  LL w;
  bool operator<(const E& o) const { return w > o.w; }
};
int n, k;
LL a, b, c, d[kN][kN][kK];
vector<E> e[kN][kN][kK];
priority_queue<E> q;

void R(int x, int y, int k, LL _d) {
  if (d[x][y][k] > _d) {
    d[x][y][k] = _d, q.push({x, y, k, _d});
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> a >> b >> c;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, v; j <= n; ++j) {
      cin >> v;
      for (int k = 0; k <= ::k; ++k) {
        for (int u = 0; u < 4; ++u) {
          int x = i + kD[u][0], y = j + kD[u][1];
          if (x >= 1 && x <= n && y >= 1 && y <= n) {
            e[i][j][k].push_back({x, y, (v || !k ? ::k : k) - 1, (v || !k) * a + (u > 1) * b + (!v && !k) * c});
          }
        }
      }
    }
  }
  fill(&d[1][1][0], &d[n][n][k] + 1, 1e18);
  for (R(1, 1, k, 0); !q.empty();) {
    E e = q.top();
    q.pop();
    for (E& i : ::e[e.x][e.y][e.k]) {
      R(i.x, i.y, i.k, d[e.x][e.y][e.k] + i.w);
    }
  }
  for (int k = 0; k <= ::k; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        debug("%lld ", d[i][j][k]);
      }
      debug("\n");
    }
    debug("\n");
  }
  LL ans = 1e18;
  for (int i = 0; i <= k; ++i) {
    ans = min(ans, d[n][n][i]);
  }
  cout << ans;
  return 0;
}