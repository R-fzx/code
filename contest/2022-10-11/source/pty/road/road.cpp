#include <algorithm>
#include <fstream>

using namespace std;
using LL = long long;

ifstream fin("road.in");
ofstream fout("road.out");

const int kMaxN = 201, kMaxM = 50001;

struct E {
  int x, y, a, b;
  bool operator<(const E &_e) { return a < _e.a; }
} e[kMaxM];

int l[kMaxN], r[kMaxN], n, m, t;
LL ans = 1e18, p, q;

int R(int x) { return r[x] == x ? x : r[x] = R(r[x]); }

int main() {
  fin >> n >> m >> p >> q;
  for (int i = 1; i <= m; i++) {
    fin >> e[i].x >> e[i].y >> e[i].a >> e[i].b;
  }
  sort(e + 1, e + 1 + m);
  for (int i = 1; i <= m; i++) {
    l[++t] = i;
    for (int j = t; j > 1 && e[l[j]].b < e[l[j - 1]].b; j--) {
      swap(l[j], l[j - 1]);
    }
    for (int j = 1; j <= n; j++) {
      r[j] = j;
    }
    int _t = 0;
    for (int j = 1; j <= t; j++) {
      int x = R(e[l[j]].x), y = R(e[l[j]].y);
      if (x != y) {
        l[++_t] = l[j];
        r[x] = y;
      }
    }
    t = _t;
    if (t == n - 1) {
      ans = min(ans, p * e[i].a + q * e[l[t]].b);
    }
  }
  fout << (ans == 1e18 ? -1 : ans);
  return 0;
}
