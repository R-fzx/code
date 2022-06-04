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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 1e5 + 1;

int n, q, o, l, r, a[2][kN];

void Add(int o, int x) {
  for (; x <= n; ++a[o][x], x += x & -x) {
  }
}
int Sum(int o, int x) {
  int s = 0;
  for (; x; s += a[o][x], x -= x & -x) {
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  while (q--) {
    cin >> o >> l >> r;
    if (o == 1) {
      Add(0, l), Add(1, r);
    } else {
      cout << Sum(0, r) - Sum(1, l - 1) << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}