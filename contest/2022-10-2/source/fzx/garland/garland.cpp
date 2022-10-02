#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 501;

int n;
LL s, c[kN][kN], l[kN][kN], r[kN][kN], a[kN][kN];
vector<pair<LL, Pii>> p;

int main() {
  RF("garland");
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> c[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> l[i][j];
      if (!c[i][j]) {
        a[i][j] = l[i][j], s += a[i][j];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> r[i][j];
      if (c[i][j]) {
        a[i][j] = r[i][j], s += a[i][j];
      }
    }
  }
  if (s > 0) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (c[i][j]) {
          p.push_back({c[i][j], {i, j}});
        }
      }
    }
    sort(p.begin(), p.end());
    for (auto i : p) {
      int x = i.second.first, y = i.second.second;
      LL v = min(s, r[x][y] - l[x][y]);
      s -= v, a[x][y] -= v;
      if (!s) {
        break;
      }
    }
  }
  s = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      s += a[i][j] * c[i][j];
    }
  }
  cout << s;
  return 0;
}