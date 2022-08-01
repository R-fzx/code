#include  <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

inline int r() {
  int c = getchar(), s = 0;
  while (c < 48 || c > 57) c = getchar();
  while (c > 47 && c < 58) s = (s << 3) + (s << 1) + c - 48, c = getchar();
  return s;
}

inline void w(int x) {
  if (x > 9) {
    w(x / 10);
  }
  putchar(x % 10 + 48);
}

struct Node {
  vector<int> e;
  int cnt, d1, d2;
} a[MAXN];

int n, m;

void bfs() {
  queue<int> q;
  for (int i(1); i <= n; ++i) {
    if (!a[i].d1) {
      q.push(i);
      a[i].cnt = 1;
    } else {
      a[i].cnt = 0;
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i(0); i < a[x].e.size(); ++i) {
      int nx = a[x].e[i];
      --a[nx].d1;
      a[nx].cnt += a[x].cnt;
      if (!a[nx].d1) {
        q.push(nx);
      }
    }
  }
}

int main() {
  freopen("lyx.in", "r", stdin);
  freopen("lyx.out", "w", stdout);
  n = r(), m = r();
  int ans = 0;
  for (int i(0), u, v; i < m; ++i) {
    u = r(), v = r();
    a[u].e.push_back(v);
    ++a[u].d2, ++a[v].d1;
  }
  bfs();
  for (int i(1); i <= n; ++i) {
    if (!a[i].d2) {
      ans += a[i].cnt;
    }
  }
  w(ans);
  return 0;
}