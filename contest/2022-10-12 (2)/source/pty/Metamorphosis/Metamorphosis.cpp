#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;
using Pdd = pair<double, double>;

ifstream fin("Metamorphosis.in");
ofstream fout("Metamorphosis.out");

const int kN = 502;

Pdd l, r;
double ans;

Pdd operator+(Pdd a, Pdd b) { return {a.first + b.first, a.second + b.second}; };
Pdd operator-(Pdd a, Pdd b) { return {a.first - b.first, a.second - b.second}; };
Pdd operator*(Pdd a, double v) { return {a.first * v, a.second * v}; };

Pdd Move(Pdd p) { return {min(max(p.first, l.first), r.first), min(max(p.second, l.second), r.second)}; }
bool In(Pdd p) { return p.first >= l.first && p.first <= r.first && p.second >= l.second && p.second <= r.second; };
Pdd LR(Pdd o, Pdd a) {
  Pdd v = a - o;
  return o + (Pdd){-v.second, v.first};
}
Pdd RR(Pdd o, Pdd a) {
  Pdd v = a - o;
  return o + (Pdd){v.second, -v.first};
}
double D(Pdd a, Pdd b) { return abs(a.first - b.first) + abs(a.second - b.second); };

void C(Pdd a, Pdd b, int l) {
  if (!l) {
    ans += D(Move(a), Move(b));
    return;
  }
  Pdd c = a + (b - a) * (2.0 / 3.0);
  Pdd d = LR(c, b), e = RR(c, b);
  if (In(a) && In(b) && In(d) && In(e)) {
    ans += D(a, b) * (1 + l * 2.0 / 3);
  } else if (In(a) || In(b) || In(d) || In(e)) {
    ans += D(Move(a), Move(c));
    C(c, b, l - 1), C(c, d, l - 1), C(c, e, l - 1);
  }
}

int main() {
  fin >> l.first >> l.second >> r.first >> r.second;
  C({0, 0}, {0, 81}, 500);
  fout << setprecision(1) << fixed << ans;
  return 0;
}