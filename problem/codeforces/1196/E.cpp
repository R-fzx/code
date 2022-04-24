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

int q, b, w, d;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> b >> w;
    if (b == w) {
      cout << "YES\n";
      for (int i = 1; i <= b + w; ++i) {
        cout << "1 " << i << endl;
      }
    } else {
      if (b < w) {
        swap(b, w), d = 1;
      } else {
        d = 0;
      }
      // b > w
      if (2 * w >= b - w - 1) {
        cout << "YES\n";
        for (int i = 1; i <= w * 2 + 1; ++i) {
          cout << "2 " << i + d << endl;
        }
        b -= w + 1;
        for (int i = 2, c = 1; b && c <= w; ++c, --b, i += 2) {
          cout << "1 " << i + d << endl;
        }
        for (int i = 2, c = 1; b && c <= w; ++c, --b, i += 2) {
          cout << "3 " << i + d << endl;
        }
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}