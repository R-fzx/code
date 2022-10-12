#include <bits/stdc++.h>
#define pdd pair<double, double>
#define x first
#define y second
using namespace std;

struct Line {
  pdd a, b;
  inline void swap() {
    pdd t(a);
    a = b, b = t;
  }
  inline double size() { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }
} p({(pdd){0, 0}, (pdd){1, 81}});
queue<pair<Line, int> > q;
const double eps(1e-5);
const pdd l90({0, 1}), r90({0, -1});
double lx, ly, rx, ry, ans;
inline pdd operator+(pdd a, pdd b) {
  return {a.x + b.x, a.y + b.y};
}
inline pdd operator-(pdd a, pdd b) {  // a起点 b终点
  return {b.x - a.x, b.y - a.y};
}
inline pdd operator*(pdd a, double k) {
  return {a.x * k, a.y * k};
}
inline pdd operator*(pdd a, pdd b) {
  return {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
}
inline Line operator*(Line x, double k) {
  return {x.a, x.a + ((x.a - x.b) * k)};
}
inline Line operator*(Line x, pdd k) {
  return {x.a, x.a + ((x.a - x.b) * k)};
}
inline bool in(Line x, pdd p) {
  double lx(min(x.a.x, x.b.x)), ly(min(x.a.y, x.b.y)), rx(max(x.a.x, x.b.x)),
      ry(max(x.a.y, x.b.y));
  return lx <= p.x && rx >= p.x && ly <= p.y && ry >= p.y;
}
inline bool in(pdd x) {
  return x.x >= lx && x.x <= rx && x.y >= ly && x.y <= ry;
}
inline double cut(Line x) {
  double r(0);
  // cout<<rx<<' '<<x.a.x<<' '<<x.a.y<<','<<x.b.x<<' '<<x.b.y<<'\n';
  bool u(in(x.a)), v(in(x.b));
  if (u && v) {
    return x.size();
  }
  if (v)
    x.swap();
  Line p[4] = {x * ((lx - x.a.x) / abs(x.a.x - x.b.x)),
               x * ((rx - x.a.x) / abs(x.a.x - x.b.x)),
               x * ((ly - x.a.y) / abs(x.a.y - x.b.y)),
               x * ((ry - x.a.y) / abs(x.a.y - x.b.y))};
  for (int i(0); i < 4; i++) {
    if (in(p[i].b) && in(x, p[i].b)) {
      r = max(r, cut(p[i]));
    }
  }
  return r;
}
inline void grow(Line x, int t) {
  x.swap();
  Line l(x * (1.0 / 3.0));
  l.swap();
  double u(cut(l)), v(cut(l * l90)), w(cut(l * r90)), ops(l.size());
  ans += u + v + w;
  // cout<<l.a.x<<' '<<l.a.y<<' '<< l.b.x << ' ' << l.b.y<<' '<<u<< '\n';
  if (u == ops && v == ops && w == ops) {
    ans += (ops * 3) * (500 - t + 1);
    return;
  }
  if (u > eps) {
    q.push({l, t});
  }
  if (v > eps) {
    q.push({l * l90, t});
  }
  if (w > eps) {
    q.push({l * r90, t});
  }
}
inline void work() {
  q.push({p, 0});
  ans += (cut(p));
  while (!q.empty()) {
    auto cur(q.front());
    // cout << cur.second << ' ' << cur.first.a.x << ' ' << cur.first.a.y << ' '
    //     << cur.first.b.x << ' ' << cur.first.b.y << '\n';
    //  getch();
    if (cur.second == 500)
      break;
    q.pop();
    grow(cur.first, cur.second + 1);
  }
  while (!q.empty()) {
    ans += cut(q.front().first);
    q.pop();
  }
}
int main() {
  freopen("Metamorphosis.in", "r", stdin),
      freopen("Metamorphosis.out", "w", stdout);
  cin >> lx >> ly >> rx >> ry;
  work();
  printf("%0.1f", ans);
  return 0;
}
/*
-1
0
1
53
*/