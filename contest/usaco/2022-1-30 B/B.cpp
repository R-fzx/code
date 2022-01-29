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
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;
using A = array<int, 4>;

int t, s[2];
A a, b, c;

bool B(A x, A y) {
  s[0] = s[1] = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (x[i] != y[j]) {
        ++s[x[i] > y[j]];
      }
    }
  }
  return s[1] > s[0];
}
bool C() {
  for (int i = 0; i < 10000; ++i) {
    for (int j = 0, k = i; j < 4; ++j) {
      c[j] = k % 10 + 1, k /= 10;
    }
    if (B(a, b) && B(b, c) && B(c, a) || B(a, c) && B(c, b) && B(b, a)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  // freopen("B.in", "r", stdin);
  // freopen("B.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    for (int i = 0; i < 4; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < 4; ++i) {
      cin >> b[i];
    }
    cout << (C() ? "yes" : "no") << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}