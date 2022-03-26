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
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 5e5 + 1;

int n, q, a[kN], b[kN];

namespace T1 {
int l, r, qu[kN], t;
void S() {
  while (q--) {
    cin >> l >> r;
    int c = t = 0;
    for (int i = l; i <= r; ++i) {
      for (; t && (a[i] == a[qu[t]] || b[i] >= b[qu[t]]); --t) {
      }
      c += !t, qu[++t] = i;
    }
    cout << c << endl;
  }
}
}  // namespace T1
namespace T2 {
const int kN = 1e4 + 1;
int l, r, f[kN][kN], qu[kN], t;
void S() {
  for (int i = 1; i <= n; ++i) {
    f[i][i] = 1, qu[t = 1] = i;
    for (int j = i + 1; j <= n; ++j) {
      for (; t && (a[qu[t]] == a[j] || b[j] >= b[qu[t]]); --t) {
      }
      f[i][j] = f[i][j - 1] + !t, qu[++t] = j;
    }
  }
  while (q--) {
    cin >> l >> r;
    cout << f[l][r] << endl;
  }
}
}  // namespace T2
namespace T3 {
int l, r, f[kN];
bool C() {
  bool f = 1;
  for (int i = 1; i <= n; ++i) {
    f &= b[i] == n - i + 1;
  }
  return f;
}
void S() {
  f[n] = 1;
  for (int i = n - 1; i >= 1; --i) {
    f[i] = f[i + 1] * (a[i] == a[i + 1]) + 1;
  }
  while (q--) {
    cin >> l >> r;
    cout << min(r - l + 1, f[l]) << endl;
  }
}
}  // namespace T3

int main() {
#define FILEIO(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout);
  FILEIO("stack");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  if (n <= 10000) {
    T2::S();
  } else if (T3::C()) {
    T3::S();
  } else {
    T1::S();
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
a b

ta tb
a == ta || b >= tb

10 4
3 1 3 1 2 3 3 2 1 1
10 10 2 9 7 5 4 7 6 1
1 4
7 8
7 10
1 8

3 10
1 10
3 2
1 9
*/