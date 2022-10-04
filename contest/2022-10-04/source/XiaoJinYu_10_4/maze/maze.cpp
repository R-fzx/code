#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

bool f[MAXN][MAXN];

pair<int, int> vis[MAXN][MAXN], s, e;

int n, m;
double l;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int cx, int cy, long double v) {
  if (min(x, y) < 0 || x >= n || y >= m || f[x][y] || cx * v + cy >= vis[x][y].first * v + vis[x][y].second) {
    return;
  }
  vis[x][y] = {cx, cy};
  int nx, ny, dcx, dcy;
  for (int i = 0; i < 4; ++i) {
    nx = x + dx[i], ny = y + dy[i];
    dcx = i < 2, dcy = i > 1;
    dfs(nx, ny, cx + dcx, cy + dcy, v);
  }
}

void _dfs(long double &v) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      vis[i][j] = {1145141919, 1145141919};
    }
  }
  dfs(s.first, s.second, 0, 0, v);
}

long double check(long double v) {
  _dfs(v);
  return vis[e.first][e.second].first * v + vis[e.first][e.second].second;
}

bool check2(long double x, long double y) {
  _dfs(x);
  pair<int, int> vx = vis[e.first][e.second];
  _dfs(y);
  return vis[e.first][e.second] == vx;
}

void getans(long double v) {
  _dfs(v);
  double ans = (l - vis[e.first][e.second].second) / vis[e.first][e.second].first;
  printf("%.5lf\n", ans);
}

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  int t;
  cin >> t;
  string s1;
  while (t--) {
    cin >> l >> n >> m;
    getline(cin, s1);
    for (int i = 0; i < n; ++i) {
      getline(cin, s1);
      for (int j = 0; j < m; ++j) {
        vis[i][j] = {1145141919, 1145141919};
        if (s1[j] == '#') {
          f[i][j] = 1;
        } else {
          f[i][j] = 0;
          if (s1[j] == 'S') {
            s = {i, j};
          } else if (s1[j] == 'E') {
            e = {i, j};
          }
        }
      }
    }
    long double le = 0, ri = 10;
    while (le + 0.000001 < ri && check2(le, ri)) {
      long double mid = (le + ri) / 2;
      if (check(mid) < l) {
        le = mid;
      } else {
        ri = mid;
      }
    }
    // cout << vis[e.first][e.second].first << ' ' << vis[e.first][e.second].second << '\n';
    getans(ri);
  }
  return 0;
}