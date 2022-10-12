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
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 5e5 + 1;

struct E {
  LL a, b, c;
} e[kN];
int n, a, b, c, _a, _b, _c;
LL ans[2];

int main() {
  RF("¤æ¤ê¤Ã¤Ú");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  // cout << "wssb\n";
  cin >> n >> a >> b >> c;
  for (int i = 1; i <= n; ++i) {
    cin >> e[i].a >> e[i].b >> e[i].c;
    LL m = max({e[i].a, e[i].b, e[i].c});
    if (e[i].a == m && _a < a) {
      ans[0] += m, ans[1] += e[i].a + e[i].b + e[i].c, ++_a;
    } else if (e[i].b == m && _b < b) {
      ans[0] += m, ans[1] += e[i].a + e[i].b + e[i].c, ++_b;
    } else if (e[i].c == m && _c < c) {
      ans[0] += m, ans[1] += e[i].a + e[i].b + e[i].c, ++_c;
    } else if (e[i].a == m) {
      
    }
  }
  return 0;
}