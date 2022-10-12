#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif
#define int long long

using namespace std;

const int kMaxN = 1005, kMod = 2147483647, kInf = 1e17;


int n, m, ans;
int cnt[kMaxN], dis[kMaxN], dd[kMaxN], u[100005], v[100005], w[100005], c[100005];
bool vis[kMaxN];
vector<pair<int, int>> G[kMaxN], gg[kMaxN];
priority_queue<pair<int, int>> q;

void addE(int u, int v, int w) {
  G[u].emplace_back(v, w);
}

void dij() {
  fill(dis + 1, dis + 1 + n, kInf);
  fill(vis + 1, vis + 1 + n, 0);
  while (!q.empty()) q.pop();
  dis[1] = 0, q.emplace(0, 1);
  while (!q.empty()) {
    auto nt = q.top(); q.pop();
    int u = nt.second;
    for (auto p : G[u]) {
      int v = p.first, w = p.second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w, q.emplace(-dis[v], v);
      }
    }
  }
}

void dijj() {
  fill(dd + 1, dd + 1 + n, kInf);
  fill(vis + 1, vis + 1 + n, 0);
  while (!q.empty()) q.pop();
  dd[1] = 0, q.emplace(0, 1);
  while (!q.empty()) {
    auto nt = q.top(); q.pop();
    int u = nt.second;
    for (auto p : gg[u]) {
      int v = p.first, w = p.second;
      if (dd[v] > dd[u] + w) {
        dd[v] = dd[u] + w, q.emplace(-dd[v], v);
      }
    }
  }
}

void check() {
  int cc = 0;
  for (int i = 1; i <= n; ++i) {
    gg[i].clear();
  }
  for (int i = 1; i <= m; ++i) {
    if (c[i]) {
      ++cc;
      gg[u[i]].emplace_back(v[i], w[i]), gg[v[i]].emplace_back(u[i], w[i]);
    }
  }
  if (cc != n - 1) return ;
  dijj();
  for (int i = 2; i <= n; ++i) {
    if (dis[i] != dd[i]) {
      return ;
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (c[i]) cerr << u[i] << ' ' << v[i] << ' ' << w[i] << endl;
  }
  cerr << "----------" << endl;
  ++ans;
}

void dfs(int x) {
  if (x == m + 1) {
    return check();
  }
  for (int i = 0; i <= 1; ++i) {
    c[x] = i;
    dfs(x + 1);
    c[x] = 0;
  }
}

signed main() {
  freopen("castle.in", "r", stdin);
  freopen("bf.out", "w", stdout);
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%lld%lld%lld", &u[i], &v[i], &w[i]);
    addE(u[i], v[i], w[i]), addE(v[i], u[i], w[i]);
  }
  dij();
  dfs(1);
  cout << ans << endl;
  return 0;
}