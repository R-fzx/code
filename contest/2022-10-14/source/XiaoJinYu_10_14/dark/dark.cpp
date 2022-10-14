#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

const int MAXN = 2e5 + 1;

struct Node {
  int x, y;
  bool operator<(const Node &xx) const {
    if (x == xx.x) return y < xx.y;
    return x < xx.x;
  }
} a[MAXN];

int n;

inline void r(int &s) {
  int c(getchar());
  while (c < 48 || c > 57) c = getchar();
  while (c > 47 && c < 58) s = (s << 1) + (s << 3) + (c ^ 48), c = getchar();
}

inline long long shit(const int &x) {
  return 1ll * x * x;
}

inline int abs1(const int &x) {
  return x ? x : -x;
}

inline long long dis(const Node &x1, const Node &x2) {
  return shit(abs1(x1.x - x2.x)) + shit(abs1(x1.y - x2.y));
}

int main() {
  freopen("dark.in", "r", stdin);
  freopen("dark.out", "w", stdout);
  long long ans, d;
  r(n);
  for (int i = 0; i < n; ++i) {
    r(a[i].x), r(a[i].y);
  }
  ans = dis(a[0], a[1]);
  sort(a, a + n);
  for (int i = 1; clock() < 950 && i < n; ++i) {
    for (int j(0); i + j < n; ++j) {
      d = dis(a[j + i], a[j]);
      if (d < ans) ans = d;
    }
  }
  printf("%.3lf\n", sqrt(ans) / 2);
  return 0;
}