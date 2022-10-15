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
const int kN = 15;

double ans = 0.0;
int n, k, p, a[kN], b[kN];
double F (int x, int g, int s) {
  if (x > n) {
    if (2 * g > n) {
      return 1.0;
    } else {
      return 1.0 * p / (1.0 * p + s);
    }
  }
  return 1.0 * b[x] / 100 * F (x + 1, g + 1, s) + 1.0 * (1 - (b[x] / 100.0)) * F (x + 1, g, s + a[x]);
}
void D (int d, int c) {
  if (d == n) {
    b[d] += c * 10;
    b[d] <= 100 && (ans = max (ans, F (1, 0, 0)));
    b[d] -= c * 10;
    return ;
  }
  for (int i = 0; i <= c; i++) {
    b[d] += 10 * i;
    if (b[d] <= 100) {
      D (d + 1, c - i);
    } else {
      b[d] -= 10 * i;
      break;
    }
    b[d] -= 10 * i;
  }
}
int main () {
  file ("assembly");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n >> k >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  D (1, k);
  cout << fixed << setprecision (6) << ans << '\n';
  return 0;
}