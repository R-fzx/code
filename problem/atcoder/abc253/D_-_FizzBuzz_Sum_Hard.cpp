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

LL n, a, b;

LL G(LL x, LL y) { return y ? G(y, x % y) : x; }
LL C(LL x) { return (n / x + 1) * (n / x) / 2 * x; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> a >> b;
  cout << (n + 1) * n / 2 - C(a) - C(b) + C(a * b / G(a, b));
  return 0;
}
/*
x * (n / x + 1) * (n / x) / 2
*/