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

const int kMaxN = 2e5 + 5, kMod = 1e9 + 9;

class DSU {
  public:
    void init(int n) {
      for (int i = 1; i <= n; ++i) {
        fa[i] = i;
      }
    }
    int find(int x) {
      return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void unionn(int x, int y) {
      int fx = find(x), fy = find(y);
      if (fx != fy) fa[fx] = fy;
    }
  private:
    int fa[kMaxN];
} d;

int n, m, ans;

int main() {
  file("magician");
  n = read(), m = read();
  d.init(n);
  while (m--) {
    int u = read(), v = read();
    if (d.find(u) == d.find(v)) ans = (2ll * ans + 1ll) % kMod;
    else d.unionn(u, v);
    printf("%d\n", ans);
  }
  return 0;
}