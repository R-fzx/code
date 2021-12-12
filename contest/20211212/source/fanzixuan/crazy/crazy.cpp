#include <bitset>
#include <iostream>

using namespace std;
using LL = long long;

const int kN = 1005, kV = 1e6 + 1;

struct V {
  double x, y;
  bool operator==(const V &o) const { return x == o.x && y == o.y; }
} e[kN][2], a[kN];
int n, m, ans, c[kN], d[kN], _c;

double Cross(V x, V y, V o) { return (x.x - o.x) * (y. y - o.y) - (x.y - o.y) * (y.x - o.x); }
bool _I(V x1, V y1, V x2, V y2) { return Cross(x2, x1, y1) >= 0 && Cross(y2, x1, y1) <= 0 && Cross(y1, x2, y2) >= 0 && Cross(x1, x2, y2) <= 0; }
bool I(V x1, V y1, V x2, V y2) { return _I(x1, y1, x2, y2) || _I(x1, y1, y2, x2) || _I(y1, x1, x2, y2) || _I(y1, x1, y2, x2); }
double D(V x, V y) { return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y); }
V Iv(V x1, V y1, V x2, V y2) {
  if (x2.x == y2.x) {
    return {x2.x, (x1.x - x2.x) / (x1.x - y1.x) * (x1.y - y1.y) + x1.y};
  }
  if (x2.y == y2.y) {
    return {(x1.y - x2.y) / (x1.y - y1.y) * (x1.x - y1.x) + x1.x, x2.y};
  }
  return {((x2.x * y2.y - y2.x * x2.y) / (x2.x - y2.x) * (x1.x - y1.x) - x1.x * y1.y + y1.x * x1.y) / ((y2.y - x2.y) / (x2.x - y2.x) * (x1.x - y1.x) - y1.y + x1.y), ((x2.x * y2.y - y2.x * x2.y) * (y1.y - x1.y) / (y2.y - x2.y) - x1.x * y1.y + y1.x * x1.y) / ((x2.x - y2.x) * (y1.y - x1.y) / (y2.y - x2.y) - x1.x + y1.x)};
}

int main() {
  freopen("crazy.in", "r", stdin);
  freopen("crazy.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> e[i][0].x >> e[i][0].y >> e[i][1].x >> e[i][1].y;
  }
  e[n + 1][0] = {-1, kV}, e[n + 1][1] = {kV, kV}, e[n + 2][0] = {kV, kV}, e[n + 2][1] = {kV, -1}, e[n + 3][0] = {kV, -1}, e[n + 3][1] = {-1, -1}, e[n + 4][0] = {-1, -1}, e[n + 4][1] = {-1, kV};
  for (int i = 1; i <= m; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  n += 4;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (I(e[i][0], e[i][1], e[j][0], e[j][1])) {
        d[i] = d[j];
        break;
      }
    }
    if (!d[i]) d[i] = ++_c;
    // cout << d[i] << " ";
  }
  // cout << endl;
  for (int i = 1; i <= m; ++i) {
    bitset<kN> v = 0;
    for (int j = 1; j <= n; ++j) {
      if (I(a[i], {kV + 1, a[i].y + 1}, e[j][0], e[j][1])) {
        v[d[j]].flip();
      }
    }
    int _d = 0;
    double md;
    for (int j = 1; j <= n; ++j) {
      if (v[d[j]]) {
        double di = D(a[i], Iv(a[i], {kV + 1, a[i].y + 1}, e[j][0], e[j][1]));
        if (!_d || di < md) {
          _d = j, md = di;
        }
      }
    }
    ++c[d[_d]];
    // cout << d[_d] << " ";
  }
  // cout << endl;
  for (int i = 1; i <= _c; ++i) {
    ans = max(ans, c[i]);
    // cout << c[i] << " ";
  }
  // cout << endl;
  cout << ans;
  return 0;
}
/*
x y

x*(y2.y-x2.y)+y*(x2.x-y2.x)=x2.x*y2.y-y2.x*x2.y
x*(y1.y-x1.y)+y*(x1.x-y1.x)=x1.x*y1.y-y1.x*x1.y
x*(y1.y-x1.y)+y*(x2.x-y2.x)*(y1.y-x1.y)/(y2.y-x2.y)=(x2.x*y2.y-y2.x*x2.y)*(y1.y-x1.y)/(y2.y-x2.y)
x=((x2.x*y2.y-y2.x*x2.y)*(x1.x-y1.x)/(x2.x-y2.x)-x1.x*y1.y+y1.x*x1.y)/((y2.y-x2.y)*(x1.x-y1.x)/(x2.x-y2.x)-y1.y+x1.y)
y=((x2.x*y2.y-y2.x*x2.y)*(y1.y-x1.y)/(y2.y-x2.y)-x1.x*y1.y+y1.x*x1.y)/((x2.x-y2.x)*(y1.y-x1.y)/(y2.y-x2.y)-x1.x+y1.x)
*/