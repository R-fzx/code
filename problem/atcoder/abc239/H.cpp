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
using mL = modint1000000007;

const LL kM = 1e9 + 7;

int n, m;
unordered_map<int, LL> f;
LL in, _in;

LL C(int x) {
  auto p = f.find(x);
  if (p != f.end()) {
    return p->second;
  }
  LL s = 0;
  for (int l = 2, r; l <= n && l <= x; l = r + 1) {
    r = min(n, x / (x / l)), s = (s + C(x / l) * (r - l + 1) % kM) % kM;
  }
  return f[x] = (s * in % kM + 1) * _in % kM;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  in = ((mL)1 / n).val(), _in = ((mL)n / (n - 1)).val();
  cout << C(m);
  return 0;
}