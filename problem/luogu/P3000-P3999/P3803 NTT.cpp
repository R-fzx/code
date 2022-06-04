#include <iostream>
#include <ctime>

using namespace std;
using LL = long long;

const int kN = 1 << 21;
const LL kM = 998244353;
const int kG = 3;

LL P(LL b, LL e = kM - 2) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) (e & 1) && (s = s * b % kM);
  return s;
}
const LL kIG = P(kG);

int n, m, r[kN], In;
LL f[kN], g[kN];

void NTT(LL *f, int s) {
  for (int i = 0; i < n; ++i) i < r[i] && (swap(f[i], f[r[i]]), 0);
  for (int l = 2; l <= n; l <<= 1) {
    int _l = l >> 1, u = P(~s ? kG : kIG, (kM - 1) / l);
    for (int i = 0; i < n; i += l) {
      LL w = 1, x;
      for (int j = i; j < i + _l; w = w * u % kM, ++j) x = w * f[j + _l] % kM, f[j + _l] = f[j] - x, f[j + _l] < 0 && (f[j + _l] += kM), f[j] = f[j] + x, f[j] > kM && (f[j] -= kM);
    }
  }
}

int main() {
  // freopen("P3803.in", "r", stdin);
  cin >> n >> m, ++n, ++m;
  for (int i = 0; i < n; ++i) cin >> f[i];
  for (int i = 0; i < m; ++i) cin >> g[i];
  for (m += n, n = 1; n < m;) n <<= 1;
  for (int i = 0; i < n; ++i) r[i] = (r[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
  NTT(f, 1), NTT(g, 1);
  for (int i = 0; i < n; ++i) f[i] = f[i] * g[i] % kM;
  NTT(f, -1), In = P(n);
  for (int i = 0; i < m - 1; ++i) cout << f[i] * In % kM << " ";
  return 0;
}