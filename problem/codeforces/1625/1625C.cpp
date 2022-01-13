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

const int kN = 501;

int n, l, k;
LL f[kN][kN];
Pll a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> l >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].second;
  }
  a[n + 1] = {l, 0};
  
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
... 3 5 8  ...
    1 9 10
*/