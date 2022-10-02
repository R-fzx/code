#include <algorithm>
#include <iostream>
#define LL long long

using namespace std;

struct V {
  LL v, l, r;
} v[250001];
LL n, m, l, r, ans;

int main() {
  freopen("garland.in", "r", stdin);
  freopen("garland.out", "w", stdout);
  cin >> n;
  for (LL i = 1; i <= n * n; i++) {
    cin >> v[i].v;
  }
  for (LL i = 1; i <= n * n; i++) {
    cin >> v[i].l;
  }
  for (LL i = 1; i <= n * n; i++) {
    cin >> v[i].r;
  }
  for (LL i = 1; i <= n; i++) {
    for (LL j = 1; j <= i; j++) {
      v[(i - 1) * n + j].l = v[(j - 1) * n + i].l = max(v[(i - 1) * n + j].l, v[(j - 1) * n + i].l);
      v[(i - 1) * n + j].r = v[(j - 1) * n + i].r = min(v[(i - 1) * n + j].r, v[(j - 1) * n + i].r);
    }
  }
  for (LL i = 1; i <= n * n; i++) {
    if (v[i].l > 0) {
      m += v[i].l, ans += v[i].l * v[i].v;
      v[i].r -= v[i].l, v[i].l = 0;
    }
  }
  sort(v + 1, v + n * n + 1, [](V i, V j) { return i.v < j.v; });
  for (l = 1; m > 0; l += !v[l].l) {
    LL _m = m;
    m -= min(-v[l].l, _m);
    ans += (-v[l].l <= _m) * (v[l].l * v[l].v);
    v[l].l += min(-v[l].l, _m);
  }
  for (r = n * n; l < r;) {
    if (-v[l].l <= v[r].r) {
      ans += -v[l].l * (v[r].v - v[l].v);
      v[r].r += v[l++].l;
    } else {
      ans += v[r].r * (v[r].v - v[l].v);
      v[l].l += v[r--].r;
    }
  }
  cout << ans;
  return 0;
}
