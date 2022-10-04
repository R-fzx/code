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
const int kN = 105;

int n, f[kN], a[kN], g[kN][kN];
int main () {
  file ("puppet");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  for ( ; cin >> n; ) {
    for_each (a + 1, a + n + 1, [&] (int &x) { cin >> x; }), sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        bool t = true;
        for (int k = 1, _i, _j; k <= j - i + 1; k++) {
          for (_i = i, _j = i + k; _j <= j; _i++, _j++) { 
            a[_j] - a[_i] > 1 && (t = false);
          }
          abs (a[_i] - a[i + k - 1]) <= 1 && (t = false);
          if (!t) {
            g[i][j] = k - 1;
            break;
          }
        }
        t && (g[i][j] = j - i + 1);
      }
    }
    fill (f + 1, f + n + 1, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        f[i] = max (f[i], f[j] + g[j + 1][i]);
      }
    }
    put (f[n]);
  }
  return 0;
}