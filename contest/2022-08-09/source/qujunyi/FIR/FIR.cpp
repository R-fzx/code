#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int p = 0;
int b[1005][1005];
vector<pair<int, int> > v[1005];
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, -1, 1, 1, -1, -1, 1};
void dfs(int x, int y, int z) {
  b[x][y] = p;
  v[p].push_back(make_pair(x, y));
  for (int i = 0; i < 4; i++) {
    int sx = x + dx[i], sy = y + dy[i];
    if (a[sx][sy] == z && b[sx][sy] != b[x][y]) {
      dfs(sx, sy, z);
    }
  }
}
bool check(int x) {
  bool s = 0;
  for (int i = 0; i < v[x].size(); i++) {
    for (int j = 0; j < 4; j++) {
      int sx = v[x][i].first + dx[j], sy = v[x][i].second + dy[j];
      if (a[sx][sy] == 0) {
        s = 1;
      }
    }
  }
  return s;
}
int main() {
  freopen("FIR.in","r",stdin);
  freopen("FIR.out","w",stdout);
  int n, m;
  cin >> n >> m;
  for (int w = 1; w <= n; w++) {
    int x, y;
    cin >> x >> y;
    if (a[x][y] != 0) {
      cout << "illegal";
      return 0;
    }
    a[x][y] = (w % 2) + 1;
    int s = (w % 2) + 1;
    if (s == 1) {
      s = 2;
    } else {
      s = 1;
    }
    ++p;
    dfs(x, y, a[x][y]);
    for (int i = 0; i < 4; i++) {
      int sx = x + dx[i], sy = y + dy[i];
      if (a[sx][sy] == s) {
        int ss = b[sx][sy];
        if (!check(ss)) {
          for (int j = 0; j < v[ss].size(); j++) {
            a[v[ss][j].first][v[ss][j].second] = 0;
          }
        }
      }
    }
    if (!check(p)) {
      cout << "illegal";
      return 0;
    }
    for (int i = 0; i < 8; i += 2) {
      int xx = x, yy = y;
      int sum = 0;
      while (a[xx][yy] == a[x][y]) {
        xx += dx[i], yy += dy[i];
        sum++;
      }
      xx = x + dx[i + 1], yy = y + dy[i + 1];
      while (a[xx][yy] == a[x][y]) {
        xx += dx[i + 1], yy += dy[i + 1];
        sum++;
      }
      if (sum >= m) {
        if (a[x][y] == 2) {
          cout << "ITer " << w << endl;
        } else {
          cout << "Kitty " << w << endl;
        }
        return 0;
      }
    }
  }
  cout << "draw";
}
