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

const int kN = 1e7 + 1;

LL a, b, p[kN], l;

LL S(LL a, LL b) {
  l = 0;
  for (LL i = 1; i * i <= b; ++i) {
    if (b % i == 0) {
      p[++l] = i;
    }
  }
  LL ans = INT64_MAX, j = 1;
  for (LL i = 1; i * i <= a; ++i) {
    if (a % i == 0) {
      for (; j + 1 <= l && p[j + 1] <= i; ++j) {
      }
      if (b / p[j] <= a / i) {
        ans = min(ans, (i + a / i) * 2);
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  cout << min(S(a + b, b), S(a + b, a));
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}