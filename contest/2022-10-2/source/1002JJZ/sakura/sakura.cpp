#include <iostream>
#include <algorithm>
#include <cstring>

#define file(x) freopen (x".in", "r", stdin), freopen (x".out", "w", stdout)
#define put(x) cout << x << '\n'
using namespace std;
using ll = long long;
const int kN = 1e6 + 5, kM = 1e9 + 7;

bool t[kN * 10];
ll p[kN * 10], ans = 1;
ll n, tot, c[kN];
int main () {
  file ("sakura");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n, t[0] = t[1] = true;
  for (int i = 2; i <= n; i++) {
    t[i] || (p[++tot] = i);
    for (int j = 1; j <= tot && p[j] * i <= n; j++) {
      t[p[j] * i] = true;
      if (i % p[j] == 0) {
        break;
      }
    }
  }
  for (int i = 1; i <= tot; i++) {
    for (int j = p[i]; j <= n; j *= p[i]) {
      (c[i] += n / j) %= kM;
    }
  }
  for (int i = 1; i <= tot; i++) {
    c[i] && ((ans *= (c[i] * 2 + 1)) %= kM);
  }
  put (ans);
  return 0;
}