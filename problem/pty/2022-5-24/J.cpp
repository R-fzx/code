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

const int kN = 17;

int n, m, f[1 << kN][kN], s;
vector<int> e[kN];
queue<Pii> q;

void R(int i, int j, int d) {
  if (f[i][j] > d) {
    f[i][j] = d, q.emplace(i, j);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    --x, --y, e[x].push_back(y), e[y].push_back(x);
  }
  fill(f[0], f[1 << kN], 1e9);
  for (int i = 0; i < n; ++i) {
    R(0, i, 0);
  }
  for (; !q.empty(); ) {
    int i = q.front().first, j = q.front().second;
    q.pop();
    for (int k : e[j]) {
      R(i ^ (1 << k), k, f[i][j] + 1);
    }
  }
  for (int i = 0; i < 1 << n; ++i) {
    int x = 1e9;
    for (int j = 0; j < n; ++j) {
      x = min(x, f[i][j]);
    }
    s += x;
  }
  cout << s;
  return 0;
}