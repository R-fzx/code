#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

struct Node {
  int f;
  vector<int> s;
  int x = 0;
} a[MAXN];

int fa(int x) {
  if (a[x].f == x) {
    return x;
  }
  a[x].f = fa(a[x].f);
  return a[x].f;
}

int main() {
  freopen("magician.in", "r", stdin);
  freopen("magician.out", "w", stdout);
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    a[i].f = i;
  }
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v;
    if (fa(u) == fa(v)) {
      ans -= (1 << a[a[u].f].x) - 1;
      ++a[a[u].f].x;
      ans += (1 << a[a[u].f].x) - 1;
    } else {
      a[v].f = a[u].f;
    }
    cout << ans << '\n';
  }
  return 0;
}