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

const int kMaxN = (1 << 21) + 5;

int n, k;
int a[kMaxN], vis[kMaxN], cp[kMaxN];

int get(int l, int r) {
  int nw = 0;
  if (l <= r) {
    for (int i = l; i <= r; ++i) {
      nw = (nw << 1) + a[i];
    }    
  } else {
    for (int i = l; i <= n; ++i) {
      nw = (nw << 1) + a[i];
    }
    for (int i = 1; i <= r; ++i) {
      nw = (nw << 1) + a[i];
    }
  }
  return nw;
}

void check() {
  for (int s = n - k + 2; s <= n; ++s) {
    if (vis[get(s, s + k - n - 1)]) goto GG;
    vis[get(s, s + k - n - 1)] = 1;
  }
  cout << n << ' ';
  for (int i = 1; i <= n; ++i) {
    cout << a[i];
  }
  exit(0);
  GG:;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n - k + 1; ++i) {
    vis[get(i, i + k - 1)] = 1;
  }
}

void dfs(int x) {
  if (x == n + 1) return check();
  for (int i = 0; i <= 1; ++i) {
    a[x] = i;
    if (x < k) goto FK;
    if (vis[get(x - k + 1, x)]) continue ;
    vis[get(x - k + 1, x)] = 1;
    FK:;
    dfs(x + 1);
    vis[get(x - k + 1, x)] = 0;
  }
}

int main() {
  file("taiko");
  cin >> k;
  n = (1 << k);
  dfs(1);
  return 0;
}