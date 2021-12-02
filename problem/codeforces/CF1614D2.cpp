#include <iostream>

using namespace std;
using LL = long long;

const int kN = 1e5 + 1, kV = 2e7 + 1;

int n, a[kN], p[kV], c[kV], m[kV];
LL f[kV];

int main() {
  // freopen("CF1614D2.in", "r", stdin);
  // freopen("CF1614D2.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], ++c[a[i]];
  for (int i = 2; i < kV; ++i) {
    f[i] = 1LL * c[i] * i;
    if (!m[i]) {
      for (int j = kV / i; j; --j) c[j] += c[i * j];
      for (int j = 1; i * j < kV; ++j) m[i * j] = i, p[i * j] = i * (j % i ? 1 : p[j]);
    }
  }
  for (int i = kV - 1; i; --i) {
    for (int j = i; j - 1; j /= p[j]) {
      int x = i / m[j];
      f[x] = max(f[x], f[i] + 1LL * (c[x] - c[i]) * x);
    }
  }
  cout << f[1];
  return 0;
}
/*
f[i] = f[j] + (c[i] - c[j]) * i

*/