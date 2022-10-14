#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
double n, ans(1e10), k(1.0 / sqrt(2.0));
pair<double, double> wp, _p[200009];
pii p[200009];
struct Node {
  double w;
  pii p;
} e[200009];
inline int read() {
  int r(0);
  char ch(getchar());
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    r = (r << 1) + (r << 3) + ch - '0', ch = getchar();
  return r;
}
inline bool cmp2(pii a, pii b) {
  return a.y == b.y ? a.x < b.x : a.y < b.y;
}
inline bool cmp3(Node a, Node b) {
  return a.w < b.w;
}
inline double sqr(double x) {
  return x * x;
}
inline double dis(pair<double, double> a, pair<double, double> b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
int main() {
  freopen("dark.in", "r", stdin), freopen("dark.out", "w", stdout);
  srand(time(0));
  n = read();
  for (int i(0); i < n; i++) {
    p[i] = {read(), read()}, wp.x += p[i].x / n, wp.y += p[i].y / n;
    _p[i] = {(p[i].x + p[i].y) * k, (p[i].x - p[i].y) * k};
  }
  for (int i(0); i < n; i++) {
    e[i] = (Node){(double)(dis(wp, p[i])), p[i]};
  }
  sort(p, p + (int)n);
  ans = min(dis(p[0], p[1]), ans);
  for (int i(1000); i--;) {
    int a(rand());
    if (a + 100 >= n)
      continue;
    ans = min(ans, dis(p[a], p[a + 1]));
    ans = min(ans, dis(p[a], p[a + (rand() % 100 + 1)]));
  }
  sort(_p, _p + (int)n);
  for (int i(1000); i--;) {
    int a(rand());
    if (a + 100 >= n)
      continue;
    ans = min(ans, dis(_p[a], _p[a + 1]));
    ans = min(ans, dis(_p[a], _p[a + (rand() % 100 + 1)]));
  }
  for (int i(0); i < n; i++) {
    if (clock() > 670) {
      break;
    }
    for (int j(i + 1); j < n; j++) {
      if (_p[j].x - _p[i].x > ans + 1e-3) {
        break;
      }
      ans = min(ans, dis(_p[j], _p[i]));
    }
  }
  sort(e, e + (int)n, cmp3);
  for (int i(0); i < n; i++) {
    if (clock() > 940) {
      break;
    }
    for (int j(i + 1); j < n; j++) {
      if (e[j].w - e[i].w > ans + 1e-3) {
        break;
      }
      ans = min(ans, dis(e[i].p, e[j].p));
    }
  }
  printf("%0.3f\n", ans / 2.0);
  return 0;
}