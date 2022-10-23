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

const int kN = 1e7 + 1, kV = 1e5 + 1;

int n, b[kV], h = 1, t;
LL q[kN], ans;

int N(int x) {
  if (!x) {
    return 0;
  }
  if (b[x]) {
    return x;
  }
  for (++x; x < kV && !b[x]; ++x) {
  }
  return x == kV ? 0 : x;
}
int R() {
  int x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) {
  }
  for (; isdigit(c); x = x * 10 + c - '0', c = getchar()) {
  }
  return x;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  n = R();
  for (int i = 1, x; i <= n; ++i) {
    ++b[R()];
  }
  for (int i = 1; --n; ) {
    i = N(i);
    LL v;
    if (h < t && (!i || i > q[h + 1])) {
      v = q[h] + q[h + 1], h += 2;
    } else {
      --b[i];
      int j = N(i);
      if (j && (h > t || q[h] > j)) {
        v = i + j, --b[j];
      } else {
        v = q[h] + i, ++h;
      }
    }
    ans += v, q[++t] = v;
  }
  cout << ans;
  return 0;
}
/*
i
1 1 0 0 0 0 0 0 1
q
0 0 0 0
h=1 t=0
*/