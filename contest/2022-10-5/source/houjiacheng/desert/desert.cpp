# include <bits/stdc++.h>
# define inf 0x3f3f3f3f
# define Dis [x + fx[i]][y + fy[i]]

using namespace std;

int dis[100][100];
char mp[100][100];
char s[10000];
bool vis[100][100];
char in[10];
int fx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int fy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, sk;

priority_queue <pair<int, pair<int, int> > > q;

void Push(int x, int y) {
  int mink = 0;
  for (int i = 1; i < 8; i++) {
    if (dis Dis < dis[x + fx[mink]][y + fy[mink]]) {
      mink = i;
    }
  }
  int minv = dis[x + fx[mink]][y + fy[mink]] + 3;
  for (int i = 0; i < 8; i++) {
    if (i != mink && dis Dis + 1 < minv) {
      minv = dis Dis + 1;
    }
  }
  q.push(make_pair(-minv, make_pair(x, y)));
}

int main() {
  freopen("desert.in", "r", stdin);
  freopen("desert.out", "w", stdout);
  scanf("%d", &n);
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     scanf("%s", in);
  //     mp[i][j] = in[0];
  //   }
  // }
  while (~scanf("%s", in)) {
    s[++sk] = in[0];
  }
  m = sk / n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      mp[i][j] = s[(i - 1) * m + j];
    }
  }
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      dis[i][j] = inf;
    }
  }
  for (int i = 0; i <= n + 1; i++) {
    mp[i][0] = mp[i][m + 1] = 'X';
  }
  for (int i = 0; i <= m + 1; i++) {
    mp[0][i] = mp[n + 1][i] = 'X';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] == '*') {
        q.push(make_pair(0, make_pair(i, j)));
        dis[i][j] = 0;
      }
    }
  }
  while (q.size()) {
    pair<int, pair<int, int> > t = q.top();
    q.pop();
    int x = t.second.first, y = t.second.second;
    int v = -t.first;
    if (mp[x][y] == '@') {
      printf("%d\n", v);
      return 0;
    }
    if (vis[x][y]) {
      continue;
    }
    dis[x][y] = v;
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
      if (vis Dis == 0 && mp Dis != 'X') {
        Push(x + fx[i], y + fy[i]);
      }
    }
    // printf("%d %d\n", x, y);
  }
      // for (int i = 1; i <= n; i++) {
      //   for (int j = 1; j <= m; j++) {
      //     printf("%d ", dis[i][j]);
      //   }printf("\n");
      // }
  printf("-1");
}
/*

3
- - *
@ - *
X - -

*/
