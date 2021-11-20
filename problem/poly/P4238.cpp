#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

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
}  // namespace Poly

int n, f[Poly::kN];

int main() {
  // freopen("P4238_16.in", "r", stdin);
  // freopen("P4238.out", "w", stdout);
  n = read();
  // cout << n << endl;
  for (int i = 0; i < n; ++i) f[i] = read();
  // cout << n << endl;
  Poly::invf(f, n);
  // cout << n << endl;
  Poly::print(f, n);
  return 0;
}