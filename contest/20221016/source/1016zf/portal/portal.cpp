#include <bits/stdc++.h>

using namespace std;

const int N = 505, inf = 25000;

int n, m, t, bx, by, ex, ey, ans = inf;
int dir[5][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int vis[N][N];
char mp[N][N];

void dfs(int x, int y, int t) {
  if (t >= ans || x < 1 || y < 1 || x > n || y > m) {
    return;
  }
  if (x == ex && y == ey) {
    ans = min(ans, t);
    return;
  }
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0], ny = y + dir[i][1], nnx, nny;
    if (mp[nx][ny] != '#' && !vis[nx][ny]) {
      nnx = nx, nny = ny;
      while (mp[nnx + dir[i][0]][nny + dir[i][1]] != '#') {
        nnx += dir[i][0], nny += dir[i][1];
      }
      if (!vis[nnx][nny]) {
        dfs(nnx, nny, t + 1);
      }
      dfs(nx, ny, t + 1);
    }
  }
  vis[x][y] = 0;
}

int main() {
  freopen("portal.in", "r", stdin);
  freopen("portal.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mp[i][j];
      if (mp[i][j] == 'C') {
        bx = i, by = j;
      } else if (mp[i][j] == 'F') {
        ex = i, ey = j;
      }
    }
  }
  dfs(bx, by, 0);
  if (ans == inf) {
    cout << "nemoguce";
  } else {
    cout << ans;
  }
  return 0;
}