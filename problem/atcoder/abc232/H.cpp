#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using LD = long double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using V = vector<Pll>;

V S(int h, int w, int a, int b) {
  V v;
  if (h == 2) {
    for (int i = 1; i < b; ++i) {
      v.emplace_back(1, i), v.emplace_back(2, i);
    }
    for (int i = b; i <= w; ++i) {
      v.emplace_back(3 - a, i);
    }
    for (int i = w; i >= b; --i) {
      v.emplace_back(a, i);
    }
  } else if (w == 2 || b == 1 || b == 2 && a == h) {
    for (auto &x : S(w, h, b, a)) {
      v.emplace_back(x.second, x.first);
    }
  } else {
    for (int i = 1; i <= h; ++i) {
      v.emplace_back(i, 1);
    }
    for (auto &x : S(h, w - 1, h - a + 1, b - 1)) {
      v.emplace_back(h - x.first + 1, x.second + 1);
    }
  }
  return v;
}
int h, w, a, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> h >> w >> a >> b;
  for (auto &x : S(h, w, a, b)) {
    cout << x.first << " " << x.second << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}