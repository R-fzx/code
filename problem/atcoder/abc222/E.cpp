#include <iostream>
#include <vector>

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;

const LL kN = 1001, kM = 998244353, kK = 1e5 + 1;

int n, m, k, a[kN];
vector<Pll> e[kN];
LL f[2][kK << 1], c[kN << 1];
bool v[kN];

bool D(int x, int y) {
  if (x == y) {
    return 1;
  }
  for (Pll i : e[x]) {
    if (!v[i.first]) {
      if (++c[i.second], v[i.first] = 1, D(i.first, y)) {
        return 1;
      }
      --c[i.second];
    }
  }
  return 0;
}

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i];
  }
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back({y, i}), e[y].push_back({x, i + n});
  }
  for (int i = 2; i <= m; ++i) {
    fill(v + 1, v + n + 1, 0), v[a[i - 1]] = 1, D(a[i - 1], a[i]);
  }
  for (int i = 1; i < n; ++i) {
    c[i] += c[i + n];
  }
  f[0][kK] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < (kK << 1); ++j) {
      f[1][j] = ((j + c[i] < (kK << 1) ? f[0][j + c[i]] : 0) + (j - c[i] >= 0 ? f[0][j - c[i]] : 0)) % kM;
    }
    copy(&f[1][0], &f[1][kK << 1], &f[0][0]);
  }
  cout << f[0][k + kK];
  return 0;
}