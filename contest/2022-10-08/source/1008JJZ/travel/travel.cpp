#include <iostream>
#include <algorithm>
#include <cstring>

#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define put(x) (cout << (x) << '\n')
#define file(x) freopen (x".in", "r", stdin), freopen (x".out", "w", stdout)

using namespace std;
const int kN = 255;

int n, m, r[kN], ans;
bool a[kN], b[kN], ed[kN][kN], k[kN];
bool D (int x) {
  a[x] = true;
  for (int i = 1; i <= n; i++) {
    if (ed[x][i] && !b[i] && !a[r[i]]) {
      if (!r[i] || D (r[i])) {
        return r[i] = x, k[i] = true;
      }
    }
  }
  return false;
}
int main () {
  file ("travel");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v, ed[u][v] = true;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        ed[i][k] && ed[k][j] && (ed[i][j] |= true);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    fill (a + 1, a + n + 1, false), fill (b + 1, b + n + 1, false);
    D (i) && ans++;
  }
  put (n - ans);
  for (int i = 1; i <= n; i++) {
    if (!k[i]) { cout << i << ' '; }
  }
  return 0;
}