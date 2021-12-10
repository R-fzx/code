#include <algorithm>
#include <iostream>

using namespace std;
using Pii = pair<int, int>;

const int kN = 2001;

int a, m, n, f[kN][kN];
Pii p[kN], b[kN];

int main() {
  freopen("CF988F.in", "r", stdin);
  freopen("CF988F.out", "w", stdout);
  cin >> a >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i].first >> b[i].second;
  }
  sort(p + 1, p + n + 1), sort(b + 1, b + m + 1);
  fill(&f[1][0], &f[n][m] + 1, INT32_MAX);
  for (int i = 1; i <= n; ++i) {
    if (b[1].first < p[i].first) {
      for (int j = 1; j <= m; ++j) {
        
      }
    }
  }
  cout << (f[n][m] == INT32_MAX ? -1 : f[n][m]);
  return 0;
}