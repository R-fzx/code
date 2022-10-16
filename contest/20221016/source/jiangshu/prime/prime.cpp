#pragma GCC optimize ("Ofast")
#include <iostream>

using namespace std;
using ll = long long;

int T, n, z, m, fz, fm;

bool isprime (int x) {
  for (int i = 2; i * i <= x; i++) {
    if (!(x % i)) {
      return 0;
    }
  }
  return 1;
}

ll gcd (ll a, ll b) {
  return !b ? a : gcd (b, a % b);
}

int main () {
  freopen ("prime.in", "r", stdin);
  freopen ("prime.out", "w", stdout);
  for (cin >> T; T--; ) {
    cin >> n;
    z = m = n; m++;
    for (; !isprime(z); z--) {
    }
    for (; !isprime(m); m++) {
    }
    fz = 1ll * z * m - 2ll * z - 2ll * (m - n - 1ll);
    fm = 2ll * z * m;
    ll tmp = gcd(fz, fm);
    cout << fz / tmp << "/" << fm / tmp << '\n';
  }
  return 0;
}