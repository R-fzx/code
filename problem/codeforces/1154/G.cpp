#include <iostream>

using namespace std;
using LL = long long;

const int kN = 1e7 + 1;

int n, p[kN], ap[2], _p[2];
LL ans = INT64_MAX, s[2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    if (p[x] && x < ans) {
      ans = x, ap[0] = p[x], ap[1] = i;
    }
    p[x] = i;
  }
  for (int g = 1; g < kN; ++g) {
    int t = -1;
    for (int i = g; i < kN; i += g) {
      if (p[i] && t < 1) {
        _p[++t] = p[i], s[t] = i;
      }
    }
    if (t == 1 && s[0] / g * s[1] < ans) {
      ans = s[0] / g * s[1], ap[0] = _p[0], ap[1] = _p[1];
    }
  }
  if (ap[0] > ap[1]) {
    swap(ap[0], ap[1]);
  }
  cout << ap[0] << " " << ap[1];
  return 0;
}