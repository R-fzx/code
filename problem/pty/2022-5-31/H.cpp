#include <atcoder/all>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kN = 1e5 + 1;

struct Q {
  int x, f;
  LL d;
  bool operator<(const Q& o) const { return d > o.d; }
};
int n, m, k, l, a[kN], p[kN], c[kN];
LL d[kN][2];
vector<Pii> e[kN];
priority_queue<Q> q;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> l;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], d[i][0] = d[i][1] = 1e18;
  }
  for (int i = 1, x; i <= l; ++i) {
    cin >> x;
    q.push({x, a[x], 0});
  }
  for (int i = 1, x, y, w; i <= m; ++i) {
    cin >> x >> y >> w;
    e[x].push_back({y, w}), e[y].push_back({x, w});
  }
  while (!q.empty()) {
    auto [x, f, _d] = q.top();
    q.pop();
    if (c[x] == 2 || p[x] == f) {
      continue;
    }
    c[x] || (p[x] = f), d[x][c[x]++] = _d;
    for (auto [i, w] : e[x]) {
      q.push({i, f, _d + w});
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << (d[i][a[i] == p[i]] == 1e18 ? -1 : d[i][a[i] == p[i]]) << " ";
  }
  return 0;
}