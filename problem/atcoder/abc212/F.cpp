#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using Pii = pair<int, int>;

const int kN = 1e5 + 1, kL = 17;

struct B {
  int x, y, s, t;
} a[kN];
int n, m, q, f[kL][kN];
vector<Pii> e[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i].x >> a[i].y >> a[i].s >> a[i].t;
    a[i].s = a[i].s * 2 + 1, a[i].t = a[i].t * 2 + 1, e[a[i].x].emplace_back(a[i].s, i);
  }
  for (int i = 1; i <= n; ++i) {
    sort(e[i].begin(), e[i].end());
  }
  for (int i = 1; i <= m; ++i) {
    auto p = lower_bound(e[a[i].y].begin(), e[a[i].y].end(), Pii(a[i].t, 0));
    f[0][i] = (p == e[a[i].y].end() ? i : p->second);
  }
  for (int i = 1; i < kL; ++i) {
    for (int j = 1; j <= m; ++j) {
      f[i][j] = f[i - 1][f[i - 1][j]];
    }
  }
  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;
    x *= 2, z *= 2;
    auto p = lower_bound(e[y].begin(), e[y].end(), Pii(x, 0));
    if (p == e[y].end() || a[p->second].s > z) {
      cout << y << endl;
    } else if (a[p->second].t > z) {
      cout << a[p->second].x << " " << a[p->second].y << endl;
    } else {
      int d = p->second;
      for (int i = kL - 1; i >= 0; --i) {
        if (a[f[i][d]].t < z) {
          d = f[i][d];
        }
      }
      x = a[d].t, y = a[d].y, p = lower_bound(e[y].begin(), e[y].end(), Pii(x, 0));
      if (p == e[y].end() || a[p->second].s > z) {
        cout << y << endl;
      } else {
        cout << a[p->second].x << " " << a[p->second].y << endl;
      }
    }
  }
  return 0;
}