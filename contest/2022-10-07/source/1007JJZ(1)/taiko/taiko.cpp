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
const int kN = 3e3 + 5;

bool t[kN];
int n, k, a[kN];
bool D (int p, int d) {
  if (t[p]) { return false; }
  t[p] = true, a[d] = p & 1;
  if (d == n || D ((p << 1) & (n - 1), d + 1) || D ((p << 1 | 1) & (n - 1), d + 1)) { return true; }
  return t[p] = false;
}
int main () {
  file ("taiko");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> k, n = 1 << k, D (n - 2, 1), cout << n << ' ';
  for (int i = 1; i <= n; i++) {
    cout << a[i];
  }
  put ("");
  return 0;
}