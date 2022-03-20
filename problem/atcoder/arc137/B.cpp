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

const int kN = 5;

int n, a[kN], s[kN], b[kN], c[kN << 1], sc[kN << 1];
LL ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  c[kN] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    c[b[i] = i - (s[i] = s[i - 1] + a[i]) * 2 + kN] = 1;
  }
  for (int i = 1; i <= n + kN; ++i) {
    cerr << c[i] << " ";
    if (c[i]) {
      ans += sc[i - 1];
    }
    sc[i] = sc[i - 1] + c[i];
  }
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
s[i]=s[i-1]+a[i]
l-r反转后的变化：(r-(l-1))-(s[r]-s[l-1])-(s[r]-s[l-1])
l=l-1
r-l-s[r]+s[l]-s[r]+s[l]
(r-s[r]*2)-(l-s[l]*2)
b[x]=x-s[x]*2
b[r]-b[l]

0 0 0 0 0
  1 1 1
l=1,r=4
0 0 0 0 0
    1 1 1
l=2,r=5

1 1 1 1 1
1
2
3
4
5
*/