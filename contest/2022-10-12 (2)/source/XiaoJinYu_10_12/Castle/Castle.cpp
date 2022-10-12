#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize(3)
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 5, Mod = 2147483647;

int n, m, ans = 1;

inline void r(int &s) {
  s = 0;
  int c(getchar());
  while (c < 48 || c > 57) c = getchar();
  while (c > 47 && c < 58) s = (s << 3) + (s << 1) + c - 48, c = getchar();
}

struct Node {
  int v, w;
  bool operator>(const Node &x) const {
    if (x.w != w) return w < x.w;
    return v < x.v;
  }
  bool operator<(const Node &x) const {
    if (x.w != w) return w > x.w;
    return v > x.v;
  }
};

vector<Node> a[MAXN];
int dis[MAXN];

void shit() {
  priority_queue<Node> q;
  q.push({1, 0});
  dis[1] = 0;
  while (!q.empty()) {
    Node x = q.top();
    q.pop();
    int cnt = 1;
    while (!q.empty() && x.v == q.top().v && x.w == q.top().w) {
      ++cnt;
      q.pop();
    }
    ans = (1ll * cnt * ans) % Mod;
    for (int i = 0; i < a[x.v].size(); ++i) {
      Node nx = a[x.v][i];
      nx.w += x.w;
      if (dis[nx.v] >= nx.w) {
        dis[nx.v] = nx.w;
        q.push(nx);
      }
    }
  }
}

int main() {
  freopen("Castle.in", "r", stdin);
  freopen("Castle.out", "w", stdout);
  r(n), r(m);
  int u, v, w;
  while (m--) {
    r(u), r(v), r(w);
    a[u].push_back({v, w});
    a[v].push_back({u, w});
  }
  for (int i = 0; i <= n; ++i) {
    dis[i] = 1145141919;
  }
  shit();
  cout << ans;
  return 0;
}