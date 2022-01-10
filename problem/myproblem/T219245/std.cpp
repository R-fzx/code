#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;
using LL = long long;

const int kN = 262147, kM = 998244353;

LL x, y;
unordered_map<LL, LL> f;
int fac[kN], ifac[kN], rt[kN], rev[kN], facm[kN], siz;

int P(int b, int e) {
  int s = 1;
  for (; e; e >>= 1, b = (LL)b * b % kM) {
    (e & 1) && (s = (LL)s * b % kM);
  }
  return s;
}
void NTT(int *f, int type, int lim) {
  if (type == -1) {
    reverse(f + 1, f + lim);
  }
  static unsigned long long a[kN];
  int x, shift = siz - __builtin_ctz(lim);
  for (int i = 0; i != lim; ++i) {
    a[rev[i] >> shift] = f[i];
  }
  for (int mid = 1; mid != lim; mid <<= 1) {
    for (int j = 0; j != lim; j += (mid << 1)) {
      for (int k = 0; k != mid; ++k) {
        x = a[j | k | mid] * rt[mid | k] % kM, a[j | k | mid] = a[j | k] + kM - x, a[j | k] += x;
      }
    }
  }
  for (int i = 0; i != lim; ++i) {
    f[i] = a[i] % kM;
  }
  if (type == 1) {
    return;
  }
  x = kM - (kM - 1) / lim;
  for (int i = 0; i != lim; ++i) {
    f[i] = (LL)f[i] * x % kM;
  }
}
void L(const int *F, int n, int m, int *R) {
  static int f[kN], G[kN], pre[kN], suf[kN], inv[kN];
  memcpy(f, F, (n + 1) << 2);
  int tmp, k = n << 1 | 1, mul, lim = 1 << (32 - __builtin_clz(n * 3));
  tmp = max(n - m + 1, 0), m = max(m, n + 1), facm[0] = 1;
  for (int i = 0; i <= n; ++i) {
    facm[0] = (LL)facm[0] * (m - n + i) % kM;
  }
  pre[0] = suf[k + 1] = 1;
  for (int i = 1; i <= k; ++i) {
    pre[i] = (LL)pre[i - 1] * (m - n + i - 1) % kM;
  }
  for (int i = k; i; --i) {
    suf[i] = (LL)suf[i + 1] * (m - n + i - 1) % kM;
  }
  mul = P(pre[k], kM - 2);
  for (int i = 1; i <= k; ++i) {
    inv[i] = (LL)mul * pre[i - 1] % kM * suf[i + 1] % kM;
  }
  for (int i = 1; i <= n; ++i) {
    facm[i] = (LL)facm[i - 1] * (m + i) % kM * inv[i] % kM;
  }
  for (int i = 0; i <= n; ++i) {
    f[i] = (LL)f[i] * ifac[i] % kM * ifac[n - i] % kM;
    if ((n - i) & 1) {
      f[i] = kM - f[i];
    }
  }
  for (int i = 0; i != k; ++i) {
    G[i] = inv[i + 1];
  }
  memset(f + n + 1, 0, (lim - n) << 2), memset(G + k, 0, (lim - k + 1) << 2), NTT(f, 1, lim), NTT(G, 1, lim);
  for (int i = 0; i != lim; ++i) {
    f[i] = (LL)f[i] * G[i] % kM;
  }
  NTT(f, -1, lim), memcpy(R, F + n - tmp + 1, tmp << 2);
  for (int i = tmp; i <= n; ++i) {
    R[i] = (LL)f[i + n - tmp] * facm[i - tmp] % kM;
  }
}
int F(int n) {
  if (n == 0) {
    return 1;
  }
  int k = sqrt(n);
  static int f[kN], fd[kN], st[30];
  memset(f, 0, sizeof(f));
  int top = 0, s = k;
  while (k) {
    st[++top] = k, k >>= 1;
  }
  k = st[top--], f[0] = 1, f[1] = s + 1;
  while (top--) {
    L(f, k, k + 1, f + k + 1), f[k << 1 | 1] = 0;
    int tmp = (LL)k * P(s, kM - 2) % kM;
    L(f, k << 1, tmp, fd);
    for (int i = 0; i <= (k << 1); ++i) {
      f[i] = (LL)f[i] * fd[i] % kM;
    }
    k <<= 1;
    if (!(st[top + 1] & 1)) {
      continue;
    }
    for (int i = 0; i <= k; ++i) {
      f[i] = (LL)f[i] * (s * i + k + 1) % kM;
    }
    f[k + 1] = 1;
    for (int i = 1; i <= k + 1; ++i) {
      f[k + 1] = (LL)f[k + 1] * (s * (k + 1) + i) % kM;
    }
    ++k;
  }
  int res = f[0];
  for (int i = 1; i != s; ++i) {
    res = (LL)res * f[i] % kM;
  }
  for (int i = k * k + 1; i <= n; ++i) {
    res = (LL)res * i % kM;
  }
  return res;
}
LL S(LL x, LL y) {
  LL s = 1, vf = P(f[x - y - 1], kM - 2);
  for (LL i = 2; i <= y; ++i) {
    s = s * P(i, f[x - i - 1] * vf % kM * P(f[y - i], kM - 2) % kM) % kM;
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int w, lim = 1;
  while (lim <= 150000) {
    lim <<= 1, ++siz;
  }
  for (int i = 1; i != lim; ++i) {
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (siz - 1));
  }
  w = P(3, (kM - 1) >> siz), fac[0] = fac[1] = ifac[0] = ifac[1] = rt[lim >> 1] = 1;
  for (int i = lim >> 1 | 1; i != lim; ++i) {
    rt[i] = (LL)rt[i - 1] * w % kM;
  }
  for (int i = (lim >> 1) - 1; i; --i) {
    rt[i] = rt[i << 1];
  }
  for (int i = 2; i <= 150000; ++i) {
    ifac[i] = fac[i] = (LL)fac[i - 1] * i % kM;
  }
  ifac[150000] = P(fac[150000], kM - 2);
  for (int i = 150000 - 1; i; --i) {
    ifac[i] = (LL)ifac[i + 1] * (i + 1) % kM;
  }
  for (int i = 1; i <= 55; ++i) {
    
  }
  cin >> x >> y;
  if (x < y) {
    cout << 0;
    return 0;
  }
  if (x == y) {
    cout << y;
    return 0;
  }
  for (LL i = 0, s = 1; i <= y - 2; s = s * ++i % kM) {
    f[i] = s;
  }
  for (LL i = x - y - 1, s = F(x - y - 1); i <= x - 3; s = s * ++i % kM) {
    f[i] = s;
  }
  cout << S(x, y) << endl;
  return 0;
}