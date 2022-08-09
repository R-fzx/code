#include <iostream>
#include <map>
#define LL long long

using namespace std;

int n, m, ex, ey;
bool b[13][13];
char ch;
map<int, LL> f[2];

int main() {
  freopen("plug2.in", "r", stdin);
  freopen("plug.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> ch;
      if (ch == '.') {
        b[i][j] = 1, ex = i, ey = j;
      }
    }
  }
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (auto [s, t] : f[0]) {
        int d = s >> j * 2 & 3, r = s & 3, _s = s ^ d << j * 2 ^ r;
        if (b[i][j]) {
          if (!d && !r) {
            i < n&& j <= m && (f[1][_s | 2 << j * 2 | 3] += f[0][s]);
          } else if (d && r) {
            if (d == r) {
              if (d == 2) {
                int p = j, q = 1;
                for (; p <= m && q; p++, q += (s >> p * 2 & 3) == 2 - ((s >> p * 2 & 3) == 3)) {
                  _s ^= (_s >> p * 2 & 3) << p * 2;
                }
                if (p <= m) {
                  _s ^= (_s >> p * 2 & 3) << p * 2;
                  f[1][_s | 2 << p * 2] += f[0][s];
                }
              } else {
                int p = j, q = -1;
                for (; p >= 1 && q; p--, q += (s >> p * 2 & 3) == 2 - ((s >> p * 2 & 3) == 3)) {
                  _s ^= (_s >> p * 2 & 3) << p * 2;
                }
                if (p >= 1) {
                  _s ^= (_s >> p * 2 & 3) << p * 2;
                  f[1][_s | 3 << p * 2] += f[0][s];
                }
              }
            } else if (d == 2) {
              f[1][_s] += f[0][s];
            } else if (i == ex && j == ey && !_s) {
              f[1][_s] += f[0][s];
            }
          } else {
            (d && i < n || r && j < m) && (f[1][s] += f[0][s]);
            (d && j < m || r && i < n) && (f[1][s ^ d + r << j * 2 ^ d + r] += f[0][s]);
          }
        } else if (!d && !r) {
          f[1][s] += f[0][s];
        }
      }
      f[0] = f[1], f[1].clear();
    }
  }
  cout << f[0][0];
  return 0;
}
