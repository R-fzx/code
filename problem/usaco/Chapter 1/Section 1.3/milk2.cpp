/*
ID: wsfxk.e1
LANG: C++
TASK: milk2
*/
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

const int kN = 1e6 + 1;

int n, l, r, a[kN], ans[2], mi[2] = {INT32_MAX};

int main() {
  freopen("milk2.in", "r", stdin);
  freopen("milk2.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  // cout << mi[0] << " " << mi[1] << endl;
  while (n--) {
    cin >> l >> r;  // (l,r]
    mi[0] = min(mi[0], l + 1), mi[1] = max(mi[1], r);
    ++a[l + 1], --a[r + 1];
  }
  // cout << mi[0] << " " << mi[1] << endl;
  int p = mi[0], o = 0;
  for (int i = mi[0]; i <= mi[1]; ++i) {
    a[i] += a[i - 1];
    if (!a[i] ^ !o) {
      // cout << p << " " << i << endl;
      ans[o] = max(ans[o], i - p), p = i, o ^= 1;
    }
  }
  ans[o] = max(ans[o], mi[1] + 1 - p);
  cout << ans[1] << " " << ans[0] << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}