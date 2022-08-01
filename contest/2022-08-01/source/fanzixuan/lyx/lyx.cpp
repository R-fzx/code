#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1;

int n, m, f[kN], c[kN], ans;
vector<int> e[kN];

int D(int x) {
  if (f[x]) {
    return f[x];
  }
  if (e[x].empty()) {
    return f[x] = 1;
  }
  for (int i : e[x]) {
    f[x] += D(i);
  }
  return f[x];
}

int main() {
#define RF(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
  RF("lyx");
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y), ++c[y];
  }
  for (int i = 1; i <= n; ++i) {
    if (!c[i]) {
      ans += D(i);
    }
  }
  cout << ans;
  return 0;
}