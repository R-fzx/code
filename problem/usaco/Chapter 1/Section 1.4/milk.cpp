/*
ID: wsfxk.e1
LANG: C++
TASK: milk
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
using Pii = pair<int, int>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 5001;

int n, m;
Pii a[kN];
LL s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream fin("milk.in");
  ofstream fout("milk.out");
  fin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    fin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; n; ++i) {
    s += min(n, a[i].second) * a[i].first, n = max(n - a[i].second, 0);
  }
  fout << s << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}