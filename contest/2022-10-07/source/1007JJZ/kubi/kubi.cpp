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
const int kN = 1e5 + 5;

int T, l[kN];
ll a, b, k, t, p[2];
int main () {
  file ("kubi");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  for (cin >> T; T; T--) {
    memset (l, 0, sizeof (l)), cin >> a >> b >> k;
    t = __gcd (a, b), a /= t, b /= t, p[1] = a, l[p[1]] = 1;
    for (int i = 2; ; i++) {
      p[i & 1] = p[(i - 1) & 1] * k % b;
      if (!p[i & 1]) {
        cout << i - 1 << ' ' << 0 << '\n';
        break;
      } else if (!l[p[i & 1]]) { 
        l[p[i & 1]] = i;
      } else {
        cout << l[p[i & 1]] - 1 << ' ' << i - l[p[i & 1]] << '\n';
        break;
      }
    } 
  }
  return 0;
}