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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 1e5 + 2;

int n, a[kN], e[kN];
LL ans;

void Add(int x) {
  for (; x <= n; ++e[x], x += x & -x) {
  }
}
int Sum(int x) {
  int s = 0;
  for (; x; s += e[x], x -= x & -x) {
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  a[n + 1] = n + 1;
  for (int i = 2, j = 1; i <= n + 1; ++i) {
    if (a[i] > a[i - 1]) {
      reverse(a + j, a + i), ans += i - j > 1, j = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans += i - Sum(a[i]) - 1, Add(a[i]);
  }
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}