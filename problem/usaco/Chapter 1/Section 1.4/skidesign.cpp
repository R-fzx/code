/*
ID: wsfxk.e1
LANG: C++
TASK: skidesign
*/
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
#include <fstream>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 1001;

int n;
LL ans = INT64_MAX, a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream fin("skidesign.in");
  ofstream fout("skidesign.out");
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    fin >> a[i];
  }
  for (int i = 0; i <= 100; ++i) {
    LL s = 0;
    for_each(a + 1, a + n + 1, [i, &s](int x) { s += (x > i + 17 ? (i + 17 - x) * (i + 17 - x) : 0) + (x < i ? (i - x) * (i - x) : 0); });
    ans = min(ans, s);
  }
  fout << ans << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}