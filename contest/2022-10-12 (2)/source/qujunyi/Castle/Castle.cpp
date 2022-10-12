#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005, maxm = 2000005;
int n, head[maxn], dis[maxn], cnt = 0;
bool vis[maxn];
struct Edge {
  int to, w, next;
} edges[maxm];
void add_edge(int a, int b, int w) {
  cnt++;
  edges[cnt].to = b;
  edges[cnt].w = w;
  edges[cnt].next = head[a];
  head[a] = cnt;
  return;
}
struct Node {
  int id, dist;
  bool operator<(const Node &b) const {
    return dist > b.dist;
  }
};
void dijkstra(int s) {
  memset(vis, false, sizeof(vis));
  priority_queue<Node> pq;
  for (int i = 1; i <= n; i++) {
    dis[i] = 1e9;
  }
  dis[s] = 0;
  Node start = {s, 0};
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
      if (dis[v] > dis[u] + edges[i].w) {
        dis[v] = dis[u] + edges[i].w;
        Node nxt = {v, dis[v]};
        pq.push(nxt);
      }
    }
  }
  return;
}
int main() {
	freopen("Castle.in","r",stdin);
	freopen("Castle.out","w",stdout);
  ios::sync_with_stdio(false);
  int m, s;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    add_edge(x, y, w);
    add_edge(y, x, w);
  }
  dijkstra(1);
  int ans  = 1;
  for(int i = 2;i <= n;i++){
    int sum = 0;
    for (int j = head[i]; j != 0; j = edges[j].next) {
      int x = edges[j].to;
      if(dis[i]==dis[x]+edges[j].w){
        sum++;
      }
    }
    ans*=sum;
  }
  cout << ans;
  return 0;
}
