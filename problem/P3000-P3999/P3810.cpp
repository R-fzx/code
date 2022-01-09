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

struct E {
  int a, b, c, &s;
  bool operator<(const E &o) const {
    return a < o.a || a == o.a && (b < o.b || b == o.b && c < o.c);
  }
} a[kN];
int n, k, s[kN], d[kN];

namespace D1 {
  void S(int l, int r) {
    
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].a >> a[i].b >> a[i].c;
    a[i].s = s[i];
  }
  sort(a + 1, a + n + 1);

#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}