#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int h[3], w[3];
LL ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 0; i < 3; ++i) {
    cin >> h[i];
  }
  for (int i = 0; i < 3; ++i) {
    cin >> w[i];
  }
  if (h[0] + h[1] + h[2] != w[0] + w[1] + w[2]) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= h[0]; ++i) {
    for (int j = 1; j <= h[0] - i; ++j) {
      int k = h[0] - i - j;
      if (k >= 1) {
        for (int a = 1; a <= h[1] && a <= w[0] - i; ++a) {
          for (int b = 1; b <= h[1] - a && b <= w[1] - j; ++b) {
            int c = h[1] - a - b;
            if (c >= 1) {
              int x = w[0] - i - a, y = w[1] - j - b, z = w[2] - k - c;
              if (x >= 1 && y >= 1 && z >= 1 && x + y + z == h[2]) {
                ++ans;
              }
            }
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}