#include <iostream>
#include <map>

using namespace std;
using LL = long long;

const int kN = 51;
const LL kM = 998244353;

int n, k;
map<LL, LL> f[kN];
LL s, fc[kN];

LL gcd(LL x, LL y) { return y ? gcd(y, x % y) : x; }
LL P(LL b, LL e) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) (e & 1) && (s = s * b % kM);
  return s;
}

int main() {
  cin >> n >> k;
  f[0][1] = fc[0] = 1;
  for (int i = 1; i <= n; ++i) fc[i] = fc[i - 1] * i % kM;
  for (LL i = 0; i < n; ++i) {
    for (auto j : f[i]) {
      for (LL k = 1; i + k <= n; ++k) {
        LL l = k / gcd(k, j.first) * j.first;
        f[i + k][l] = (f[i + k][l] + 1LL * j.second * fc[n - i - 1] % kM * P(fc[n - i - k], kM - 2) % kM) % kM;
      }
    }
  }
  for (auto i : f[n]) s = (s + 1LL * P(i.first, k) * i.second % kM) % kM;
  cout << s;
  return 0;
}
/*
x
y
x*(x-1)*...*(x-y+1)
x!/x-y
(n-i-1)*(n-i-2)*...*(n-i-(k-1))
(n-i-1)!/(n-i-k)!
*/