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

const int kV = 5e5 + 1;

int n, m, x, y;
bitset<kV> f;

int main() {
  freopen("watch.in", "r", stdin);
  freopen("watch.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  f[0] = 1;
  cin >> n >> m;
  while (n--) {
    cin >> x >> y;
    for (int i = 1; i <= y; i <<= 1) {
      f |= f << x * i, y -= i;
    }
    if (y) {
      f |= f << x * y;
    }
  }
  while (m--) {
    cin >> x;
    cout << (f[x] ? "Yes" : "No") << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}