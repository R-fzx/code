#include <bits/stdc++.h>

using namespace std;

inline long long gcd(long long a, long long b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, k, x;
    cin >> a >> b >> k;
    x = gcd(a, b);
    a /= x, b /= x;
    
  }
  return 0;
}