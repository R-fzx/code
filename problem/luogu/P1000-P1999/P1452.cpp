#include <iostream>
#include <random>

using namespace std;
using Pll = pair<int, int>;
random_device rd;
mt19937 rnd(rd());

const int kN = 50001;

int n;
Pll a[kN];
int s;
int D(Pll x, Pll y) { return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second); }

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  for (int _ = 1; _ <= 100; ++_) {
    for (int x = rnd() % n + 1, __ = 1; __ <= 10; ++__) {
      int m[2] = {0, 0};
      for (int i = 1; i <= n; ++i) {
        if (D(a[x], a[i]) > m[0]) m[0] = D(a[x], a[i]), m[1] = i;
      }
      s = max(s, m[0]), x = m[1];
    }
  }
  cout << s;
  return 0;
}