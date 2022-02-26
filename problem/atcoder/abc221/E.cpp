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

const int kN = 3e5 + 1;
const LL kM = 998244353;

int n, a[kN], b[kN];
LL p2[kN], ans;
Pll e[kN << 2];

void Mul(int x, LL v) { e[x] = {e[x].first * v % kM, e[x].second * v % kM}; }
LL Do(int ty, int x, int l, int r, int tl, int tr) {
  if (l == tl && r == tr) {
    if (ty == 1) {
      Mul(x, 2);
    } else if (ty == 2) {
      e[x].first = (e[x].first + 1) % kM;
    } else {
      return e[x].first;
    }
    return 0;
  }
  Mul(x * 2, e[x].second), Mul(x * 2 + 1, e[x].second), e[x].second = 1;
  int m = l + r >> 1;
  LL s = 0;
  if (tl <= m) {
    s = (s + Do(ty, x * 2, l, m, tl, min(tr, m))) % kM;
  }
  if (m < tr) {
    s = (s + Do(ty, x * 2 + 1, m + 1, r, max(tl, m + 1), tr)) % kM;
  }
  e[x].first = (e[x * 2].first + e[x * 2 + 1].first) % kM;
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  fill_n(e + 1, n << 2, Pll{0, 1});
  p2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    p2[i] = p2[i - 1] * 2 % kM;
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  int m = unique(b + 1, b + n + 1) - b;
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(b + 1, b + m, a[i]) - b;
    ans = (ans + Do(3, 1, 1, m, 1, a[i])) % kM;
    Do(1, 1, 1, m, 1, m), Do(2, 1, 1, m, a[i], a[i]);
  }
  cout << ans;
  // for (int i = 1; i <= n; ++i) {
  //   cerr << a[i] << " ";
  // }
  // cerr << "\n";
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
3
1 2 1

0 0 0 +0
1 0 0 +0
2 1 0 +1
5 2 0 +2

3
1 2 2


10
2 1 9 3 10 8 7 6 5 4
*/