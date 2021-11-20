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
using uLL = unsigned long long;
template <typename T>
inline void print(T *f, int n) {
  for (int i = 0; i < n; ++i) cout << f[i] << " ";
  puts("");
}
#define clr(f, n) memset(f, 0, (n) * sizeof(int))
#define cpy(f, g, n) memcpy(f, g, (n) * sizeof(int))
#define rev(f, n) reverse(f, f + n)
const int _G = 3, _iG = 332748118, kM = 998244353, kN = 3e5 + 1;
LL Pow(LL b, LL e = kM - 2) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) (e & 1) && (s = s * b % kM);
  return s;
}
int r[kN], rn;
inline void rpre(int n) {
  if (rn == n) return;
  rn = n;
  for (int i = 0; i < n; ++i) r[i] = (r[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
}
inline void ptx(int *f, int *g, int n) {
  for (int i = 0; i < n; ++i) f[i] = 1LL * f[i] * g[i] % kM;
}
inline int get(int x) {
  int n = 1;
  while (n < x) n <<= 1;
  return n;
}
void NTT(int *g, int n, bool o) {
  rpre(n);
  static uLL f[kN << 1], w[kN << 1] = {1};
  for (int i = 0; i < n; ++i) f[i] = (((LL)kM << 5) + g[r[i]]) % kM;
  for (int l = 1; l < n; l <<= 1) {
    uLL u = Pow(o ? _iG : _G, (kM - 1) / (l << 1));
    for (int i = 1; i < l; ++i) w[i] = w[i - 1] * u % kM;
    for (int i = 0; i < n; i += l << 1)
      for (int j = 0; j < l; ++j) {
        int y = i | j, x = w[j] * f[y | l] % kM;
        f[y | l] = f[y] + kM - x, f[y] += x;
      }
    if (l == 1024)
      for (int i = 0; i < n; ++i) f[i] %= kM;
  }
  for (int i = 0; i < n; ++i) g[i] = f[i] % kM;
  if (o) {
    uLL p = Pow(n);
    for (int i = 0; i < n; ++i) g[i] = g[i] * p % kM;
  }
}
void muil(int *f, int *g, int m, int l) {
  static int v[kN << 1];
  int n = get(m << 1);
  clr(v, n), cpy(v, g, n), NTT(f, n, 0), NTT(v, n, 0), ptx(f, v, n), NTT(f, n, 1), clr(f + l, n - l), clr(v, n);
}
void invf(int *g, int m) {
  int n = get(m);
  static int w[kN << 1], r[kN << 1], f[kN << 1];
  w[0] = Pow(g[0]);
  for (int l = 2; l <= n; l <<= 1) {
    cpy(r, w, l >> 1), cpy(f, g, l), NTT(f, l, 0), NTT(r, l, 0), ptx(r, f, l), NTT(r, l, 1), clr(r, l >> 1), cpy(f, w, l), NTT(f, l, 0), NTT(r, l, 0), ptx(r, f, l), NTT(r, l, 1);
    for (int i = (l >> 1); i < l; ++i) w[i] = (w[i] * 2LL - r[i] + kM) % kM;
  }
  cpy(g, w, m), clr(f, n), clr(w, n), clr(r, n);
}
int iv[kN] = {0, 1}, ivn = 1;
void init(int n) {
  if (n <= ivn) return;
  for (int i = ivn + 1; i <= n; ++i) iv[i] = 1LL * iv[kM % i] * (kM - kM / i) % kM;
  ivn = n;
}
void divt(int *f, int n) {
  for (int i = 1; i < n; ++i) f[i - 1] = 1LL * f[i] * i % kM;
  f[n - 1] = 0;
}
void iteg(int *f, int n) {
  for (int i = n; i; --i) f[i] = 1LL * f[i - 1] * iv[i] % kM;
  f[0] = 0;
}
void sqrf(int *f, int m) {
  int n = get(m);
  static int b[kN << 1] = {1}, d[kN << 1];
  for (int l = 2; l <= n; l <<= 1) {
    for (int i = 0; i < (l >> 1); ++i) d[i] = (b[i] << 1) % kM;
    invf(d, l), NTT(b, l, 0), ptx(b, b, l), NTT(b, l, 1);
    for (int i = 0; i < l; ++i) b[i] = (b[i] + f[i]) % kM;
    muil(b, d, l, l);
  }
  cpy(f, b, m), clr(b, n << 1), clr(d, n << 1);
}
void divf(int *f, int *g, int n, int m) {
  int l = n - m + 1;
  static int b[kN << 1], d[kN << 1];
  rev(f, n), cpy(b, f, l), rev(f, n), rev(g, m), cpy(d, g, l), rev(g, m), invf(d, l), muil(d, b, l, l), rev(d, l), muil(g, d, n, n);
  for (int i = 0; i < m - 1; ++i) g[i] = (f[i] - g[i] + kM) % kM;
  clr(g + m - 1, l), cpy(f, d, l), clr(f + l, n - l);
}
}  // namespace Poly

int n, m, f[Poly::kN], g[Poly::kN];

int main() {
  n = read(), m = read();
  for (int i = 0; i <= n; ++i) f[i] = read();
  for (int i = 0; i <= m; ++i) g[i] = read();
  Poly::divf(f, g, n, m), Poly::print(f, n - m + 1), Poly::print(g, m);
  return 0;
}