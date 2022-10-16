#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

const int N = 501, D[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m, a[N][N], cx, cy, fx, fy, f[N][N];
pii d[N][N][4];
char c;
queue<pii> q;

void R(int x, int y, int d) {
  if (a[x][y] || f[x][y] <= d) {
    return;
  }
  f[x][y] = d;
  q.push({x, y});
}

int main() {
  freopen("portal.in", "r", stdin);
  freopen("portal.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> c;
      a[i][j] = c == '#';
      if (c == 'C') {
        cx = i, cy = j;
      }
      if (c == 'F') {
        fx = i, fy = j;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    int l = 0;
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) {
        for (int k = l + 1; k < j; ++k) {
          d[i][k][0] = {i, j - 1}, d[i][k][1] = {i, l + 1};
        }
        l = j;
      }
    }
  }
  for (int j = 1; j <= m; ++j) {
    int l = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i][j]) {
        for (int k = l + 1; k < i; ++k) {
          d[k][j][2] = {i - 1, j}, d[k][j][3] = {l + 1, j};
        }
        l = i;
      }
    }
  }
  fill(f[0], f[n + 1], 1e9);
  for (R(cx, cy, 0); !q.empty();) {
    pii p = q.front();
    q.pop();
    if (p.first == fx && p.second == fy) {
      cout << f[p.first][p.second];
      return 0;
    }
    for (int i = 0; i < 4; ++i) {
      R(p.first + D[i][0], p.second + D[i][1], f[p.first][p.second] + 1);
    }
    for (int i = 0; i < 4; ++i) {
      if (a[p.first + D[i][0]][p.second + D[i][1]]) {
        for (int j = 0; j < 4; ++j) {
          R(d[p.first][p.second][j].first, d[p.first][p.second][j].second, f[p.first][p.second] + 1);
        }
      }
    }
  }
  cout << "nemoguce";
  return 0;
}