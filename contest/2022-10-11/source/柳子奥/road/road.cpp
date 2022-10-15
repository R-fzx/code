#include <bits/stdc++.h>

#define int long long
#define db(x) cerr << #x << '=' << x << endl

using namespace std;

const int kMaxN = 205, kMaxM = 5e4 + 5;

struct Edge {
  int u, v, a, b;
} ed[kMaxM];

int n, m, p, q, m1, m2, ans;
int b[kMaxM], c[kMaxM], g[kMaxN][kMaxN];
bool vis[kMaxN];

void dfs(int u) {
  if (vis[u]) return ;
  vis[u] = 1;
  for (int i = 1; i <= n; ++i) {
    if (i != u && g[u][i]) {
      dfs(i);
    }
  }
}

bool check(int x, int y) {
  memset(g, 0, sizeof(g));
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= m; ++i) {
    if (ed[i].a <= x && ed[i].b <= y) {
      g[ed[i].u][ed[i].v] = g[ed[i].v][ed[i].u] = 1;
    }
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) return 0;
  }
  return 1;
}

int solve(int x) {
  int L = -1, R = m2 + 1, res = -1e18;
  while (L + 1 < R) {
    int mid = (L + R) >> 1;
    if (check(x, c[mid])) R = res = mid;
    else L = mid;
  }
  if (res == -1e18) return 1e18;
  else return c[res];
}

signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  scanf("%d%d%d%d", &n, &m, &p, &q);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &ed[i].u, &ed[i].v, &ed[i].a, &ed[i].b);
    b[i] = ed[i].a, c[i] = ed[i].b;
  }
  sort(b + 1, b + 1 + m), sort(c + 1, c + 1 + m);
  m1 = unique(b + 1, b + 1 + m) - (b + 1);
  m2 = unique(c + 1, c + 1 + m) - (c + 1);
  ans = 1e18;
  for (int i = 0; i <= m1; ++i) {
    ans = min(ans, b[i] * p + solve(b[i]) * q);
  }
  cout << (ans == 1e18 ? -1 : ans) << endl;
  return 0;
}