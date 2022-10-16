#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 32000;

int t, n, y[N], l, r;
vector<int> e;
unordered_map<int, int> p;

void S() {
  for (int i = 2; i < N; i++) {
    if (!y[i]) {
      e.push_back(i);
      for (int j = 2; i * j < N; j++) {
        y[i * j] = 1;
      }
    }
  }
}

int main() {
  freopen("prime.in", "r", stdin);
  freopen("prime.out", "w", stdout);
  S();
  for (cin >> t; t--; p.clear()) {
    cin >> n;
    for (int i : e) {
      for (int j = max(((n - N) / i + 1) * i, 2 * i); j <= (n + N); j += i) {
        p[j] = 1;
      }
    }
    for (l = n; p[l]; l--) {
    }
    for (r = n + 1; p[r]; r++) {
    }
    ll z = 1ll * l * r - 2 * l - 2 * r + 2 * n + 2, m = 2ll * l * r, g = __gcd(z, m);
    cout << z / g << '/' << m / g << '\n';
  }
  return 0;
}