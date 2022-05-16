#include <atcoder/all>

using namespace std;
using namespace atcoder;

const int kN = 51;

int n, m, d[kN][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    d[x][y] = 1, d[y][x] = -1;
  }
  for (int i = 1; i <= n; ++i) {
    int w = -1;
    for (int j = 1; j <= n; ++j) {
      w += d[i][j] != -1;
    }
    if (w) {
      int s = n * (n - 1) / 2 + n + 1, t = s + 1;
      mf_graph<int> g(t + 1);
      int c = n;
      for (int j = 1; j <= n; ++j) {
        g.add_edge(j, t, w - (j != i));
        for (int k = j + 1; k <= n; ++k) {
          ++c;
          g.add_edge(s, c, 1);
          if (d[j][k] != -1) {
            g.add_edge(c, j, 1);
          }
          if (d[k][j] != -1) {
            g.add_edge(c, k, 1);
          }
        }
      }
      if (g.flow(s, t) == n * (n - 1) / 2) {
        cout << i << " ";
      }
    }
  }
  return 0;
}