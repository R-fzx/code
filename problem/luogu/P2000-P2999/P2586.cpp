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
#define _DEBUG
#ifdef _DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 9, kD[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct P {
  int x, y;
};
struct A {
  int a, l, h, mh, x, y, px, py;
  bool k;
};
int n, m, a[kN][kN], s, d, r, t, tac, tg = -1, nc;
bool v[kN][kN];
vector<A> l;
vector<P> p;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> s >> d >> r;
  for (int i = 1, x, y; i <= s; ++i) {
    cin >> x >> y;
    p.push_back({x, y}), v[x][y] = 1;
  }
  cin >> t;
  for (int nt = 1; nt <= t; ++nt) {
    debug("Time %d\n", nt);
    if (!v[0][0] && nc < 6) {
      debug("New Ant\n");
      v[0][0] = 1;
      l.push_back({1, tac++ / 6 + 1, 0, 0, 0, 0, 0, 0, 0});
      A &x = l.back();
      x.mh = x.h = 4 * pow(1.1, x.l);
    }
    for (A &i : l) {
      a[i.x][i.y] += 2 + 3 * i.k;
    }
    for (A &i : l) {
      bitset<4> b;
      int mx = -1;
      for (int d = 0; d < 4; ++d) {
        int nx = i.x + kD[d][0], ny = i.y + kD[d][1];
        if (nx < 0 || nx > n || ny < 0 || ny > m || v[nx][ny] || nx == i.px && ny == i.py) {
          continue;
        }
        b[d] = 1, mx = max(mx, a[nx][ny]);
      }
      if (~mx) {
        int d;
        for (d = 0; d < 4; ++d) {
          int nx = i.x + kD[d][0], ny = i.y + kD[d][1];
          if (b[d] && a[nx][ny] == mx) {
            break;
          }
        }
        if (i.a % 5 == 0) {
          while (!b[d = (d + 3) % 4]) {
          }
        }
        v[i.px = i.x][i.py = i.y] = 0, v[i.x += kD[d][0]][i.y += kD[d][1]] = 1;
      } else {
        i.px = i.x, i.py = i.y;
      }
    }
    for (int i = 0; i < l.size(); ++i) {
      if (l[i].x == n && l[i].y == m && !~tg) {
        tg = i, l[i].k = 1, l[i].h = min(l[i].mh, l[i].h + l[i].mh / 2);
      }
    }
    for (P i : p) {
      // TODO: Attack
    }
    nc = 0;
    for (int i = 0; i < l.size(); ++i) {
      if (l[i].h < 0) {
        if (tg == i) {
          tg = -1;
        }
        l.erase(l.begin() + i);
      } else {
        ++nc;
      }
    }
    if (~tg && !l[tg].x && !l[tg].y) {
      printf("Game over after %d seconds\n%llu\n", nt, l.size());
      for (A &i : l) {
        printf("%d %d %d %d %d\n", i.a, i.l, i.h, i.x, i.y);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        a[i][j] = max(0, a[i][j] - 1);
      }
    }
    for (A &i : l) {
      i.a += i.h >= 0;
    }
  }
  printf("The game is going on\n%llu\n", l.size());
  for (A &i : l) {
    printf("%d %d %d %d %d\n", i.a - 1, i.l, i.h, i.x, i.y);
  }
  return 0;
}
/*
time=1:
age=1
move
age=2
time=2:
age=2
move
age=3
*/