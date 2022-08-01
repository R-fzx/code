#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5 + 5;

vector<int> G[kMaxN];
int n, m;
int u, v;
int in[kMaxN], out[kMaxN];

void addEdge(int u, int v) {
  G[u].emplace_back(v);
  ++in[v], ++out[u];
}

namespace Topo {

queue<int> q;
int f[kMaxN];

void Topo() {
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!in[i]) {
      q.emplace(i);
      f[i] = 1;
    }
  }
  while (!q.empty()) {
    int nf = q.front(); q.pop();
    for (auto to : G[nf]) {
      f[to] += f[nf];
      if (!--in[to]) q.emplace(to);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!out[i]) {
      ans += f[i];
    }
  }
  printf("%lld\n", ans);
}

} // namespace Topo

int main() {
  freopen("lyx.in", "r", stdin);
  freopen("lyx.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    addEdge(u, v);
  }
  Topo::Topo();
  return 0;
}
/*
10 16
1 2
1 4
1 10
2 3
2 5
4 3
4 5
4 8
6 5
7 6
7 9
8 5
9 8
10 6
10 7
10 9
*/