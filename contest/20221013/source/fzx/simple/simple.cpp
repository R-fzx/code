#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e6 + 1;

int t, n, q, mx, my;
Pll a[kN];
LL bx[kN], by[kN], sx[kN], sy[kN], cx[kN], cy[kN];

int main() {
  RF("simple");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--; ) {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].first >> a[i].second;
      bx[i] = a[i].first += a[i].second, by[i] = a[i].second += a[i].second - a[i].first;
    }
    sort(bx + 1, bx + n + 1), mx = unique(bx + 1, bx + n + 1) - bx - 1;
    sort(by + 1, by + n + 1), my = unique(by + 1, by + n + 1) - by - 1;
    fill_n(cx + 1, mx, 0), fill_n(cy + 1, my, 0);
    for (int i = 1; i <= n; ++i) {
      a[i].first = lower_bound(bx + 1, bx + mx + 1, a[i].first) - bx, ++cx[a[i].first];
      a[i].second = lower_bound(by + 1, by + my + 1, a[i].second) - by, ++cy[a[i].second];
    }
    for (int i = 1; i <= mx; ++i) {
      sx[i] = cx[i] * bx[i] + sx[i - 1], cx[i] += cx[i - 1];
    }
    for (int i = 1; i <= my; ++i) {
      sy[i] = cy[i] * by[i] + sy[i - 1], cy[i] += cy[i - 1];
    }
    for (LL x, y; q--; ) {
      cin >> x >> y;
      x += y, y += y - x;
      int dx = upper_bound(bx + 1, bx + mx + 1, x) - bx - 1, dy = upper_bound(by + 1, by + my + 1, y) - by - 1;
      cout << (x * cx[dx] - sx[dx] + (sx[mx] - sx[dx]) - x * (cx[mx] - cx[dx]) + y * cy[dy] - sy[dy] + (sy[my] - sy[dy]) - y * (cy[my] - cy[dy])) / 2 << '\n';
    }
  }
  return 0;
}
/*
max(|sx-x|,|sy-y|)
*/