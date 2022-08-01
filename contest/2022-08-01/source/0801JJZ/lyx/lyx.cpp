#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int kN = 1e5 + 5;

struct Edge {
  int v, nxt;
} ed[kN << 1];
int n, m, tot, ans, h[kN], ind[kN], oud[kN], f[kN];
void add (int u, int v) {
  ed[++tot] = {v, h[u]}, h[u] = tot;
}
int DFS (int x) {
  if (!oud[x]) {
    return f[x] = 1;
  }
  for (int i = h[x], v; i; i = ed[i].nxt) {
    v = ed[i].v;
    (!f[v]) ? f[v] = DFS (v) : 0; 
    f[x] += f[v];
  }
  return f[x];
}
int main () {
  freopen ("lyx.in", "r", stdin);
  freopen ("lyx.out", "w", stdout);
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v, add (u, v), ind[v]++, oud[u]++;
  }
  for (int i = 1; i <= n; i++) {
    (!f[i]) ? f[i] = DFS (i) : 0;
  }
  for (int i = 1; i <= n; i++) {
    (!ind[i] && h[i]) ? ans += f[i] : 0;
  }
  cout << ans << '\n';
  return 0;
}