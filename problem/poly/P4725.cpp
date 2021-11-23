#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <numeric>

using namespace std;

inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x;
}

namespace Poly {
using LL = long long;
void print(int a[], int m) {
  for (int i = 0; i < m; ++i) cout << a[i] << " ";
  puts("");
}
const int kN = 1e6 + 1, kM = 998244353, kG = 3;
int n, ip[kN];
#define clr(a, l, r) memset(a + (l), 0, ((r) - (l)) * sizeof(int))
#define cpy(a, b, m) memcpy(a, b, (m) * sizeof(int)), clr(a, m, n)
void init(int m) {
  for (n = 1; n <= m;) n <<= 1;
  for (int i = 0; i < n; ++i) ip[i] = (ip[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
}
int pow(int a, int e = kM - 2) {
  int s = 1;
  for (; e; e >>= 1, a = 1LL * a * a % kM) (e & 1) && (s = 1LL * s * a % kM);
  return s;
}
void NTT(int a[], bool o) {
  for (int i = 0; i < n; ++i)
    if (i < ip[i]) swap(a[i], a[ip[i]]);
  int _l, u, w, x;
  for (int l = 2; l <= n; l <<= 1)
    for (int i = (_l = l >> 1, u = pow(kG, (kM - 1) / l), 0); i < n; i += l)
      for (int j = (w = 1, i); j < i + _l; ++j) x = 1LL * w * a[j + _l] % kM, a[j + _l] = (a[j] - x + kM) % kM, a[j] = (a[j] + x) % kM, w = 1LL * w * u % kM;
  if (o) return;
  for (int i = (reverse(a + 1, a + n), 0), ivn = pow(n); i < n; ++i) a[i] = 1LL * a[i] * ivn % kM;
}
void mulf(int a[], int b[], int c[], int na, int nb) {
  static int _a[kN];
  init(na + nb), clr(_a, 0, n), cpy(c, a, na), cpy(_a, b, nb), NTT(c, 1), NTT(_a, 1);
  for (int i = 0; i < n; ++i) c[i] = 1LL * c[i] * _a[i] % kM;
  NTT(c, 0);
}
void invf(int a[], int b[], int m) {
  static int _a[kN];
  for (int l = (init(m << 1), clr(_a, 0, n), clr(b, 0, n), b[0] = pow(a[0]), 2); l <= m << 1; NTT(b, 0), clr(b, l, n), l <<= 1)
    for (int i = (init(l << 1), cpy(_a, a, l), NTT(_a, 1), NTT(b, 1), 0); i < n; ++i) b[i] = 1LL * (2 - 1LL * _a[i] * b[i] % kM + kM) * b[i] % kM;
}
void dvtf(int a[], int b[], int m) {
  for (int i = (b[m - 1] = 0, 1); i < m; ++i) b[i - 1] = 1LL * a[i] * i % kM;
}
int iv[kN] = {0, 1}, ivn = 1;
void ivpre(int m) {
  for (int i = ivn + 1; i <= m; ++i) iv[i] = 1LL * (kM - kM / i) * iv[kM % i] % kM;
  ivn = max(ivn, m);
}
void itgf(int a[], int b[], int m) {
  for (int i = (b[0] = 0, ivpre(m - 1), 1); i < m; ++i) b[i] = 1LL * a[i - 1] * iv[i] % kM;
}
void lnf(int a[], int b[], int m) {
  static int _a[kN], _b[kN];
  init(m), clr(_a, 0, n), clr(_b, 0, n), invf(a, _a, m), dvtf(a, b, m), mulf(_a, b, _b, m, m), itgf(_b, b, m);
}
}  // namespace Poly

int n, f[Poly::kN], g[Poly::kN];

int main() {
  n = read();
  for (int i = 0; i < n; ++i) f[i] = read();
  Poly::lnf(f, g, n);
  // cout << n << endl;
  Poly::print(g, n);
  return 0;
}