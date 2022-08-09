#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kN = 1002, kD[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, kW[4][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}};

int n, m, a[kN][kN], b[kN][kN], t;
vector<Pii> l;

bool D(int x, int y, int v) {
  if (a[x][y] != v) {
    return !a[x][y];
  }
  if (b[x][y] == t) {
    return 0;
  }
  b[x][y] = t, l.emplace_back(x, y);
  for (int i = 0; i < 4; ++i) {
    if (D(x + kD[i][0], y + kD[i][1], v)) {
      return 1;
    }
  }
  return 0;
}
int C(int x, int y, int dx, int dy) {
  int c = 0;
  for (int i = x, j = y; c < m && a[i][j] == a[x][y]; ++c, i += dx, j += dy) {
  }
  return c;
}

int main() {
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
  RF("FIR");
  cin >> n >> m;
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    if (a[x][y]) {
      cout << "illegal";
      return 0;
    }
    a[x][y] = i % 2 + 1;
    for (int j = 0; j < 4; ++j) {
      ++t, l.clear();
      int nx = x + kD[j][0], ny = y + kD[j][1];
      if (a[nx][ny] == 3 - a[x][y] && !D(nx, ny, a[nx][ny])) {
        for (Pii &k : l) {
          a[k.first][k.second] = 0;
        }
      }
    }
    ++t, l.clear();
    if (!D(x, y, a[x][y])) {
      cout << "illegal";
      return 0;
    }
    for (int j = 0; j < 4; ++j) {
      if (C(x, y, kW[j][0], kW[j][1]) + C(x, y, -kW[j][0], -kW[j][1]) - 1 >= m) {
        cout << (i % 2 ? "ITer" : "Kitty") << ' ' << i;
        return 0;
      }
    }
  }
  cout << "draw";
  return 0;
}