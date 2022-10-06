#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define put(x) (cout << (x) << '\n')
#define file(x) freopen (x".in", "r", stdin), freopen (x".out", "w", stdout)

using namespace std;
const int kN = 202, kM = 402;

// tn (x) => min (x, n) + 201
int n, a[kN], l, k;
double f[kN][kN][kM], p[kN], ans = 0.0;
int main () {
  file ("guard");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n >> l >> k;
  for (int i = 1, x; i <= n; i++) {
    cin >> x, p[i] = x / 100.0;
  }
  for_each (a + 1, a + n + 1, [&] (int &x) { cin >> x; });
  f[0][0][min (k, n) + 201] = 1.0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int q = -i; q <= n; q++) {
        f[i + 1][j + 1][min (q + a[i + 1], n) + 201] += 
          f[i][j][min (q, n) + 201] * p[i + 1];
        f[i + 1][j][min (q, n) + 201] += f[i][j][min (q, n) + 201] * 
          (1.0 - p[i + 1]);
      }
    }
  }
  for (int i = l; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      ans += f[n][i][min (j, n) + 201];
    }
  }
  cout << fixed << setprecision (6) << ans << '\n';
  return 0;
}
/*
卧槽怎么突然黑屏啊
吓死我了我朝
*/