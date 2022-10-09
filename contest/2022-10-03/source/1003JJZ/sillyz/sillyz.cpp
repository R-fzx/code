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
// const int kN = ;

int f[int (1e6 + 5)], a, b;
int main () {
  file ("sillyz");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  for (int i = 1, p = 1; i <= int (1e6); i++, p = i) {
    long long x = i;
    for (f[i] += f[i - 1]; p; x *= p % 10, p /= 10) {}
    x < int (1e6) && (f[x]++);
  }
  cin >> a >> b;
  cout << f[b] - f[a - 1] << '\n';
  return 0;
}