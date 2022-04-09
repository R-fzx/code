#include <iostream>

using namespace std;
using LL = long long;

const LL kM = 998244353;

LL p, ans = 1;

LL Gp(LL x) {
  LL s = x;
  for (LL i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      for (s = s / i * (i - 1); x % i == 0; x /= i) {
      }
    }
  }
  if (x > 1) {
    s = s / x * (x - 1);
  }
  return s % kM;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> p;
  --p;
  for (LL i = 1; i * i <= p; ++i) {
    if (p % i == 0) {
      ans = (ans + (p / i) % kM * Gp(p / i) % kM) % kM;
      if (i * i != p) {
        ans = (ans + i % kM * Gp(i) % kM) % kM;
      }
    }
  }
  cout << ans;
  return 0;
}