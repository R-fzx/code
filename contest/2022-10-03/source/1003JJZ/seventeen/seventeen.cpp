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
const int kN = 255;

bool f[kN * kN];
int n, mx, hx, hy, X[kN], Y[kN], ans;
int main () {
  file ("seventeen");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> X[i] >> Y[i];
    hx += X[i], hy += Y[i], ans -= X[i] * X[i] + Y[i] * Y[i];
  }
  memset (f, false, sizeof (f)), f[0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = hx / 2; j >= X[i]; j--) {
      f[j] |= f[j - X[i]];
    }
  }
  for (int i = 1; i <= hx / 2; i++) {
    f[i] && (mx = i);
  }
  ans += (hx - 2 * mx) * (hx - 2 * mx);
  memset (f, false, sizeof (f)), f[0] = true, mx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = hy / 2; j >= Y[i]; j--) {
      f[j] |= f[j - Y[i]];
    }
  }
  for (int i = 1; i <= hy / 2; i++) {
    f[i] && (mx = i);
  }
  ans += (hy - 2 * mx) * (hy - 2 * mx);
  cout << fixed << setprecision (2) << ans * 0.5 << '\n';
  return 0;
}

/*

*/