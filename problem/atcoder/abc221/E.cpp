#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 3e5 + 1;
const LL kM = 998244353;

int n, a[kN], b[kN];
LL p2[kN], e[kN << 2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
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
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
3
1 2 1
1 1 0
1 0 1
1 1 1

3
1 2 2


10
2 1 9 3 10 8 7 6 5 4
*/