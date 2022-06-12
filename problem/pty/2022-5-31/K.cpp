#include <atcoder/all>

using namespace std;
using namespace atcoder;

const int kN = 2e5 + 1;

int n, a[kN], f[kN];
vector<int> e[kN];

void D(int x, int _f, int v) {
  for (int i : e[x]) {
    if (i ^ _f) {
      D(i, x, v), f[x] += f[i];
    }
  }
  f[x] = max(f[x] - 1, 0) + (a[x] >= v);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for_each_n(a + 2, n - 1, [](int &x) { cin >> x; });
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  int l = 0, r = 1e9;
  for (int m; l != r;) {
    m = l + r + 1 >> 1, fill_n(f + 1, n, 0), D(1, 0, m);
    if (f[1]) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l;
  return 0;
}