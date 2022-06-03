#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using mL = modint998244353;

const int kN = 2e5 + 1;

int n, a[kN];
LL l, r;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> l >> r;
  iota(a + 1, a + n + 1, 1);
  
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  return 0;
}
/*
1 n-1
2 n-2
3 n-3
4 n-4
...
i n-i
[1,4]
[1,5]
[2,3]
[2,4]
lx + 1, rx - 1
3,4,5
1,2,3,4,5,6,7,8
1,2,8,3,4,5,6,7
1,2,8,7,3,4,5,6
1,2,8,7,6,3,4,5
*/