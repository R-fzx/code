#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif
#define int long long

using namespace std;

const int kMaxN = 1005, kMod = 2147483647, kInf = 1e17;

int n, m, ans = 1ll;
int cnt[kMaxN], dis[kMaxN];
bool vis[kMaxN];
vector<pair<int, int>> G[kMaxN];
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
    if (vis[u]) continue ;
    vis[u] = 1;
    for (auto p : G[u]) {
      int v = p.first, w = p.second;
      // if (v == 4) debug(u, w);
      if (dis[v] > dis[u] + w) {
        // if (v == 4) debug(u, w);
        dis[v] = dis[u] + w, q.emplace(-dis[v], v), cnt[v] = 1;
      } else if (dis[v] == dis[u] + w) {
        // if (v == 4) debug(u, w);
        ++cnt[v];
      }
    }
  }
}

signed main() {
  freopen("Castle.in", "r", stdin);
  freopen("Castle.out", "w", stdout);
  scanf("%lld%lld", &n, &m);
  for (int i = 1, u, v, w; i <= m; ++i) {
    scanf("%lld%lld%lld", &u, &v, &w);
    if (u != v) addE(u, v, w), addE(v, u, w);
    // if (u * v == 8) debug(i);
  }
  dij();
  for (int i = 2; i <= n; ++i) {
    // debug(i, cnt[i], dis[i]);
    ans = (ans * cnt[i]) % kMod;
  }
  printf("%lld\n", ans);
  return 0;
}
