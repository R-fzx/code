/**
 * @file trip.cpp
 * @author Lightwhite (Lwchicky@qq.com)
 * @brief Trip (problem of 1class contest)
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>

using namespace std;
const int kN = 1e5 + 5, kI = 1e9;

int n, m, a[kN], c[kN], f[kN], cnt, a1, a2 = kI, s, t, l = 1, r;
struct Node {
  int u, v;
  double w;
} p[kN];
int R(int x) {
  return f[x] == x ? x : f[x] = R(f[x]);
}
int main() {
  freopen("trip.in", "r", stdin);
  freopen("trip.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for_each(p + 1, p + m + 1, [&](Node& P) { cin >> P.u >> P.v >> P.w; });
  for (int i = 1, x; i <= n; i++) {
    cin >> x; 
    cnt += x;
    for (int j = 1, y; j <= x; j++) {
      cin >> y;
      c[y] = i;
    }
  }
  for_each(a + 1, a + n + 1, [&](int& x) { cin >> x; });
  cin >> s >> t;
  for (int i = 1; i <= m; i++) {
    p[i].w = p[i].w * 1.0 * (a[c[p[i].u]] * 1.0 + a[c[p[i].v]] * 1.0) / 200.0;
  }
  sort(p + 1, p + m + 1, [&](Node& p1, Node& p2) { return p1.w < p2.w; });
  for (r = m; l < r;) {
    int mid = l + r >> 1;
    iota(f + 1, f + cnt + 1, 1);
    int i = mid;
    for (int fu, fv; i <= m; i++) {
      fu = R(p[i].u), fv = R(p[i].v);
      if (fu != fv) {
        f[fu] = fv;
      }
      if (R(s) == R(t)) {
        break;
      } 
    }
    if (R(s) != R(t)) {
      r = mid;
    } else {
      l = mid + 1;
      int fu = floor(p[mid].w), fv = ceil(p[i].w);
      if (fu > a1) {
        a1 = fu, a2 = fv;
      } else if (fu == a1) {
        a2 = min (a2, fv);
      }
    }
  }
  cout << a1 << ' ' << a2 << '\n';
  return 0;
}