#include <iostream>

using namespace std;
using LL = long long;

const LL kM = 998244353;

LL n, k, m;

LL P(LL b, LL e, LL m) {
  LL s = 1;
  for (b %= m; e; e >>= 1, b = b * b % m) if (e & 1) s = s * b % m;
  return s;
}

int main() {
  cin >> n >> k >> m;
  cout << (m % kM ? P(m, P(k, n, kM - 1), kM) : 0);
  return 0;
}