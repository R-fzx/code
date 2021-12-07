#include <atcoder/dsu>
#include <iostream>
#include <vector>

using namespace std;
using namespace atcoder;

const int kN = 2e5 + 1;

int n, m, ans[kN], c;
vector<int> e[kN];

int main() {
  cin >> n >> m;
  dsu f(n + 1);
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y);
  }
  for (int i = n; i >= 1; --i) {
    for (int j : e[i]) {
      c -= !f.same(i, j), f.merge(i, j);
    }
    ans[i - 1] = ++c;
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}