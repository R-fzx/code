/*
ID: wsfxk.e1
LANG: C++
TASK: cowtour
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
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
using ULL = unsigned long long;
using Pii = pair<int, int>;

#define FILE_READ
#ifdef FILE_READ
ifstream fin("cowtour.in");
ofstream fout("cowtour.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 151;

int n, c[kN], t;
Pii a[kN];
bool l[kN][kN];
double d[kN][kN], md[kN], pd[kN];

double D(double x, double y) {
  return sqrt(x * x + y * y);
}
void F(int x, int _c) {
  if (c[x]) {
    return;
  }
  c[x] = _c;
  for (int i = 1; i <= n; ++i) {
    if (l[x][i]) {
      F(i, _c);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    fin >> a[i].first >> a[i].second;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char ch;
      fin >> ch;
      l[i][j] = ch == '1', d[i][j] = (l[i][j] || i == j ? D(a[i].first - a[j].first, a[i].second - a[j].second) : 1e18);
    }
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (d[i][j] != 1e18) {
        md[i] = max(md[i], d[i][j]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!c[i]) {
      F(i, ++t);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (c[i] == c[j]) {
        pd[c[i]] = max(pd[c[i]], d[i][j]);
      }
    }
  }
  // for (int i = 1; i <= t; ++i) {
  //   fout << pd[i] << " ";
  // }
  // fout << endl;
  double ans = 1e18;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (c[i] != c[j]) {
        ans = min({ans, max({pd[c[i]], pd[c[j]], md[i] + md[j] + D(a[i].first - a[j].first, a[i].second - a[j].second)})});
      }
    }
  }
  fout << fixed << setprecision(6) << ans << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}