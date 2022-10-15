#include <bits/stdc++.h>

#define db(x) cerr << #x << '=' << x << endl

using namespace std;

int n, m, k, ans;
int a[5][5], cc[15], cnt[15][15];
bool vis[10005];

void check() {
  int k1, k2, k3 = 0;
  memset(cc, 0, sizeof(cc));
  int kkk = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i < m; ++i) {
    memset(vis, 0, sizeof(vis));
    int t1 = 0, t2 = 0;
    for (int x = 1; x <= i; ++x) {
      for (int y = 1; y <= n; ++y) {
        if (!vis[a[y][x]]) {
          ++t1;
        }
        vis[a[y][x]] = 1;
      }
    }
    memset(vis, 0, sizeof(vis));
    for (int x = m; x > i; --x) {
      for (int y = 1; y <= n; ++y) {
        if (!vis[a[y][x]]) {
          ++t2;
        }
        vis[a[y][x]] = 1;
      }
    }
    if (t1 != t2) return ;
  }
  // ++cnt[k1][k3];
  // if(k3 != kkk) {
  //   db("!!!!");
  // cout << "----------"<< endl;
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     cout << a[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // exit(0);
  // }
  ++ans;
}

void dfs(int x) {
  if (x == n * m + 1) {
    return check();
  }
  for (int i = 1; i <= k; ++i) {
    a[(x - 1) / m + 1][(x - 1) % m + 1] = i;
    dfs(x + 1);
  }
}

int main() {
  cin >> n >> m >> k;
  dfs(1);
  cout << ans << endl;
  return 0;
}