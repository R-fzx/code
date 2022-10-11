#include <algorithm>
#include <cstring>
#include <iostream>

#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define put(x) (cout << (x) << '\n')
#define file(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)

using namespace std;
const int kN = (1 << 16) + 1, kM = 5e4 + 1, kB = 17;

char c[kM];
int k, ans = 2147483647, len, f[kN][kB], f1[kB][kB], f2[kB][kB];
int main() {
  freopen("permrle.in", "r", stdin);
  freopen("permrle.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> k >> c + 1, len = strlen(c + 1);
  for (int i = 1; i <= len / k; i++) {
    for (int x = 1; x <= k; x++) {
      for (int y = 1; y <= k; y++) {
        if (c[(i - 1) * k + x] != c[(i - 1) * k + y]) {
          f1[x][y]++;
        }
        if (i != len / k && c[(i - 1) * k + x] == c[i * k + y]) {
          f2[x][y]++;
        }
      }
    }
  }
  for (int l = 1; l <= k; l++) {
    memset(f, 0x3f, sizeof(f));
    f[1 << l - 1][l] = len / k;
    for (int i = 0; i < (1 << k); i++) {
      if ((1 << l - 1) & i) {
        for (int r = 1; r <= k; r++) {
          if ((1 << r - 1) & i) {
            for (int x = 1; x <= k; x++) {
              if (!((1 << x - 1) & i)) {
                f[i | (1 << x - 1)][x] = min(f[i | (1 << x - 1)][x], f[i][r] + f1[r][x]);
              }
            }
          }
        }
      }
    }
    for (int y = 1; y <= k; y++) {
      if (l != y) {
        ans = min(ans, f[(1 << k) - 1][y] - f2[l][y]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}

/**
 * author :  Lightwhite
 * time :  2022/10/10 21:10
 */