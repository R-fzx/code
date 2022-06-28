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

int n, a[10], p, c[10];
vector<int> l;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i < 10; ++i) {
    cin >> a[i];
  }
  l.push_back(9);
  for (int i = 8; i >= 1; --i) {
    if (a[i] < a[l.back()]) {
      l.push_back(i);
    }
  }
  for (int i : l) {
    debug("%d ", i);
  }
  debug("\n");
  p = n / a[l.back()], n -= p * a[l.back()], c[l.back()] = p;
  for (int i = 0; i < l.size() - 1; ++i) {
    a[l[i]] -= a[l.back()];
    c[l.back()] -= n / a[l[i]], c[l[i]] += n / a[l[i]], n -= n / a[l[i]] * a[l[i]];
  }
  for (int i = 9; i >= 1; --i) {
    cout << string(c[i], '0' + i);
  }
  return 0;
}