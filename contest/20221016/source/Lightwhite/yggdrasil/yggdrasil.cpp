#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
const int kN = 7e5 + 5;
const ll kI = 1e16;

ll f[kN], p, ans = kI, c;
int n, s[kN], w[kN], tot, h[kN];
struct Edge {
  int v, nxt, w;
} ed[kN << 1];
void A(int u, int v, int w) {
  ed[++tot] = {v, h[u], w};
  h[u] = tot;
}
void D(int x, int fa) {
  s[x] = 1;
  for (int i = h[x], v; i; i = ed[i].nxt) {
    v = ed[i].v;
    if (v == fa) {
      continue;
    }
    D(v, x);
    f[x] += f[v] + s[v] * (ed[i].w - w[x]);
    s[x] += s[v];
  }
}
void _D(int x, int fa) {
  if (ans > c) {
    p = x;
    ans = c;
  }
  for (int i = h[x], v; i; i = ed[i].nxt) {
    v = ed[i].v;
    if (v == fa) {
      continue;
    }
    c -= (ed[i].w - w[x]) * s[v];
    c += (ed[i].w - w[v]) * (s[1] - s[v]);
    _D(v, x);
    c += (ed[i].w - w[x]) * s[v];
    c -= (ed[i].w - w[v]) * (s[1] - s[v]);
  }
}
int main() {
  freopen("yggdrasil.in", "r", stdin);
  freopen("yggdrasil.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for_each(w + 1, w + n + 1, [&](int& x) { cin >> x; });
  for (int i = 1, u, v, w; i < n; i++) {
    cin >> u >> v >> w;
    A(u, v, w);
    A(v, u, w);
  }
  D(1, 0);
  c = f[1];
  _D(1, 0);
  cout << p << '\n' << ans << '\n';
  return 0;
}