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

const int kN = 2e5 + 1;

int n, x, y, d[kN], f[kN], s[kN], t;
vector<int> e[kN];

void D(int x, int _f) {
  f[x] = _f, d[x] = d[_f] + 1;
  for (int i : e[x]) {
    if (i != _f) {
      D(i, x);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x >> y;
  for (int i = 1, a, b; i < n; ++i) {
    cin >> a >> b;
    e[a].push_back(b), e[b].push_back(a);
  }
  D(1, 0);
  if (d[x] > d[y]) {
    for (; d[x] > d[y]; cout << x << ' ', x = f[x]) {
    }
  } else {
    for (; d[x] < d[y]; s[++t] = y, y = f[y]) {
    }
  }
  for (; x != y; cout << x << ' ', s[++t] = y, x = f[x], y = f[y]) {
  }
  cout << x << ' ';
  for (; t; cout << s[t--] << ' ') {
  }
  return 0;
}