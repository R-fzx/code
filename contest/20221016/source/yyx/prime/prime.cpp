#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

int t, n;

bool prime(int x) {
  for (int i = 2; i <= sqrt(x); i++) {
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
    if (n == 2) {
      cout << 1 << '/' << 6 << endl;
      continue; 
    }
    long long v = n, u = n + 1;
    while (!prime(v)) {
      v--;
    }
    while (!prime(u)) {
      u++;
    }
    long long x = v * u - 2 * u + 2 * (n - v + 1), y = 2 * v * u;
    long long z = __gcd(x, y);
    x /= z, y /= z;
    cout << x << '/' << y << endl;
  }  
  return 0;
}
