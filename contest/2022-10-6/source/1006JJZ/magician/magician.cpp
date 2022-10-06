#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>

#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define put(x) (cout << (x) << '\n')
#define file(x) freopen (x".in", "r", stdin), freopen (x".out", "w", stdout)

using namespace std;
const int kN = 2e5 + 5, kM = 1e9 + 9;

int n, m, fa[kN], ans;
int R (int x) {
  return x == fa[x] ? x : fa[x] = R (fa[x]);
}
int main () {
  file ("magician");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n >> m, iota (fa, fa + n, 0);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    int fu = R (u), fv = R (v);
    if (fu != fv) {
      fa[fu] = fv;
    } else {
      (ans += ans + 1) %= kM;
    }
    put (ans);
  }
  return 0;
}