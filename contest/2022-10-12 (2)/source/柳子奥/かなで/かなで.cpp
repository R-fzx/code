#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

using namespace std;

typedef pair<int, int> pii;

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int n, m, k, tt;
int a[10][10];
bool vs[10][10], cc[10][10];
pii c[15], tmp[15];
map<unsigned long long, bool> mp;
vector<int> b[10];

void dfs(int x, int y) {
  if (cc[x][y]) return ;
  cc[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int tx = x + dx[i], ty = y + dy[i];
    if (tx < 1 || tx > n || ty < 1 || ty > m) continue ;
    dfs(tx, ty);
  }
}

void check() {
  if (tt != k) return ;
  memset(cc, 0, sizeof(cc));
  dfs(c[1].first, c[1].second);
  for (int i = 1; i <= k; ++i) {
    if (!cc[c[i].first][c[i].second]) return ;
  }
  for (int i = 2; i <= k; ++i) {
    c[i].first -= c[1].first - 1, c[i].second -= c[1].second - 1;
  }
  c[1] = {1, 1};
  unsigned long long hs = 1;
  for (int i = 1; i <= n; ++i) {
    hs *= (unsigned long long)((c[i].first - 1) * m + c[i].second);
  }
  
}

void dfs(int x) {
  if (tt == k || x == n + 1) {
    return check();
  }
  for (int s = 0; s < (1 << ((int)b[x].size())); ++s) {
    int tmp = tt;
    for (int i = 0; i < (int)b[x].size(); ++i) {
      if (s >> i & 1) {
        c[++tt] = {x, b[x][i]}, vs[x][b[x][i]] = 0;
        if (tt > k) goto FK;
      }
    }
    dfs(x + 1);
    FK:;
    for (int i = tmp + 1; i <= tt; ++i) {
      vs[x][c[i].second] = 0;
    }
    tt = tmp;
  }
}

int main() {
  freopen("かなで.in", "r", stdin);
  freopen("かなで.out", "w", stdout);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      if (a[i][j]) b[i].emplace_back(j);
    }
  }
  dfs(1, 0);
  return 0;
}
