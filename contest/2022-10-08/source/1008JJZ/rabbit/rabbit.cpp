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
const int kN = 1e3 + 5;

int n;
int main () {
  file ("rabbit");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n, put (n * (n - 1) / 2);
  for (int i = 1; i <= n >> 1; i++) {
    for (int j = 1; j <= n; j++) {
      cout << j << ' ' << (j + i - 1) % n + 1 << ' ' << (j + i * 2 - 1) % n + 1 << '\n';
    }
  }
  return 0;
}