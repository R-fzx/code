#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

LL a, b, ans;
int c[10], _c[10], p[20], pc[20], d[20];

int S(LL n) {
  int c = 0;
  for (; n; ++c, n /= 10) {
  }
  return c;
}
void A(int x, int v) {
  for (; x != 1; pc[p[x]] += v, x /= p[x]) {
  }
}
LL P(LL b, LL e) {
  LL s = 1;
  for (; e; e >>= 1, b *= b) {
    (e & 1) && (s *= b);
  }
  return s;
}
void C() {
  int l = accumulate(_c + 1, _c + 10, 0);
  for (int i = 1; i <= l; A(i++, 1)) {
  }
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j <= _c[i]; A(j++, -1)) {
    }
  }
  LL s = 1;
  for (int i = 1; i < 20; ++i) {
    s *= P(i, pc[i]), pc[i] = 0;
  }
  ans += s;
}
void S(int l, LL n) {
  if (l < S(n)) {
    C();
    return;
  }
  for (int i = 1; n; d[i] = n % 10, ++i, n /= 10) {
  }
  for (int i = l; i; --i) {
    for (int j = 1; j < d[i]; ++j) {
      if (_c[j]) {
        --_c[j], C(), ++_c[j];
      }
    }
    if (!_c[d[i]]) {
      return;
    }
    --_c[d[i]];
  }
  C();
}
void D(int x, int l, LL n) {
  if (l > S(n)) {
    return;
  }
  if (x > 9) {
    copy_n(c + 1, 9, _c + 1), S(l, n);
    return;
  }
  D(x + 1, l, n), ++c[x], D(x, l + 1, n / x), --c[x];
}
LL C(LL n) {
  ans = 0, D(1, 0, n);
  return ans;
}

int main() {
  // RF("sillyz");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 2; i < 20; ++i) {  
    if (!p[i]) {
      for (int j = i; j < 20; p[j] = i, j += i) {
      }
    }
  }
  cin >> a >> b;
  cout << C(b) - C(a - 1);
  return 0;
}