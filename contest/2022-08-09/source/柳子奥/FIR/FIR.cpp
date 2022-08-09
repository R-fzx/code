#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#define db(x) cerr << #x << '=' << x << endl;
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define dbg debug("*** Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

using namespace std;

const int kMaxN = 1e3 + 5;
const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

vector<int> G1[kMaxN], G2[kMaxN], v, bv; // 1 : 4连通 2 : 8
int n, k;
int b[kMaxN], x[kMaxN], y[kMaxN], p[kMaxN][kMaxN], idx[kMaxN * kMaxN];
bool vis[kMaxN], yy[4], fl;

int getid(int x, int y) {
  return (x - 1) * 1000 + y;
}

void addEdge1(int u, int v) {
  G1[u].emplace_back(v), G1[v].emplace_back(u);
}

void addEdge2(int u, int v) {
  G2[u].emplace_back(v), G2[v].emplace_back(u);
}

void dfs1(int x) {
  vis[x] = 1;
  for (auto v : G1[x]) {
    if (vis[v]) continue ;
    dfs1(v);
  }
}

void dfs2(int x) {
  vis[x] = 1;
  for (auto v : G2[x]) {
    if (vis[v]) continue ;
    dfs2(v);
  }
}

void kill(vector<int> v) {
  for (auto x : v) {
    int x1 = (x - 1) / 1000 + 1, y1 = x - 1000 * (x1 - 1);
    p[x1][y1] = 0;
  }
}

void print() {
  for (int i = 1; i <= n; ++i) {
    int x1 = (b[i] - 1) / 1000 + 1, y1 = b[i] - 1000 * (x1 - 1);
    printf("%d %d %d\n", x1, y1, p[x1][y1]);
  }
}

bool check(int x, int y) {
  int c = p[x][y];
  if (x == 3 && y == 3) db(c);
  for (int i = 0; i < 8; ++i) {
    int cx = x, cy = y;
    for (int j = 1; j < k; ++j) {
      cx += dx[i], cy += dy[i];
      // db(p[cx][cy]);
      // db(c);
      if (p[cx][cy] != c) goto YXY;
    }
    // db(p[cx][cy]); db(c);
    // db(x); db(y);
    // db(i);
    return 1;
    YXY:;
  }
  return 0;
}

int main() {
  freopen("FIR.in", "r", stdin);
  freopen("FIR.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
    b[i] = (x[i] - 1) * 1000 + y[i];
  }
  sort(b + 1, b + 1 + n);
  int m = unique(b + 1, b + 1 + n) - b;
  for (int i = 1; i <= m; ++i) {
    idx[b[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    debug("______________________________\n");
    db(i);
    v.clear(); bv.clear();
    memset(yy, 0, sizeof(yy));
    memset(vis, 0, sizeof(vis));
    if (i & 1) {
      if (p[x[i]][y[i]]) { puts("illegal"); return 0; }
      p[x[i]][y[i]] = 1;
      for (int j = 0; j < 8; ++j) {
        int tx = x[i] + dx[j], ty = y[i] + dy[j];
        if (tx < 0 || tx > 1000 || ty < 0 || ty > 1000) continue ;
        if (p[tx][ty] != 1) continue ;
        if (j < 4) addEdge1(idx[getid(x[i], y[i])], idx[getid(tx, ty)]), addEdge2(idx[getid(x[i], y[i])], idx[getid(tx, ty)]);
        else addEdge2(idx[getid(x[i], y[i])], idx[getid(tx, ty)]);
      }
      memset(vis, 0, sizeof(vis));
      v.clear();
      for (int j = 0; j < 4; ++j) {
        int x1 = x[i] + dx[j], y1 = y[i] + dy[j];
        if (x1 < 0 || x1 > 1000 || y1 < 0 || y1 > 1000) continue ;
        if (p[x1][y1] == 2) {
          bv.emplace_back(idx[getid(x1, y1)]);
        }
      }
      for (auto tt : bv) {
        if (i == 5) db(b[tt]);
        // db(tt);
        memset(vis, 0, sizeof(vis));
        dfs1(tt);
        v.clear();
        for (int j = 1; j <= m; ++j) {
          if (vis[j]) v.emplace_back(b[j]);
        }
        if (i == 5) db(v.size());
        fl = 1;
        for (auto kk : v) {
          int x1 = (kk - 1) / 1000 + 1, y1 = kk - 1000 * (x1 - 1);
          if (i == 5) {db(x1); db(y1);}
          for (int j = 0; j < 4; ++j) {
            int x2 = x1 + dx[j], y2 = y1 + dy[j];
            if (x2 < 0 || x2 > 1000 || y2 < 0 || y2 > 1000) continue ;
            if (p[x2][y2] == 0) {
              fl = 0;
            }
          }
        }
        if (fl) {
          kill(v);
          dbg;
        }
      }
      memset(vis, 0, sizeof(vis));
      dfs1(idx[getid(x[i], y[i])]);
      for (int j = 1; j <= m; ++j) {
        if (vis[j]) v.emplace_back(b[j]);
      }
      fl = 1;
      for (auto kk : v) {
        int x1 = (kk - 1) / 1000 + 1, y1 = kk - 1000 * (x1 - 1);
        if (i == 11) {db(x1);db(y1);}
        for (int j = 0; j < 4; ++j) {
          int x2 = x1 + dx[j], y2 = y1 + dy[j];
          if (x2 < 0 || x2 > 1000 || y2 < 0 || y2 > 1000) continue ;
          if (p[x2][y2] == 0) {
            fl = 0;
          }
        }
      }
      if (fl == 1) { puts("illegal"); return 0; }
      // if (i == 17) puts("!!!");
      if(check(x[i], y[i])) { cout << "ITer " << i << endl; return 0; }
    } else {
      if (p[x[i]][y[i]]) { puts("illegal"); return 0; }
      p[x[i]][y[i]] = 2;
      for (int j = 0; j < 8; ++j) {
        int tx = x[i] + dx[j], ty = y[i] + dy[j];
        if (tx < 0 || tx > 1000 || ty < 0 || ty > 1000) continue ;
        if (p[tx][ty] != 2) continue ;
        if (j < 4) addEdge1(idx[getid(x[i], y[i])], idx[getid(tx, ty)]), addEdge2(idx[getid(x[i], y[i])], idx[getid(tx, ty)]);
        else addEdge2(idx[getid(x[i], y[i])], idx[getid(tx, ty)]);
      }
      memset(vis, 0, sizeof(vis));
      v.clear();
      for (int j = 0; j < 4; ++j) {
        int x1 = x[i] + dx[j], y1 = y[i] + dy[j];
        if (x1 < 0 || x1 > 1000 || y1 < 0 || y1 > 1000) continue ;
        if (p[x1][y1] == 1) {
          bv.emplace_back(idx[getid(x1, y1)]);
        }
      }
      for (auto tt : bv) {
        if (i == 8) db(b[tt]);
        memset(vis, 0, sizeof(vis));
        dfs1(tt);
        v.clear();
        for (int j = 1; j <= m; ++j) {
          if (vis[j]) v.emplace_back(b[j]);
        }
        fl = 1;
        for (auto kk : v) {
          int x1 = (kk - 1) / 1000 + 1, y1 = kk - (x1 - 1) * 1000;
          for (int j = 0; j < 4; ++j) {
            int x2 = x1 + dx[j], y2 = y1 + dy[j];
            if (x2 < 1 || x2 > 1000 || y2 < 1 || y2 > 1000) continue ;
            if (p[x2][y2] == 0) {
              fl = 0;
            }
          }
        }
        if (fl) {
          kill(v);
          dbg;
        }
      }
      memset(vis, 0, sizeof(vis));
      dfs1(idx[getid(x[i], y[i])]);
      for (int j = 1; j <= m; ++j) {
        if (vis[j]) v.emplace_back(b[j]);
      }
       fl = 1;
      for (auto kk : v) {
        int x1 = (kk - 1) / 1000 + 1, y1 = kk - 1000 * (x1 - 1);
        if (i == 2) {db(x1);db(y1);}
        for (int j = 0; j < 4; ++j) {
          int x2 = x1 + dx[j], y2 = y1 + dy[j];
          if (x2 < 0 || x2 > 1000 || y2 < 0 || y2 > 1000) continue ;
          if (p[x2][y2] == 0) {
            fl = 0;
          }
        }
      }
      if (fl == 1) { puts("illegal"); return 0; }

      if(check(x[i], y[i])) { cout << "Kitty " << i << endl; return 0; }
    }
    // print();
    // puts("____________________________");
  }
  puts("draw");
  return 0;
}
/*
20 5 2 3 3 3 3 2 2 2 4 3 2 4 5 3 1 3 3 4 5 5 2 3 3 3 2 3 2 5 6 3 1 5 3 3 1 5 1 5 1 5
*/