#include <iostream>

using namespace std;
using LL = long long;

const int kN = 2e5 + 1;

string sr;
LL n, a[kN], k, s[kN];

LL S(LL l, LL r) { return s[r] - s[l - 1]; }
bool C(LL x) {
  LL _s = INT64_MAX;
  for (LL i = 1, j; (j = i + x - 1) <= n; ++i) {
    LL m = i + j + 1 >> 1;
    _s = min(_s, S(m + 1, j) - a[m] * (j - m) + a[m] * (m - i + 1) - S(i, m));
  }
  return _s <= k;
}

int main() {
  cin >> sr >> k;
  for (LL i = 0; i < sr.size(); ++i) {
    if (sr[i] == 'Y') {
      ++n, s[n] = s[n - 1] + (a[n] = i - n + 1);
    }
  }
  LL l = 1, r = n;
  while (l <= r) {
    LL m = l + r >> 1;
    if (C(m)) l = m + 1;
    else r = m - 1;
  }
  cout << r;
  return 0;
}