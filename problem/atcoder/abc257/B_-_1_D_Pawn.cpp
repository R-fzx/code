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

const int kN = 202;

int n, k, q, a[kN];
bool v[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> q;
  for (int i = 1; i <= k; ++i) {
    cin >> a[i];
    v[a[i]] = 1;
  }
  v[n + 1] = 1;
  for (int x; q--; ) {
    cin >> x;
    if (!v[a[x] + 1]) {
      v[a[x]] = 0, v[++a[x]] = 1;
    }
  }
  for (int i = 1; i <= k; ++i) {
    cout << a[i] << " ";
  }
  return 0;
}