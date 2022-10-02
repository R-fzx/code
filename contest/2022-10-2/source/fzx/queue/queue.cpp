#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 301;

int n;
double s;

int main() {
  RF("queue");
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      double _s = 1;
      for (int k = 0; k < j; ++k) {
        _s *= 1.0 * (k + i - j) / (k + n - j + 1);
      }
      s += _s;
    }
  }
  cout << fixed << setprecision(2) << s;
  return 0;
}
/*
123
111
011
001
-------
132
101
010
001
-------
213
101
011
001
-------
231
100
011
001
-------
312
110
010
001
-------
321
100
010
001
*/