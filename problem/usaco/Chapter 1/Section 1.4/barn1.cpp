/*
ID: wsfxk.e1
LANG: C++
TASK: barn1
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

const int kN = 201;

int m, s, c, a[kN], b[kN], ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream fin("barn1.in");
  ofstream fout("barn1.out");
  fin >> m >> s >> c;
  for (int i = 1; i <= c; ++i) {
    fin >> a[i];
  }
  sort(a + 1, a + c + 1);
  for (int i = 1; i < c; ++i) {
    b[i] = a[i + 1] - a[i] - 1;
  }
  sort(b + 1, b + c);
  for (int i = c, j = 1; i > m; --i, ++j) {
    ans += b[j];
  }
  fout << ans + c << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}