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
const int kN = 3e6 + 1, kM = 998244353, kG = 3;
int n, iv[kN << 1], _a[kN << 1], _b[kN << 1], _c[kN << 1];
#define cpy(a, b, n) memcpy(a, b, n * sizeof(int))
#define clr(a, l, r) memset(a + l, 0, (r - l) * sizeof(int))
inline void init(int m) {
  for (n = 1; n <= m;) n <<= 1;
}
int pow(int a, int e = kM - 2) {
  int s = 1;
  for (; e; e >>= 1, a = 1LL * a * a % kM)
    if (e & 1) s = 1LL * s * a % kM;
  return s;
}
void NTT(int a[], bool o) {
  for (int i = 0; i < n; ++i)
    if (i < iv[i]) swap(a[i], a[iv[i]]);
  int _l, u, w, x;
  for (int l = 2; l <= n; l <<= 1)
    for (int i = (_l = l >> 1, u = pow(kG, (kM - 1) / l), 0); i < n; i += l)
      for (int j = (w = 1, i); j < i + _l; ++j) x = 1LL * w * a[j + _l] % kM, a[j + _l] = (a[j] - x + kM) % kM, a[j] = (a[j] + x) % kM, w = 1LL * w * u % kM;
  if (o) return;
  for (int i = (reverse(a + 1, a + n), 0), iv = pow(n, kM - 2); i < n; ++i) a[i] = 1LL * a[i] * iv % kM;
}
void mulf(int a[], int b[], int c[], int na, int nb) {
  init(na + nb);
  for (int i = 0; i < n; ++i) iv[i] = (iv[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
  cpy(c, a, na), cpy(_b, b, nb), clr(c, na, n), clr(_b, nb, n), NTT(c, 1), NTT(_b, 1);
  for (int i = 0; i < n; ++i) c[i] = 1LL * c[i] * _b[i] % kM;
  NTT(c, 0);
}
}  // namespace Poly

int na, nb, a[Poly::kN], b[Poly::kN], c[Poly::kN];

int main() {
  na = read() + 1, nb = read() + 1;
  for (int i = 0; i < na; ++i) a[i] = read();
  for (int i = 0; i < nb; ++i) b[i] = read();
  Poly::mulf(a, b, c, na, nb);
  Poly::print(c, na + nb - 1);
  return 0;
}