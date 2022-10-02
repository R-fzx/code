#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

#define file(x) freopen (x".in", "r", stdin), freopen (x".out", "w", stdout)
#define put(x) cout << x << '\n'
using namespace std;
const int kN = 1e3 + 5;

double ans = 0.0;
int n, h[kN], r[kN];
int main () {
  file ("queue");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n;
  for (int i = 1, x; i <= n; i++) { 
    cin >> x, h[x]++;
  }
  for (int i = 1; i <= int (1e3); i++) {
    for (int j = 1; j <= i; j++) {
      r[j] += h[i];
    }
  }
  for (int i = 1; i <= int (1e3); i++) {
    ans += 1.0 * h[i] * (n + 1) / (r[i] + 1);
  }
  cout << fixed << setprecision (2), put (ans);
  return 0;
}