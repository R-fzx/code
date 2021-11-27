#include <iostream>

using namespace std;
using LL = long long;

const int kN = 2e5 + 1;

int n, k;
LL a[kN], s;

bool C(LL x) {
  LL _s = 0;
  for (LL i : a) _s += min(i, x);
  return _s >= k * x;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i], s += a[i];
  LL l = 0, r = s / k;
  while (l <= r) {
    LL m = l + r >> 1;
    if (C(m)) l = m + 1;
    else r = m - 1;
  }
  cout << r;
  return 0;
}