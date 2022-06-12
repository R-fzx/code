#include <atcoder/all>

using namespace std;
using namespace atcoder;

const int kN = 2e5 + 1;

int n, m, q[kN], h = 1, t, c;
bool v[kN];
vector<int> e[kN];

void R(int x) {
  if (!v[x]) {
    v[x] = 1, ++c, q[++t] = x;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  scc_graph g(n + 1);
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    g.add_edge(x, y), e[y].push_back(x);
  }
  auto l = g.scc();
  for (auto &x : l) {
    if (x.size() > 1) {
      R(x[0]);
    }
  }
  for (; h <= t; ++h) {
    for (int i : e[q[h]]) {
      R(i);
    }
  }
  cout << c;
  return 0;
}