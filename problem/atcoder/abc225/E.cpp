#include <iostream>
#include <algorithm>

using namespace std;

const int kN = 2e5 + 1;

struct E {
  struct F {
    int a, b;
    bool operator<(const F &o) const { return 1LL * a * o.b < 1LL * o.a * b; }
    bool operator==(const F &o) const { return 1LL * a * o.b == 1LL * o.a * b; }
  } l, r;
} e[kN];

int n, ans = 1;

int main() {
  // freopen("E.in", "r", stdin);
  // freopen("E.out", "w", stdout);
  cin >> n;
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    e[i].l = {x - 1, y}, e[i].r = {x, y - 1};
  }
  sort(e + 1, e + n + 1, [](E i, E j) { return i.r < j.r || i.r == j.r && i.r.a * i.r.a + i.r.b * i.r.b < j.r.a * j.r.a + j.r.b * j.r.b; });
  for (int i = 2, p = 1; i <= n; ++i) {
    if (e[p].r < e[i].l || e[p].r == e[i].l) {
      p = i, ++ans;
    }
  }
  cout << ans;
  return 0;
}