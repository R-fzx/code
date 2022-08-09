// 暴力
#include <iostream>
#include <vector>

using namespace std;

long long map[21][21];
int n, m;
long long X;
long long Find(int x, int y, int num) {
  if (y > m || x > n || map[x][y] == 0) {
    return 0;
  }
  num ^= map[x][y];
  if (x == n && y == m) {
    return num == X;
  }
  return Find(x + 1, y, num) + Find(x, y + 1, num);
}

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  cin >> n >> m >> X;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> map[i][j];
    }
  }
  cout << Find(1, 1, 0);
  return 0;
}