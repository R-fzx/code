#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

#define int long long
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;

int read() {
  int x = 0, f = 0; char ch = getchar();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x * 10) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}

typedef __int128 i128;

int T, a, b, k;
vector<int> p;
map<int, int> mp;

int qpow(int bs, int idx, int mod) {
  int ret = 1;
  for (; idx; idx >>= 1, bs = (i128)bs * bs % mod) {
    if (idx & 1) ret = (i128)ret * bs % mod;
  }
  return ret % mod;
}

int getm(int &b) {
  int nw = 1;
  if (__gcd(b, k) == 1) return 0;
  for (int i = 1; ; ++i) {
    nw = (i128)nw * k % cb;
    int d = __gcd(b, nw);
    debug(nw, b);
    if (nw) b /= __gcd(b, nw), nw /= d;
    else return i;
    if (__gcd(b, k) == 1) return i;
  }
}

void getm(int a, int &b) {
  int ck = k; p.clear();
  for (int i = 2; i * i <= ck; ++i) {
    if (ck % i) continue ;
    p.emplace_back(i);
    while (ck % i == 0) ck /= i;
  }
  if (ck != 1) p.emplace_back(ck);
  // debug(p.size());
  int cnt = 0;
  for (auto x : p) {
    int tmp = 0;
    while (b % x == 0) {
      ++tmp, b /= x;
    }
    // debug(x, tmp, b);
  }
}

int getr(int a, int b) {
  // debug(b, k);
  if (b == 1) return 0;
  mp.clear();
  int t = sqrt(b) + 1, nw = 1;
  // debug(t);
  for (int i = 0; i < t; ++i, nw = ((i128)nw * k) % b) {
    mp[nw] = i;
    // debug(nw, i);
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
    int d = __gcd(a, b);
    a /= d, b /= d;
    // debug(a, b, k);
    // debug("!!!");
    cout << getm(b) << ' ' << getr(a, b) << endl;
  }
  return 0;
}