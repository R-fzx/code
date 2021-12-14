#include <algorithm>
#include <iostream>

using namespace std;
using LL = long long;

const int kN = 1e5 + 1;

struct V {
  LL x, y;
} a[kN], e[2][kN];
LL Cross(V x, V y, V o = {0, 0}) { return (x.x - o.x) * (y.y - o.y) - (x.y - o.y) * (y.x - o.x); }
bool operator<(const V &x, const V &y) { return Cross(x, y) > 0; }
LL C(LL x) { return x * (x - 1) / 2; }
int n, _c[2];
LL c;

int main() {
  freopen("tricount.in", "r", stdin);
  freopen("tricount.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
    e[a[i].y < 0][++_c[a[i].y < 0]] = a[i];
  }
  sort(&e[0][1], &e[0][_c[0]] + 1), sort(&e[1][1], &e[1][_c[1]] + 1);
  copy_n(e[0] + 1, _c[0], a + 1), copy_n(e[1] + 1, _c[1], a + _c[0] + 1);
  int p;
  for (p = 2; p <= n && Cross(a[p], a[1]) < 0; ++p) {
  }
  for (int i = 1; i <= n; ++i) {
    c += C((p - i + n) % n) + C()
  }
  cout << c / 2;
  return 0;
}