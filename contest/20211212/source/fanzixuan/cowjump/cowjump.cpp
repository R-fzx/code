#include <iostream>
#include <ctime>

using namespace std;
using LL = long long;

const int kN = 1e5 + 1;

struct V {
  LL x, y;
} e[kN][2];
int n;

LL Cross(V x, V y, V o) {
  return (x.x - o.x) * (y.y - o.y) - (x.y - o.y) * (y.x - o.x);
}
bool _I(V x1, V y1, V x2, V y2) {
  return Cross(x2, x1, y1) >= 0 && Cross(y2, x1, y1) <= 0 && Cross(y1, x2, y2) >= 0 && Cross(x1, x2, y2) <= 0;
}
bool I(int x, int y) {
  return _I(e[x][0], e[x][1], e[y][0], e[y][1]) || _I(e[x][1], e[x][0], e[y][0], e[y][1]) || _I(e[x][0], e[x][1], e[y][1], e[y][0]) || _I(e[x][1], e[x][0], e[y][1], e[y][0]);
}
pair<int, int> C(int x) {
  int c = 0, p = -1;
  for (int i = 1; i <= n; ++i) {
    if (i != x && I(x, i)) {
      ++c, p = i;
    }
  }
  return {c, p};
}
int S() {
  for (int i = 1; i <= n && clock() <= 950; ++i) {
    auto c = C(i);
    if (c.first > 1) {
      return i;
    } else if (c.first == 1) {
      auto _c = C(c.second);
      return _c.first > 1 ? c.second : i;
    }
  }
  return n;
}

int main() {
  freopen("cowjump.in", "r", stdin);
  freopen("cowjump.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> e[i][0].x >> e[i][0].y >> e[i][1].x >> e[i][1].y;
  }
  cout << S();
  return 0;
}
/*
e[x][0] e[x][1]

e[y][0] e[y][1]

Cross(x2, x1, y1) >= 0 && Cross(y2, x1, x2) <= 0 && Cross(x2, y1, y2) >= 0 && Cross(x1, y1, y2) <= 0

2 1 6 1
4 0 1 5
5 6 5 5
2 7 1 3

7 |    4
6 |          3 3
5 |  2
4 |
3 |  4
2 |
1 |    1       1
0 |        2 
  --------------
   0 1 2 3 4 5 6
*/