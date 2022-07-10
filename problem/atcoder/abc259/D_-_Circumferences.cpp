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

const int kN = 3002;

int n, f[kN];
LL x[kN], y[kN], r[kN];

int F(int i) { return f[i] == i ? i : (f[i] = F(f[i])); }
bool C1(int i, int j) {
  if ((r[i] - r[j]) * (r[i] - r[j]) <= (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) && (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= (r[i] + r[j]) * (r[i] + r[j])) {
    f[F(i)] = F(j);
    return 1;
  }
  return 0;
}
bool C2(int i, int j) {
  if (r[i] * r[i] == (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) {
    f[F(i)] = F(j);
    return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x[0] >> y[0] >> x[n + 1] >> y[n + 1];
  iota(f, f + n + 2, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i] >> r[i];
    for (int j = 1; j < i; ++j) {
      C1(i, j);
    }
    C2(i, 0), C2(i, n + 1);
  }
  cout << (F(0) == F(n + 1) ? "Yes" : "No");
  return 0;
}