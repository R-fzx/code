/*
ID: wsfxk.e1
LANG: C++
TASK: numtri
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

int n, f[kN], ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream fin("numtri.in");
  ofstream fout("numtri.out");
  fin >> n >> f[1];
  for (int i = 2; i <= n; ++i) {
    for (int j = 1, p = INT32_MIN, x; j <= i; ++j) {
      fin >> x;
      swap(f[j], p), f[j] = max(f[j], p) + x;
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, f[i]);
  }
  fout << ans << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}