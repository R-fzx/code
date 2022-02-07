#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 310, MAXM = 12010;
bool vis[MAXN];
int n, m, cnt, ans, head[MAXN], match[MAXN];
struct edge {
  int nxt, to;
} e[MAXM];
void AddEdge(int x, int y) {
  e[++cnt].nxt = head[x];
  e[cnt].to = y;
  head[x] = cnt;
}
bool DFS(int x) {
  for (int i = head[x], t; i; i = e[i].nxt)
    if (!vis[t = e[i].to]) {
      vis[t] = 1;
      if (!match[t] || DFS(match[t])) {
        match[x] = t, match[t] = x;
        return 1;
      }
    }
  return 0;
}
void Hungary(void) {
  for (int i = 1; i <= n; ++i)
    if (!match[i]) {
      memset(vis, 0, sizeof vis);
      ans -= DFS(i);
    }
}
void Print(int x) {
  x += n;
  do
    printf("%d ", x = x - n);
  while (vis[x] = 1, x = match[x]);
  printf("\n");
}
int main(int argc, char *argv[]) {
  scanf("%d %d", &n, &m);
  ans = n;
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d %d", &x, &y);
    AddEdge(x, y + n);
  }
  Hungary();
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; ++i)
    if (!vis[i])
      Print(i);
  printf("%d\n", ans);
  return 0;
}
