#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int t, n;

bool prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  freopen("prime.in", "r", stdin);
  freopen("prime.out", "w", stdout);
  for (cin >> t; t--;) {
    cin >> n;
    ll v = n, u = n + 1;
    for (; !prime(v); v--) {
    }
    for (; !prime(u); u++) {
    }
    ll x = v * u - 2 * u + 2 * (n - v + 1), y = 2 * u * v;
    ll g = __gcd(x, y);
    cout << x / g << '/' << y / g << '\n';
  }
  return 0;
}