#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
using ll = long long;
const int kN = 25;

ll ans;
vector <int> v[kN << 4];
int n, m, k, a[kN][kN], d[kN][kN], ax, f[kN][kN][kN * kN << 2];
void DFS1 (int x, int y, int k) {
  if (x + y == (n + m) / 2 + 1) {
    return v[d[x][y]].push_back (k);
  }
  (x < n && a[x + 1][y]) ? DFS1 (x + 1, y, k ^ a[x][y]) : void ();
  (y < n && a[x][y + 1]) ? DFS1 (x, y + 1, k ^ a[x][y]) : void ();
}
void DFS2 (int x, int y, int s) {
  if (x + y == (n + m) / 2 + 1) {
    int t = s ^ k, r = d[x][y];
    ans = ans + upper_bound (v[r].begin (), v[r].end (), t) - lower_bound (v[r].begin (), v[r].end (), t);
    return ;
  }
  (x > 1 && a[x - 1][y]) ? DFS2 (x - 1, y, s ^ a[x - 1][y]) : void ();
  (y > 1 && a[x][y - 1]) ? DFS2 (x, y - 1, s ^ a[x][y - 1]) : void ();
}
int main () {
  freopen ("maze.in", "r", stdin);
  freopen ("maze.out", "w", stdout);
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j], ax = max (a[i][j], ax), d[i][j] = (i - 1) * m + j;
    }
  }
  DFS1 (1, 1, 0);
  for (int i = 1; i <= d[n][m]; i++) {
    sort (v[i].begin (), v[i].end ());
  }
  DFS2 (n, m, a[n][m]);
  cout << ans << '\n';
  return 0;
}