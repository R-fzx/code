#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
using Pdd = pair<double, double>;

const int kN = 1e5 + 1;

int n, st[2][kN], t[2];
Pdd a[kN];
double s;

Pdd operator-(Pdd x, Pdd y) { return {x.first - y.first, x.second - y.second}; }
double Cross(Pdd x, Pdd y, Pdd o) { return x = x - o, y = y - o, x.first * y.second - x.second * y.first; }
double Distance(Pdd x, Pdd y) {
  Pdd o = x - y;
  return hypot(o.first, o.second);
}

void S(int o) {
  st[o][++t[o]] = 1;
  for (int i = 2; i <= n; ++i) {
    while (t[o] > 1 && Cross(a[st[o][t[o]]], a[i], a[st[o][t[o] - 1]]) >= 0) --t[o];
    st[o][++t[o]] = i;
  }
  for (int i = 1; i < t[o]; ++i) s += Distance(a[st[o][i]], a[st[o][i + 1]]);
}

int main() {
  // freopen("P2742_8.in", "r", stdin);
  // freopen("P2742.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1), S(0), reverse(a + 1, a + n + 1), S(1);
  printf("%.2lf", s);
  return 0;
}