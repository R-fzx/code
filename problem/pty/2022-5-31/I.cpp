#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using mL = modint998244353;

const int kN = 1501, kL[2] = {-1, 1};

struct E {
  int x, y, f;
};
int n, sx, sy, tx, ty, d[kN][kN][5];
char a[kN][kN];
deque<E> q;

void R(int x, int y, int _d, int f, int pf) {
  bool _f = f != pf;
  if (d[x][y][f] > _d + _f) {
    d[x][y][f] = _d + _f, (_f ? q.push_back({x, y, f}) : q.push_front({x, y, f}));
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> sx >> sy >> tx >> ty;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] + 1;
  }
  fill(&d[1][1][0], &d[n][n][4] + 1, 1e9);
  for (R(sx, sy, 0, 4, 4); !q.empty(); ) {
    E x = q.front();
    q.pop_front();
    for (int k = 0; k < 4; ++k) {
      int nx = x.x + kL[k & 1], ny = x.y + kL[k >> 1];
      if (min(nx, ny) >= 1 && max(nx, ny) <= n && a[nx][ny] != '#') {
        R(nx, ny, d[x.x][x.y][x.f], k, x.f);
      }
    }
  }
  int m = 1e9;
  for (int k = 0; k < 5; ++k) {
    m = min(m, d[tx][ty][k]);
  }
  cout << (m == 1e9 ? -1 : m);
  return 0;
}