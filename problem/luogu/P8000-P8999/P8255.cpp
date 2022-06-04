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

int t;
LL x, z;

LL G(LL a, LL b) { return b ? G(b, a % b) : a; }
LL C() {
  if (z % x) {
    return -1;
  }
  LL d, _ = G(x * x, z / x);
  d = sqrt(_);
  if (d * d != _ || z / x % d) {
    return -1;
  }
  return z / x / d;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> x >> z;
    cout << C() << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}