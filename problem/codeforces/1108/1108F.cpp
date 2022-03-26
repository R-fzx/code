#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;
using LL = long long;

const int kN = 2e5 + 1;

struct E {
  int x, y, v;
  bool operator<(const E &o) const { return v < o.v; }
} e[kN];
int n, m, f[2][kN];
LL ans;

int F(int o, int x) { return x == f[o][x] ? x : (f[o][x] = F(o, f[o][x])); }
bool U(int o, int x, int y) { return F(o, x) == F(o, y); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  iota(f[0] + 1, f[0] + n + 1, 1), iota(f[1] + 1, f[1] + n + 1, 1);
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].x >> e[i].y >> e[i].v;
  }
  sort(e + 1, e + m + 1);
  for (int i = 1, j = 1; i <= m; i = j) {
    for (; j <= m && e[j].v == e[i].v; ++j) {
      if (!U(0, e[j].x, e[j].y)) {
        f[0][F(0, e[j].x)] = F(0, e[j].y);
      } else if (!U(1, e[j].x, e[j].y)) {
        ++ans;
      }
    }
    for (j = i; j <= m && e[j].v == e[i].v; ++j) {
      if (!U(1, e[j].x, e[j].y)) {
        f[1][F(1, e[j].x)] = F(1, e[j].y);
      }
    }
  }
  cout << ans;
  return 0;
}