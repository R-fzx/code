#include <algorithm>
#include <iostream>

using namespace std;
const int kN = 6e5 + 5, kM = kN << 3, kI = 1e9, kP = 505;

bool f[kN];
char map[kP][kP];
int n, m, sx, sy, ex, ey, ans = kI, now, T, d[kN], q[kN], h = 1, t = 1, tot, hd[kM];
struct Node {
  int x, y, d;
} p[5];
struct Edge {
  int v, nxt, w;
} ed[kM];
void A(int u, int v, int w) {
  ed[++tot] = {v, hd[u], w};
  hd[u] = tot;
}
int E(int x, int y) {
  return (x - 1) * m + y;
}
void F(int X, int Y) {
  T = E(X, Y);
  if (map[X - 1][Y] != '#') {
    A(T, E(X - 1, Y), 1);
  }
  if (map[X + 1][Y] != '#') {
    A(T, E(X + 1, Y), 1);
  }
  if (map[X][Y - 1] != '#') {
    A(T, E(X, Y - 1), 1);
  }
  if (map[X][Y + 1] != '#') {
    A(T, E(X, Y + 1), 1);
  }
  int x = X, y = Y;
  for ( ; map[x][y] != '#'; x--) {
  }
  p[1] = {x + 1, y, X - x};
  for (x = X; map[x][y] != '#'; x++) {
  }
  p[2] = {x - 1, y, x - X};
  for (x = X; map[x][y] != '#'; y--) {
  }
  p[3] = {x, y + 1, Y - y};
  for (y = Y; map[x][y] != '#'; y++) {
  }
  p[4] = {x, y - 1, y - Y};
  sort(p + 1, p + 5, [&](Node& p1, Node& p2) { return p1.d < p2.d; });
  A(T, E(p[1].x, p[1].y), p[1].d - 1);
  A(T, E(p[2].x, p[2].y), p[1].d);
  A(T, E(p[3].x, p[3].y), p[1].d);
  A(T, E(p[4].x, p[4].y), p[1].d);
}
void S(int s) {
  fill (d + 1, d + n * m + 1, kI);
  d[s] = 0;
  q[t++] = s;
  f[s] = true;
  while (h != t) {
    int x = q[h++];
    f[x] = false;
    if (d[x] == kI) {
      continue;
    }
    for (int i = hd[x], v; i; i = ed[i].nxt) {
      v = ed[i].v;
      if (d[x] + ed[i].w < d[v]) {
        d[v] = d[x] + ed[i].w;
        if (!f[v]) {
          f[v] = true;
          q[t++] = v;
        }
      }
    }
  }
}
int main () {
  freopen("portal.in", "r", stdin);
  freopen("portal.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie (0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> map[i][j];
      if (map[i][j] == 'C') {
        sx = i, sy = j;
      } else if (map[i][j] == 'F') {
        ex = i, ey = j;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (map[i][j] != '#') {
        F(i, j);
      }
    }
  }
  S(E(sx, sy));
  if (d[E(ex, ey)] == kI) {
    cout << "nemoguce" << '\n';
  } else {
    cout << d[E(ex, ey)] << '\n';
  }
  return 0;
}