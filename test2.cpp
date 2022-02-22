#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans;
int dx[] = {0, 1, -1, 0, 0}, dy[] = {0, 0, 0, 1, -1};
bool vis[15][15];
void Dfs(int x, int y) {
  if (x < 1 || x >= n || y < 1 || y >= m)
    ans++;
  else {
    vis[x][y] = 1;
    for (int i = 1; i <= 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (!vis[nx][ny]) Dfs(nx, ny);
    }
    vis[x][y] = 0;
  }
}
int main() {
  // freopen("1.txt", "r", stdin);
  freopen("ans2.txt", "w", stdout);
  for (int _n = 1; _n <= 7; ++_n) {
    for (int _m = 1; _m <= 8; ++_m) {
      n = _n, m = _m;
      ans = 0;
      for (int i = 1; i < n; i++) {
        memset(vis, 0, sizeof(vis));
        vis[i][0] = 1;
        Dfs(i, 1);
      }
      for (int i = 1; i < m; i++) {
        memset(vis, 0, sizeof(vis));
        vis[0][i] = 1;
        Dfs(1, i);
      }
      printf("t[%d][%d]=%lld;\n", n, m, ans * 2);
    }
  }
  return 0;
}
