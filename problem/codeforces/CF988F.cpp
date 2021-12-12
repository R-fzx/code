#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;
using Pii = pair<int, int>;

const int kN = 2002;

int a, m, n, f[kN][kN], d[kN];
Pii p[kN], b[kN];
bool v[kN];

int main() {
  // freopen("CF988F.in", "r", stdin);
  // freopen("CF988F.out", "w", stdout);
  cin >> a >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i].first >> p[i].second;
    fill(v + p[i].first, v + p[i].second, 1);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i].first >> b[i].second;
  }
  fill(&f[0][1], &f[a][m] + 1, 1 << 30), iota(d, d + m + 1, 0);
  for (int i = 0; i <= a; ++i) {
    int mx = *min_element(&f[i][0], &f[i][m] + 1);
    for_each(d, d + m + 1, [i, mx](int j) { f[i][j] = (!j || b[j].first == i ? mx : f[i][j]); });
    for_each(d, d + m + 1, [i](int j) { f[i + 1][j] = min(f[i + 1][j], j || !v[i] ? f[i][j] + b[j].second : INT32_MAX); });
  }
  cout << (f[a][0] == (1 << 30) ? -1 : f[a][0]);
  return 0;
}
/*

*/