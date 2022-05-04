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

const int kN = 1e5 + 1, kK = 21;

int n, q, a[kN], b[kN][kK], p[kK << 1];
vector<int> e[kN];

void D(int x, int f) {
  b[x][1] = a[x];
  for (int i : e[x]) {
    if (i != f) {
      D(i, x);
      merge(&b[x][1], &b[x][kK - 1] + 1, &b[i][1], &b[i][kK - 1] + 1, p + 1, greater<int>());
      copy(p + 1, p + kK, &b[x][1]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  D(1, 0);
  while (q--) {
    int x, k;
    cin >> x >> k;
    cout << b[x][k] << endl;
  }
  return 0;
}