#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

using namespace std;

const int kMaxN = 205;

class DSU {
  public:
    void init(int n) {
      for (int i = 1; i <= n; ++i) {
        fa[i] = i, sz[i] = 1;
      }
    }
    int find(int x) {
      return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void unionn(int x, int y) {
      int fx = find(x), fy = find(y);
      if (fx != fy) fa[fx] = fy, sz[fy] += sz[fx];
    }
    int getsz(int x) {
      return sz[find(x)];
    }
  private:
    int fa[kMaxN], sz[kMaxN];  
} d;

int n, m, ed;
int a[kMaxN][kMaxN], deg[kMaxN];
bool vis[kMaxN];
vector<int> G[kMaxN], R[kMaxN];

void addE(int u, int v) {
  G[u].emplace_back(v);
}

void dfs(int u) {
  if (vis[u]) return ;
  vis[u] = 1;
  for (auto v : G[u]) {
    dfs(v);
  }
}

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    addE(u, v);
  }
  if (n <= 20) {
    for (int i = 1; i <= n; ++i) {
      memset(vis, 0, sizeof(vis));
      dfs(i);
      for (int j = 1; j <= n; ++j) {
        if (j != i && vis[j]) a[i][j] = a[j][i] = 1;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if (!a[i][j]) R[i].emplace_back(j), R[j].emplace_back(i), ++ed;
      }
    }
    int tmp[10000], res[kMaxN], ans = 1;
    for (int s = 0; s < (1 << n); ++s) {
      int c = 0;
      for (int i = 1; i <= n; ++i) {
        if (s >> (i - 1) & 1) {
          tmp[++c] = i;
        }
      }
      for (int i = 1; i <= c; ++i) {
        for (int j = i + 1; j <= c; ++j) {
          if (a[tmp[i]][tmp[j]]) goto fuck;
        }
      }
      if (c >= ans) {
        ans = c;
        for (int i = 1; i <= c; ++i) {
          res[i] = tmp[i];
        }
      }
      fuck:;
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; ++i) {
      cout << res[i] << ' ';
    }    
  } else {
    d.init(n);
    for (int i = 1; i <= n; ++i) {
      memset(vis, 0, sizeof(vis));
      dfs(i);
      for (int j = 1; j <= n; ++j) {
        if (j != i && vis[j]) a[i][j] = a[j][i] = 1;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if (!a[i][j]) d.unionn(i, j), debug(i, j);
      }
    }
    int x, ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (d.getsz(i) > ans) {
        ans = d.getsz(i), x = d.find(i);
      }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
      if (d.find(i) == x) cout << i << ' ';
    }
  }

  return 0;
}
/*
6 7
1 2
1 3
2 4
3 4
3 5
5 6
4 6
*/