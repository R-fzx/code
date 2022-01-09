#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define N 262147
#define ll long long
#define reg register
#define p 998244353
using namespace std;

inline int power(int a, int t) {
  int res = 1;
  while (t) {
    if (t & 1) res = (ll)res * a % p;
    a = (ll)a * a % p;
    t >>= 1;
  }
  return res;
}

int fac[N], ifac[N], rt[N], rev[N], facm[N];
int siz;

void init(int n) {
  int w, lim = 1;
  while (lim <= n) lim <<= 1, ++siz;
  for (reg int i = 1; i != lim; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (siz - 1));
  w = power(3, (p - 1) >> siz);
  fac[0] = fac[1] = ifac[0] = ifac[1] = rt[lim >> 1] = 1;
  for (reg int i = lim >> 1 | 1; i != lim; ++i) rt[i] = (ll)rt[i - 1] * w % p;
  for (reg int i = (lim >> 1) - 1; i; --i) rt[i] = rt[i << 1];
  for (reg int i = 2; i <= n; ++i) ifac[i] = fac[i] = (ll)fac[i - 1] * i % p;
  ifac[n] = power(fac[n], p - 2);
  for (reg int i = n - 1; i; --i) ifac[i] = (ll)ifac[i + 1] * (i + 1) % p;
}

inline void NTT(int *f, int type, int lim) {
  if (type == -1) reverse(f + 1, f + lim);
  static unsigned long long a[N];
  reg int x, shift = siz - __builtin_ctz(lim);
  for (reg int i = 0; i != lim; ++i) a[rev[i] >> shift] = f[i];
  for (reg int mid = 1; mid != lim; mid <<= 1)
    for (reg int j = 0; j != lim; j += (mid << 1))
      for (reg int k = 0; k != mid; ++k) {
        x = a[j | k | mid] * rt[mid | k] % p;
        a[j | k | mid] = a[j | k] + p - x;
        a[j | k] += x;
      }
  for (reg int i = 0; i != lim; ++i) f[i] = a[i] % p;
  if (type == 1) return;
  x = p - (p - 1) / lim;
  for (reg int i = 0; i != lim; ++i) f[i] = (ll)f[i] * x % p;
}

void lagrange(const int *F, int n, int m, int *R) {  // calculate f(m),f(m+1) ... f(m+n) with f(0),f(1) ... f(n)
  static int f[N], G[N], pre[N], suf[N], inv[N];
  memcpy(f, F, (n + 1) << 2);
  int tmp, k = n << 1 | 1, mul, lim = 1 << (32 - __builtin_clz(n * 3));
  if (m <= n)
    tmp = n - m + 1, m = n + 1;
  else
    tmp = 0;
  facm[0] = 1;
  for (reg int i = 0; i <= n; ++i) facm[0] = (ll)facm[0] * (m - n + i) % p;
  pre[0] = suf[k + 1] = 1;
  for (reg int i = 1; i <= k; ++i) pre[i] = (ll)pre[i - 1] * (m - n + i - 1) % p;
  for (reg int i = k; i; --i) suf[i] = (ll)suf[i + 1] * (m - n + i - 1) % p;
  mul = power(pre[k], p - 2);
  for (reg int i = 1; i <= k; ++i) inv[i] = (ll)mul * pre[i - 1] % p * suf[i + 1] % p;
  for (reg int i = 1; i <= n; ++i) facm[i] = (ll)facm[i - 1] * (m + i) % p * inv[i] % p;
  for (reg int i = 0; i <= n; ++i) {
    f[i] = (ll)f[i] * ifac[i] % p * ifac[n - i] % p;
    if ((n - i) & 1) f[i] = p - f[i];
  }
  for (reg int i = 0; i != k; ++i) G[i] = inv[i + 1];
  memset(f + n + 1, 0, (lim - n) << 2);
  memset(G + k, 0, (lim - k + 1) << 2);
  NTT(f, 1, lim), NTT(G, 1, lim);
  for (reg int i = 0; i != lim; ++i) f[i] = (ll)f[i] * G[i] % p;
  NTT(f, -1, lim);
  memcpy(R, F + n - tmp + 1, tmp << 2);
  for (reg int i = tmp; i <= n; ++i) R[i] = (ll)f[i + n - tmp] * facm[i - tmp] % p;
}

int solve(int n) {
  static int f[N], fd[N], st[30];
  memset(f, 0, sizeof(f));
  int top = 0, s = n;
  while (n) {
    st[++top] = n;
    n >>= 1;
  }
  n = st[top--];
  f[0] = 1, f[1] = s + 1;
  while (top--) {
    lagrange(f, n, n + 1, f + n + 1);
    f[n << 1 | 1] = 0;
    int tmp = (ll)n * power(s, p - 2) % p;
    lagrange(f, n << 1, tmp, fd);
    for (reg int i = 0; i <= (n << 1); ++i) f[i] = (ll)f[i] * fd[i] % p;
    n <<= 1;
    if (!(st[top + 1] & 1)) continue;
    for (reg int i = 0; i <= n; ++i) f[i] = (ll)f[i] * (s * i + n + 1) % p;
    f[n + 1] = 1;
    for (reg int i = 1; i <= n + 1; ++i) f[n + 1] = (ll)f[n + 1] * (s * (n + 1) + i) % p;
    ++n;
  }
  int res = f[0];
  for (reg int i = 1; i != s; ++i) res = (ll)res * f[i] % p;
  return res;
}

inline int factorial(int n) {
  int k = sqrt(n), res;
  res = solve(k);
  for (reg int i = k * k + 1; i <= n; ++i) res = (ll)res * i % p;
  return res;
}

int main() {
  init(150000);
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", factorial(n));
  }
  return 0;
}