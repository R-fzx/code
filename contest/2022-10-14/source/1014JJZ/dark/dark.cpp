/**
 * @file dark.cpp
 * @author Lightwhite (Lwchicky@qq.com)
 * @brief Dark(problem in 0class contest)
 * @version 0.1
 * @date 2022-10-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
using Pdd = pair<double, double>;
#define x first
#define y second
const int kN = 2e5 + 5;
const double kI = 1e20;

Pdd p[kN];
int n, t[kN];
double D(int l, int r) {
  if (l == r) {
    return kI;
  }
  if (l + 1 == r) {
    return hypot(p[l].x - p[r].x, p[l].y - p[r].y);
  }
  int mid = l + r >> 1, k = 0;
  double d = min(D(l, mid), D(mid + 1, r));
  for (int i = l; i <= r; i++) {
    if (fabs(p[mid].x - p[i].x) <= d) {
      t[k++] = i;
    }
  }
  sort(t, t + k, [&](int& x, int& y) { return p[x].y < p[y].y; });
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k && p[t[j]].y - p[t[i]].y < d; j++) {
      d = min(d, hypot(p[t[i]].x - p[t[j]].x, p[t[i]].y - p[t[j]].y));
    }
  }
  return d;
}
int main() {
  freopen("dark.in", "r", stdin);
  freopen("dark.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for_each(p, p + n, [&](Pdd& d) { cin >> d.x >> d.y; });
  sort(p, p + n, [&](Pdd& p1, Pdd& p2) { return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x; });
  cout << fixed << setprecision(3) << D(0, n - 1) * 0.5 << '\n';
  return 0;
}