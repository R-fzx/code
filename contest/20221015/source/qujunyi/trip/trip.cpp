#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005, maxm = 200005;
int n, head[maxn], dis[maxn], diss[maxn], cnt = 0;
bool vis[maxn];
struct Edge {
  int to;
  int w, ww;
  int next;
} edges[maxm];
struct node {
  int x, y;
  double z, zz;
} a[maxm];
int b[maxn];
double ui[maxn];
void add_edge(int a, int b, double w) {
  cnt++;
  int s = w;
  edges[cnt].w = s;
  if (double(s) == w) {
    edges[cnt].ww = s;
  } else {
    edges[cnt].ww = s + 1;
  }
  edges[cnt].to = b;
  edges[cnt].next = head[a];
  head[a] = cnt;
  return;
}
struct Node {
  int id;
  int dist, Dist;
  bool operator<(const Node &b) const {
    if (dist == b.dist) {
      return Dist > b.Dist;
    }
    return dist < b.dist;
  }
};
void dijkstra(int s) {
  memset(vis, false, sizeof(vis));
  priority_queue<Node> pq;
  for (int i = 1; i <= n; i++) {
    dis[i] = 0;
    diss[i] = 2e9;
  }
  dis[s] = 2e9;
  diss[s] = 0;
  Node start = {s, (int)2e9, 0};
  pq.push(start);
  while (!pq.empty()) {
    Node now = pq.top();
    pq.pop();
    int u = now.id;
    if (vis[u] == true)
      continue;
    vis[u] = true;
    for (int i = head[u]; i != 0; i = edges[i].next) {
      int v = edges[i].to;
      if (dis[v] < min(dis[u], edges[i].w)) {
        dis[v] = min(dis[u], edges[i].w);
        diss[v] = max(diss[u], edges[i].ww);
        Node nxt = {v, dis[v], diss[v]};
        pq.push(nxt);
      } else if (dis[v] == min(dis[u], edges[i].w) && max(diss[u], edges[i].ww) < diss[v]) {
        dis[v] = min(dis[u], edges[i].w);
        diss[v] = max(diss[u], edges[i].ww);
        Node nxt = {v, dis[v], diss[v]};
        pq.push(nxt);
      }
    }
  }
  return;
}
int main() {
  freopen("trip.in", "r", stdin);
  freopen("trip.out", "w", stdout);
   ios::sync_with_stdio(false);
   cout.tie(0);
   cin.tie(0);
  int m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].x >> a[i].y >> a[i].z;
  }
  for (int i = 1; i <= n; i++) {
    int u, x;
    cin >> u;
    for (int j = 1; j <= u; j++) {
      cin >> x;
      b[x] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> ui[i];
  }
  for (int i = 1; i <= m; i++) {
    if (b[a[i].x] == b[a[i].y]) {
      add_edge(a[i].x, a[i].y, (a[i].z * ui[b[a[i].x]]) / 100.0000);
      add_edge(a[i].y, a[i].x, (a[i].z * ui[b[a[i].x]]) / 100.0000);
    } else {
      add_edge(a[i].x, a[i].y, (a[i].z * (ui[b[a[i].x]] + ui[b[a[i].y]])) / 200.0000);
      add_edge(a[i].y, a[i].x, (a[i].z * (ui[b[a[i].x]] + ui[b[a[i].y]])) / 200.0000);
    }
  }
  int s, t;
  cin >> s >> t;
  dijkstra(s);
  cout << dis[t] << " " << diss[t];
  return 0;
}
