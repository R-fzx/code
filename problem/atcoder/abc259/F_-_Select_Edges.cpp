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

const int kN = 3e5 + 1;

int n, d[kN];
LL f[kN][2], a[kN];
vector<Pii> e[kN];

LL D(int x, int p, int l) {
  if (~f[x][l]) {
    return f[x][l];
  }
  d[x] -= l, f[x][l] = 0;
  int c = 0;
  for (Pii i : e[x]) {
    if (i.first != p) {
      D(i.first, x, 0);
      if (d[i.first]) {
        D(i.first, x, 1), i.second > 0 && (f[i.first][1] += i.second);
        if (f[i.first][0] >= f[i.first][1] && f[i.first][0] > 0) {
          f[x][l] += f[i.first][0], a[++c] = f[i.first][1] - f[i.first][0];
        } else if (f[i.first][1] > f[i.first][0] && f[i.first][1] > 0) {
          a[++c] = f[i.first][1];
        }
        i.second > 0 && (f[i.first][1] -= i.second);
      } else {
        if (f[i.first][0] >= 0) {
          f[x][l] += f[i.first][0];
        }
      }
    }
  }
  sort(a + 1, a + c + 1, greater<LL>());
  for (int i = 1; i <= c && i <= d[x]; ++i) {
    f[x][l] += max(0LL, a[i]);
  }
  d[x] += l;
  return f[x][l];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  fill(&f[0][0], &f[n][1] + 1, -1);
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
  }
  for (int i = 1, x, y, w; i < n; ++i) {
    cin >> x >> y >> w;
    e[x].push_back({y, w}), e[y].push_back({x, w});
  }
  cout << D(1, 0, 0);
  return 0;
}