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
using ll = long long;
const int kN = 855;

ll ans, _a;
int n, a[kN], b[kN];
int main () {
  file ("scalar");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n;
  for_each (a + 1, a + n + 1, [&] (int &x) { cin >> x; }), sort (a + 1, a + n + 1);
  for_each (b + 1, b + n + 1, [&] (int &x) { cin >> x; }), sort (b + 1, b + n + 1, greater <int> ());
  for (int i = 1; i <= n; i++) {
    ans += 1ll * a[i] * b[i];
  }
  put (ans);
  return 0;
}