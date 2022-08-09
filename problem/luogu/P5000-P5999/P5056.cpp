#include <iostream>
#include <unordered_map>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 12;

int n, m, ei, ej;
bool a[kN][kN];
unordered_map<int, LL> f[2];
LL ans;

int G(int x, int i) { return x >> i * 2 & 3; }
int S(int x, int i, int v) { return x ^ (G(x, i) << i * 2) ^ (v << i * 2); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      if (a[i][j] = c == '.') {
        ei = i, ej = j;
      }
    }
  }
  f[0][0] = 1;
  for (int i = 0, k = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j, k ^= 1) {
      f[k].clear();
      for (auto [x, v] : f[k ^ 1]) {
        int l = G(x, m), u = G(x, j);
        if (a[i][j]) {
          int _x = S(S(x, j, 0), m, 0);
          if (l == 1 && u == 1) {
            int p = j;
            for (int c = 1; c; ++p, c += (G(x, p) == 2 ? -1 : G(x, p))) {
            }
            f[k][S(_x, p, 1)] += v;
          } else if (l == 2 && u == 1) {
            f[k][_x] += v;
          } else if (l == 1 && u == 2) {
            if (i == ei && j == ej && !_x) {
              ans += v; 
            }
          } else if (l == 2 && u == 2) {
            int p = j;
            for (int c = -1; c; --p, c += (G(x, p) == 2 ? -1 : G(x, p))) {
            }
            f[k][S(_x, p, 2)] += v;
          } else if (!l && !u) {
            if (j + 1 < m && i + 1 < n) {
              f[k][S(S(x, j, 1), m, 2)] += v;
            }
          } else if (l && !u) {
            if (j + 1 < m) {
              f[k][x] += v;
            }
            if (i + 1 < n) {
              f[k][S(S(x, j, l), m, 0)] += v;
            }
          } else if (!l && u) {
            if (j + 1 < m) {
              f[k][S(S(x, j, 0), m, u)] += v;
            }
            if (i + 1 < n) {
              f[k][x] += v;
            }
          }
        } else {
          if (!l && !u) {
            f[k][x] += v;
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
/*
100
102
*/