#include <iostream>
#include <cmath>
#include <set>

using namespace std;
using Pii = pair<int, int>;

const int kN = 1001;

int n, l[kN], p0 = INT32_MAX;
Pii a[kN], s;
bool v[kN];

int Cross(Pii x, Pii y, Pii z) {
  return (x.first - z.first) * (y.second - z.second) - (x.second - z.second) * (y.first - z.first);
}
double D(Pii x, Pii y) {
  return hypot(x.first - y.first, x.second - y.second);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
    p0 = min(p0, a[i].second);
  }
  s = {0, p0};
  for (int t = 1; t <= n; ++t) {
    int j = 0;
    for (int i = 1; i <= n; ++i) {
      if (!v[i] && (!j || (Cross(a[j], a[i], s) < 0 || Cross(a[j], a[i], s) == 0 && D(a[i], s) < D(a[j], s)))) {
        j = i;
      }
    }
    v[j] = 1, l[t] = j, s = a[j];
  }
  cout << n;
  for (int i = 1; i <= n; ++i) cout << " " << l[i];
  return 0;
}