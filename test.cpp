#include <iostream>
#include <queue>

using namespace std;

const int kN = 1e3 + 1;

struct Q {
  int x, y, t, d;

  bool operator<(const Q &o) const { return d > o.d; }
};
priority_queue<Q> q;
int t, n, m, d[kN][kN][2];
bool a[kN][kN];

void R(int x, int y, int t, int _d) {
  if (x >= 1 && x <= n && y >= 1 && y <= m) {
    if (a[x][y]) {
      t = 1;
    } else if (t) {
      t = 0, ++_d;
    }
    if (d[x][y][t] > _d) {
      d[x][y][t] = _d, q.push({x, y, t, _d});
    }
  }
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cin >> a[i][j];
        d[i][j][0] = d[i][j][1] = 1e9;
      }
    }
    for (R(1, 1, 0, 0); !q.empty(); ) {
      Q x = q.top();
      q.pop();
      for (int i = 0; i < 2; ++i) {
        R(x.x + i, x.y + !i, x.t, x.d);
      }
    }
    cout << min(d[n][m][0], d[n][m][1] + 1) << '\n';
  }
  return 0;
}