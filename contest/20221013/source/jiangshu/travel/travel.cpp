#pragma GCC optimize ("Ofast")
#include <iostream>
#include <vector>

using namespace std;
using Pii = pair <int, int>;

const int N = 1005, M = 3005, K = 1e6;

struct E {
  int to, next;
  int l, r;
} edge[M * 2];
Pii res;
bool vis[N];
int tot, ans, head[N];
int n, m;

void add (int x, int y, int l, int r) {
  edge[++tot] = {y, head[x], l, r}; head[x] = tot;
  edge[++tot] = {x, head[y], l, r}; head[y] = tot;
}

Pii Q (int x1, int y1, int x2, int y2) {
  if (x1 <= x2) {
    if (y1 >= y2) {
      return {x2, y2};
    } else {
      return {x2, y1};
    }
  }
  if (y1 >= y2) {
    if (x1 <= x2) {
      return {x2, y2};
    } else {
      return {x1, y2};
    }
  }
  swap (x1, x2), swap (y1, y2);
  if (x1 <= x2) {
    if (y1 >= y2) {
      return {x2, y2};
    } else {
      return {x2, y1};
    }
  }
  if (y1 >= y2) {
    if (x1 <= x2) {
      return {x2, y2};
    } else {
      return {x1, y2};
    }
  }
  return {x1, y1};
}

void D (int cur, int fath, int l, int r) {
  Pii o = {l, r};
  if (cur == n || vis[cur]) {
    if (ans < r - l + 1 || (ans == r - l + 1 && res > o)) {
      ans = r - l + 1, res = o;
    }
    return ;
  }
  vis[cur] = 1;
  for (int i = head[cur], to; i; i = edge[i].next) {
    to = edge[i].to;
    if (to != fath) {
      if (edge[i].r < l || edge[i].l > r) {
        continue;
      }
      Pii L = Q (l, r, edge[i].l, edge[i].r);
      D (to, cur, L.first, L.second);
    }
  }
  vis[cur] = 0;
}

int main () {
  freopen ("travel.in", "r", stdin);
  freopen ("travel.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    add (x, y, l, r);
  }
  D (1, -1, 1, K);
  cout << ans << '\n';
  for (int i = res.first; i <= res.second; i++) {
    cout << i << ' ';
  }
  return 0;
}