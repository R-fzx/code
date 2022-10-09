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
int c[10], _c[10], p[18], pc[18];

int S(LL n) { return log10(n) + 1; }
void A(int x, int v) {
  for (; x != 1; pc[p[x]] += v, x /= p[x]) {
  }
}
LL C() {
  int s = accumulate(_c + 1, _c + 10, 0);
  for (int i = 1; i <= s; A(i++, 1)) {
  }
  for (int i = 1; i < 10; ++i) {
    
  }
}
void S(int l, LL n) {
  
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
  RF("sillyz");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  cout << C(b) - C(a - 1);
  return 0;
}