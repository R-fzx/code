#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

const int N = 105;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct NODE {
  int vis, t;
  int z;
} dp[N][N];

struct NODE2 {
  int x, y, t;
};

int r, c, stx, sty, lx, ly, t;
double l;
char map[N][N];
queue<NODE2> q;

inline void Becord(int x, int y, int step) {
  // cout << x << ' ' << y << '\n';
  if (x < 1 || y < 1 || x > r || y > c || dp[x][y].vis || map[x][y] == '#') {
    return ;
  }
  dp[x][y].vis = 1;
  dp[x][y].t = step;
  NODE2 u = {x, y, step};
  q.push(u);
}

inline void bfs() {
  Becord(stx, sty, 0);
  while (!q.empty()) {
    NODE2 u = q.front();
    q.pop();
    for (int i = 0; i < 4; ++ i) {
      Becord(u.x + dx[i], u.y + dy[i], u.t + 1);
      if (dx[i]) {
        dp[u.x + dx[i]][u.y + dy[i]].z = dp[u.x][u.y].z + 1;
      } else {
        dp[u.x + dx[i]][u.y + dy[i]].z = dp[u.x][u.y].z;
      }
    }
  }
}

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  cin >> t;
  while (t--) { 
    cin >> l >> r >> c;
    // cout << c;
    for (int i = 1; i <= r; ++i) {
      char ch = getchar();
      for (int j = 1; j <= c; ++j) {
        map[i][j] = getchar();
        if (map[i][j] == 'S') {
          stx = i, sty = j;
        } else if (map[i][j] == 'E') {
          lx = i, ly = j;
        }
      }
    }
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        // cout << dp[i][j].t << ' ';
        dp[i][j].t = dp[i][j].vis = dp[i][j].z = 0;
      }
      // cout << '\n';
    }
    bfs();
    // cout << stx << ' ' << sty << '\n';
    // cout << lx << ' ' << ly << '\n';
    // cout << dp[lx][ly].z << ' ' << dp[lx][ly].t << '\n';
    double t = l - dp[lx][ly].t + dp[lx][ly].z;
    double v = t * 1.0 / dp[lx][ly].z;
    printf("%.5lf\n", v);
  }
}
/*
2
2.5 4 5
#####
#S  #
#  E#
#####
21 13 12
############
#S##     #E#
# ##  #  # #
#   # #  # #
### # #  # #
#   # #  # #
#  ## #  # #
##  # #  # #
### # #  # #
##  # #  # #
#  ## #    #
#     #    #
############
37*/