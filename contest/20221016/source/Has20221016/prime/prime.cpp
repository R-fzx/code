#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

ll t, n;

bool P(ll x) {
  for (ll i = 2; i <= x / i; ++i) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  freopen("prime.in", "r", stdin);
  freopen("prime.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    ll u = n + 1, v = n;
    while (!P(u)) {
      ++u;
    }
    while (!P(v)) {
      --v;
    }
    ll fz = u * v - 2 * v - 2 * (u - n - 1), fm = 2 * u * v, g = __gcd(fz, fm);
    cout << fz / g << '/' << fm / g << '\n';
  }
  return 0;
}