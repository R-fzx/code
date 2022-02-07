#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int kmax = 310, kmaxM = 12010;

bool vis[kmax];
int n, m, cnt, ans, h[kmax], match[kmax];

struct edge {
  int p, to;
} e[kmaxM];

void AddEdge(int x, int y) {
  e[++cnt] = {h[x], y};
  h[x] = cnt;
}

bool DFS(int x) {
  for (int i = h[x], t; i; i = e[i].p) {
    if (!vis[t = e[i].to]) {
      vis[t] = 1;
      if (!match[t] || DFS(match[t])) {
        match[x] = t, match[t] = x;
        return 1;
      }
    }
  }
  return 0;
}

void Hungary() {
  for (int i = 1; i <= n; ++i) {
    if (!match[i]) {
      memset(vis, 0, sizeof vis);
      ans -= DFS(i);
    }
  }
}

void Print(int x) {
  x += n;
  do {
    printf("%d ", x = x - n);
  } while (vis[x] = 1, x = match[x]);
  printf("\n");
}

int main() {
  scanf("%d %d", &n, &m);
  ans = n;
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d %d", &x, &y);
    AddEdge(x, y + n);
  }
  Hungary();
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      Print(i);
    }
  }
  printf("%d\n", ans);
  return 0;
}