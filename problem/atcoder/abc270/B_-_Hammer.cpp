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

int x, y, z;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> x >> y >> z;
  if (y > 0 && x > y && z > y || y < 0 && x < y && z < y) {
    cout << -1;
  } else {
    if (y > 0 && x > y || y < 0 && x < y) {
      cout << abs(z) + abs(x - z);
    } else {
      cout << abs(x);
    }
  }
  return 0;
}