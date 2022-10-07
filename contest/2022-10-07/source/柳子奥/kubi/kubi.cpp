#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

#define int long long
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using namespace __gnu_pbds;

int read() {
  int x = 0, f = 0; char ch = getchar();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x * 10) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}

typedef __int128 i128;

int T, a, b, k;
vector<int> p;
gp_hash_table<int, int> mp;

int gcd(int m, int n) {
  if (!n) return m;
  int m1 = (m & 1), n1 = (n & 1);
  if (!m1 && !n1) return gcd(m >> 1, n >> 1) << 1;
  if (!m1) return gcd(m >> 1, n);
  if (!n1) return gcd(m, n >> 1);
  return gcd(n, m % n);
}

int qpow(int bs, int idx, int mod) {
  int ret = 1;
  for (; idx; idx >>= 1, bs = (i128)bs * bs % mod) {
    if (idx & 1) ret = (i128)ret * bs % mod;
  }
  return ret % mod;
}

int getm(int &b) {
  int nw = 1;
  if (gcd(b, k) == 1) return 0;
  for (int i = 1; ; ++i) {
    nw = (i128)nw * k % b;
    int d = gcd(b, nw);
    if (nw) b /= d, nw /= d;
    else return i;
    if (gcd(b, k) == 1) return i;
  }
}

int getr(int b) {
  if (b == 1) return 0;
  mp.clear();
  int t = sqrt(b) + 1, nw = 1;
  for (int i = 0; i < t; ++i, nw = ((i128)nw * k) % b) {
    mp[nw] = i;
  }
  k = qpow(k, t, b);
  nw = k;
  for (int i = 1; i <= t; ++i, nw = ((i128)nw * k) % b) {
    if (mp.find(nw) == mp.end()) continue ;
    if (i * t - mp[nw] >= 0) return i * t - mp[nw];
  }
  return -1;
}

signed main() {
  file("kubi");
  cin >> T;
  while (T--) {
    cin >> a >> b >> k;
    int d = gcd(a, b);
    a /= d, b /= d;
    cout << getm(b) << ' ' << getr(b) << endl;
  }
  return 0;
}