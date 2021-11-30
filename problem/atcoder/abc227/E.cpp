#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using LL = long long;

const int kN = 32;

string s;
int k, n, c[3];
LL f[kN][kN][kN][kN * kN];
vector<int> p[3];

int main() {
  cin >> s >> k;
  n = s.size(), k = min(k, n * n);
  for (int i = 0; i < n; ++i) p[(s[i] != 'K') + (s[i] == 'Y')].push_back(i + 1);
  f[0][0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (c[0] = max(0, int(i - p[1].size() - p[2].size())); c[0] <= min(int(p[0].size()), i); ++c[0]) {
      for (c[1] = max(0, int(i - c[0] - p[2].size())); c[1] <= min(int(p[1].size()), i - c[0]); ++c[1]) {
        c[2] = i - c[0] - c[1];
        for (int j = 0; j < 3; ++j) {
          if (c[j] < p[j].size()) {
            int _c = p[j][c[j]] - i - 1;
            for (int u = 0; u < 3; ++u)
              for (int v = 0; v < c[u]; ++v) _c += p[u][v] > p[j][c[j]];
            for (int u = _c; u <= k; ++u) f[i + 1][c[0] + (j == 0)][c[1] + (j == 1)][u] += f[i][c[0]][c[1]][u - _c];
          }
        }
      }
    }
  }
  LL s = 0;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      for (int u = 0; u <= k; ++u) s += f[n][i][j][u];
  cout << s;
  return 0;
}
/*
a,b,c,d

(x==a||x==b)?(x==b):2+(x==d)
(x!=a&&x!=b)?2+(x==d):(x==b)
((x==c||x==d)<<1)+(x==b||x==d)

*/