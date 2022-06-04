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
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int t;
LL a, b, c;

void EG(LL a, LL &x, LL b, LL &y) { !b ? (x = 1, y = 0) : (EG(b, y, a % b, x), y -= a / b * x); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    LL g = gcd(a, b);
    if (c % g) {
      cout << "-1\n";
    } else {
      a /= g, b /= g, c /= g;
    }
  }
  return 0;
}