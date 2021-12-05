#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int kN = 1e5 + 1;

struct V {
  double x, y;
} a[kN];
const V operator+(const V& a, const V& b) { return {a.x + b.x, a.y + b.y}; }
const V operator-(const V& a, const V& b) { return {a.x - b.x, a.y - b.y}; }
const V operator-(const V& a) { return {-a.x, -a.y}; }
const int Dot(const V& a, const V& b) { return a.x * b.x + a.y * b.y; }
const int Cross(const V& a, const V& b) { return a.x * b.y - a.y * b.x; }
const double Distance(const V& a, const V& b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }

int n, ms = 1, t, st[kN];
double s;

int main() {
  // freopen("P2742.in", "r", stdin);
  // freopen("P2742.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y, (a[i].x < a[ms].x || a[i].x == a[ms].x && a[i].y < a[ms].y) && (ms = i);
  V _x = a[ms];
  sort(a + 1, a + n + 1, [_x](const V& x, const V& y) { return Cross(x - _x, y - _x) > 0 || Cross(x - _x, y - _x) == 0 && Distance(_x, x) < Distance(_x, y); });
  st[++t] = 1;
  for (int i = 2; i <= n; ++i) {
    while (t > 1 && Cross(a[st[t]] - a[st[t - 1]], a[i] - a[st[t - 1]]) <= 0) --t;
    st[++t] = i;
  }
  s = Distance(a[st[1]], a[st[t]]);
  for (int i = 1; i < t; ++i) s += Distance(a[st[i]], a[st[i + 1]]);
  printf("%.2lf", s);
  return 0;
}
/*
Cross(a[st[t]]-a[st[t - 1]],a[i]-a[st[t-1]])<0
*/