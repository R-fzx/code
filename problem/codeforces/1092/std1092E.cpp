#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;
const int INF = 1000000000;

int n, m;
vector<int> g[N];

int bfs(int x, int dist[N]) {
  queue<int> q;
  q.push(x);
  dist[x] = 0;
  int lst = -1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    lst = v;
    for (auto u : g[v])
      if (dist[u] > dist[v] + 1) {
        dist[u] = dist[v] + 1;
        q.push(u);
      }
  }
  return lst;
}

int distx[N], disty[N];
bool used[N];
vector<int> cur;

void dfs(int v) {
  used[v] = true;
  cur.push_back(v);
  for (auto u : g[v])
    if (!used[u])
      dfs(u);
}

int main() {
  scanf("%d%d", &n, &m);
  forn(i, m) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v, --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }

  forn(i, n) distx[i] = disty[i] = INF;

  vector<pair<int, int>> comps;
  forn(i, n) if (!used[i]) {
    cur.clear();
    dfs(i);
    int x = bfs(i, distx);
    int y = bfs(x, disty);
    for (auto v : cur) distx[v] = INF;
    bfs(y, distx);
    int d = disty[y], center;
    for (auto v : cur)
      if (distx[v] == d / 2 && disty[v] == d - d / 2)
        center = v;
    comps.push_back({d, center});
  }

  vector<pair<int, int>> ans;
  nth_element(comps.begin(), comps.end() - 1, comps.end());
  forn(i, int(comps.size()) - 1) {
    g[comps[i].second].push_back(comps.back().second);
    g[comps.back().second].push_back(comps[i].second);
    ans.push_back({comps[i].second, comps.back().second});
  }

  forn(i, n) distx[i] = disty[i] = INF;
  int y = bfs(bfs(comps.back().second, distx), disty);

  printf("%d\n", disty[y]);
  for (auto it : ans)
    printf("%d %d\n", it.first + 1, it.second + 1);
  return 0;
}