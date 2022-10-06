#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...)
#endif

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;

int read() {
  int x = 0, f = 0; char ch = getchar();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x * 10) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}

const int kMaxN = 55;

int n, k;
int a[kMaxN], b[kMaxN], c[10][10];
string s;
bool vis[10];

bool check(int x) {
  for (int i = 1; i <= n; ++i) {
    if (x >= a[i] && x <= b[i]) return 1;
  }
  return 0;
}

int getr(int x, int p, int q, int s) {
  static int c[20];
  int tp = 0, ret = 0;
  while (x) {
    c[++tp] = x % 10, x /= 10;
  }
  for (int i = 1; i <= k; ++i) {
    if (s >> (i - 1) & 1) {
      if (c[i] == p) c[i] = q;
    }
  }
  for (int i = tp; i; --i) {
    ret = 10 * ret + c[i];
  }
  return ret;
}

int rev(int p, int q) {
  for (int i = 1; i <= 6000; ++i) {
    if (check(i)) {
      for (int j = 0; j < (1 << k); ++j) {
        if (!check(getr(i, p, q, j))) return 0;
      }
    }
  }
  return 1;
}

void dfs(int u) {
  if (vis[u]) return ;
  vis[u] = 1, s += u + '0';
  for (int v = 1; v <= 9; ++v) {
    if (u == v || !c[u][v]) continue ;
    dfs(v);
  }
}

int main() {
  file("laser");
  n = read(), k = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read(), b[i] = read();
  }
  for (int p = 1; p <= 9; ++p) {
    for (int q = p + 1; q <= 9; ++q) {
      if (rev(p, q) && rev(q, p)) c[p][q] = c[q][p] = 1;
    }
  }
  for (int i = 1; i <= 9; ++i) {
    if (!vis[i]) {
      s = "", dfs(i);
      sort(s.begin(), s.end());
      cout << s << endl;
    }
  }
  return 0;
}