# include <stdio.h>
# include <queue>
# define eps 1e-7
# define dis(x, y, z) make_pair(-(z), make_pair(x, y))
# define disnow [now.second.first][now.second.second]
# define disnext [now.second.first + fx[i]][now.second.second + fy[i]]
using namespace std;

int n, m, sx, sy, tx, ty;
char mp[110][110];
int vis[110][110], vt;
double l, v;
int fx[4] = {0, 0, -1, 1};
int fy[4] = {-1, 1, 0, 0};


double dij() {
  ++vt;
  priority_queue<pair<double, pair<int, int> > > q;
  q.push(dis(sx, sy, 0));
  while(q.size()) {
    pair<double, pair<int, int> > now = q.top();
    q.pop();
    // printf("%d %d\n", now.second.first, now.second.second);
    if (now.second.first == tx && now.second.second == ty) {
      return -now.first;
    }
    if (vis disnow == vt) {
      continue;
    }
    vis disnow = vt;
    for (int i = 0; i < 4; i++) {
      if (mp disnext != '#' && vis disnext != vt) {
        if (i >= 2) {
          q.push(dis(now.second.first + fx[i], now.second.second + fy[i], -now.first + v));
        } else {
          q.push(dis(now.second.first + fx[i], now.second.second + fy[i], -now.first + 1));
        }
      }
    }
  }
  return 114514.0;
}

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lf%d%d\n", &l, &n, &m);
    for (int i = 1; i <= n; i++) {
      gets(mp[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
      mp[i][0] = mp[i][m + 1] = '#';
    }
    for (int i = 1; i <= m; i++) {
      mp[0][i] = mp[n + 1][i] = '#';
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (mp[i][j] == 'S') {
          sx = i, sy = j;
        } else if(mp[i][j] == 'E') {
          tx = i, ty = j;
        }
      }
    }
    // printf("%d %d %d %d\n", sx, sy, tx, ty);
    // for (int i = 1; i <= n; i++) {
    //   printf("%s\n", mp[i] + 1);
    // }
    double min = 0.0, max = 10.1;
    while (max - min > eps) {
      v = (min + max) / 2;
      // printf("%lf, %lf\n", v, dij());
      if (dij() > l) {
        max = v;
      } else {
        min = v;
      }
    }
    printf("%.5f\n", (min + max) / 2);
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

*/


