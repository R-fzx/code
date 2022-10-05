#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

char a[MAXN][MAXN];
int dis[MAXN][MAXN];

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int n;
pair<int, int> s;

struct Node {
  int x, y, d;
  bool operator>(const Node &xx) const {
    return d < xx.d;
  }
  bool operator<(const Node &xx) const {
    return d > xx.d;
  }
};

void dij(int v) {
  priority_queue<Node> q;
  q.push({s.first, s.second, 0});
  while (!q.empty()) {
    Node x = q.top();
    if (a[x.x][x.y] == '*') {
      return;
    }
    q.pop();
    int nx, ny, nd;
    for (int i = 0; i < 8; ++i) {
      nx = x.x + dx[i], ny = x.y + dy[i], nd = x.d + (i == v ? 3 : 1);
      if (min(nx, ny) > -1 && max(nx, ny) < n && a[nx][ny] != 'X' && nd < dis[nx][ny]) {
        dis[nx][ny] = nd;
        q.push({nx, ny, nd});
      }
    }
  }
}

int main() {
  freopen("desert.in", "r", stdin);
  freopen("desert.out", "w", stdout);
  int ans = -1145141919;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      if (a[i][j] == '@') {
        s = {i, j};
      }
      dis[i][j] = 1145141919;
    }
  }
  for (int i = 0; i < 8; ++i) {
    dij(i);
    int minn = 1145141919;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (a[j][k] == '*' && minn > dis[j][k]) {
          minn = dis[j][k];
        }
        dis[j][k] = 1145141919;
      }
    }
    if (minn > ans) ans = minn;
  }
  cout << ans;
  return 0;
}