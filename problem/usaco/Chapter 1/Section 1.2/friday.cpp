/*
ID: wsfxk.e1
LANG: C++
TASK: friday
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

int n, c[7], y = 1900, m = 1, d = 1, o = 2;

int M() { return m == 2 ? 28 + (!(y % 4) && (y % 100) || !(y % 400)) : 30 + ((m > 7) ^ (m & 1)); }

int main() {
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> n; y < 1900 + n; o = (o + 1) % 7) {
    // cout << y << " " << m << " " << d << " " << o << endl;
    c[o] += d == 13, ++d > M() && (++m > 12 && (++y, m = 1), d = 1);
  }
  for (int i = 0; i < 7; ++i) {
    cout << (i ? " " : "") << c[i];
  }
  cout << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}