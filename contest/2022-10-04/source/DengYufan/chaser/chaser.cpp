#include <cmath>
#include <iostream>

using namespace std;

struct Dot {
  double x, y;
};
struct Line {
  double k, b;
};
struct Function {
  double a, b, c;
};
struct V {
  double v, s, t;
  Dot p, q;
  Line l;
} chaser, wind;
int r;
double n, m, s1, s2, s, k, dis;
Dot d1, d2, delta, mid1, mid2, mid3;
Line l1, l2;
Function f1, f2, f3;

double Calc(Dot p, Dot q, bool o) {  // 0:Go 1:Back
  ;
}

int main() {
  freopen("chaser.in", "r", stdin);
  freopen("chaser.out", "w", stdout);
  while (cin >> chaser.p.x) {  // Go correctly way / Go wrong way
    cin >> chaser.p.y >> chaser.q.x >> chaser.q.y >> chaser.v >> wind.p.x >> wind.p.y >> wind.q.x >> wind.q.y >> wind.v >> n >> m;

    wind.s = sqrt(pow(wind.p.x - wind.q.x, 2) + pow(wind.p.y - wind.q.y, 2));
    wind.t = chaser.t = wind.s / wind.v;
    chaser.s = chaser.v * chaser.t;

    wind.l.k = (wind.p.y - wind.q.y) / (wind.p.x - wind.q.y);  // divided by 0
    wind.l.b = wind.p.y - wind.l.k * wind.p.x;
    chaser.l.k = (chaser.p.y - chaser.q.y) / (chaser.p.x - chaser.q.x);  // divided by 0
    chaser.l.b = chaser.p.y - chaser.l.k * chaser.p.x;

    l1.k = -1.0 / chaser.l.k;  // divided by 0
    l1.b = wind.p.y - l1.k * wind.p.x;
    d1.x = (chaser.l.b - l1.b) / (l1.k - chaser.l.k);  // divided by 0
    d1.y = chaser.l.k * d1.x + chaser.l.b;

    l2.k = -1.0 / chaser.l.k;  // divided by 0
    l2.b = wind.q.y - l2.k * wind.q.x;
    d2.x = (chaser.l.b - l2.b) / (l2.k - chaser.l.k);  // divided by 0
    d2.y = chaser.l.k * d2.x + chaser.l.b;

    s1 = sqrt(pow(wind.p.x - d1.x, 2) + pow(wind.p.y - d1.y, 2));
    s2 = sqrt(pow(wind.q.x - d2.x, 2) + pow(wind.q.y - d2.y, 2));
    if (s1 > s2) {
      swap(s1, s2), swap(d1, d2), swap(l1, l2);
    }

    s = sqrt(pow(d1.x - chaser.p.x, 2) + pow(d1.y - chaser.p.y, 2));
    r = s / chaser.s / 2.0;
    delta.x = chaser.q.x - chaser.p.x;
    delta.y = chaser.q.y - chaser.p.y;
    k = chaser.s / sqrt(pow(chaser.p.x - chaser.q.x, 2) + pow(chaser.p.y - chaser.q.y, 2));
    delta.x *= k, delta.y *= k;

    chaser.p.x += delta.x * double(r) * 2.0 - delta.x;
    chaser.p.y += delta.y * double(r) * 2.0 - delta.y;
    chaser.q.x = chaser.p.x + delta.x * 4.0;
    chaser.q.y = chaser.p.y + delta.y * 4.0;
    mid1.x = chaser.p.x + delta.x;
    mid1.y = chaser.p.y + delta.y;
    mid2.x = mid1.x + delta.x;
    mid2.y = mid1.y + delta.y;
    mid3.x = mid2.x + delta.x;
    mid3.y = mid2.y + delta.y;

    dis = min(min(Calc(chaser.p, mid1, 1), Calc(mid1, mid2, 0)), min(Calc(mid2, mid3, 1), Calc(mid3, chaser.q, 0)));
    if (dis < n) {
      cout << "Dangerous\n";
    } else if (dis > m) {
      cout << "Miss\n";
    } else {
      cout << "Perfect\n";
    }
  }
  return 0;
}
