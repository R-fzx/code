#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int kN = 1001;

struct E {
  LL x, y, v;
  const E operator-(const E &o) const { return {x - o.x, y - o.y, v}; }
} a[kN];
LL Cross(E x, E y) { return x.x * y.y - x.y * y.x; }
LL Dot(E x, E y) { return x.x * y.x + x.y * y.y; }
struct S {
  E l, r, x, h;
  LL v;
  bool C(const S &o) const { return Cross(x, o.x) < 0 || !Cross(x, o.x) && Dot(r - h, o.h - h) > 0; }
  bool P(const S &o) const { return !Cross(x, o.x) && !Dot(r - h, o.h - h); }
  bool operator<(const S &o) const { return C(o) || P(o) && v > o.v; }
};
int n;
LL ans = -1;
vector<S> b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y >> a[i].v;
    a[i].x <<= 1, a[i].y <<= 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      E x = a[i], y = a[j];
      if (x.y > y.y || x.y == y.y && x.x > y.x) {
        swap(x, y);
      }
      b.push_back({x, y, y - x, {(x.x + y.x) / 2, (x.y + y.y) / 2, 0}, x.v + y.v});
    }
  }
  sort(b.begin(), b.end());
  for (int i = 1; i < b.size(); ++i) {
    if (b[i - 1].P(b[i]) && Cross(b[i].r - b[i].l, b[i - 1].r - b[i].l)) {
      ans = max(ans, b[i - 1].v + b[i].v);
    }
  }
  cout << ans;
  return 0;
}